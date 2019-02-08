/*
 * MIT License
 *
 * Copyright (c) 2018 Christopher Friedt
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <utility>

using namespace std;

class Ukkonen {

public:

	Ukkonen() : Ukkonen( "" ) {}
	Ukkonen( const string & text ) : text( text ) {
		buildSuffixTree();
	}

	SuffixTreeNode *convertToSuffixTreeNode() {
		if ( nullptr == root ) {
			return nullptr;
		}
		SuffixTreeNode *parent = new SuffixTreeNode();
		convertToSuffixTreeNodeHelper( parent, nullptr, root );
		return parent;
	}

	string to_string() {
		string out;
		to_string_helper( out, root );
		return out;
	}

protected:

	// constexpr size_t m = 255; // all of UTF-8 minus '\0'

	using OrderedPair = pair<size_t,size_t>;

	struct State {
		size_t leaf_number;
		unordered_map<char,shared_ptr<State>> transition;
		// using a pair of indices into string text to encode labels
		unordered_map<char,OrderedPair> transition_label;
	};

	using ReferencePairString = pair<shared_ptr<State>,string>;
	using ReferencePair = pair<shared_ptr<State>,OrderedPair>;
	using StateAndLeftLink = pair<shared_ptr<State>,size_t>;
	using BoolStatePair = pair<bool,shared_ptr<State>>;

	const string & text;

	shared_ptr<State> root;

	unordered_map<shared_ptr<State>,shared_ptr<State>> suffix_links;

	void buildSuffixTree() {

		shared_ptr<State> s;
		size_t k;
		size_t i;

		root = make_shared<State>();

		for(
			s = root,
				i = size_t(-1),
				k = 0
				;
			i + 1 < text.size()
				;

		) {
			i++;
			update( s, k, i );
			canonize( s, k, i );
		}
	}

	// (s,(k,i-1)) is the canonical reference pair for the active point
	void update( shared_ptr<State> & s, size_t & k, size_t i ) {

		shared_ptr<State> oldr;
		char ti;
		BoolStatePair end_point_r;
		bool end_point;
		shared_ptr<State> r;

		for (
			oldr = root,
				ti = text[ i ],
				end_point_r = test_and_split( s, k, i - 1, ti ),
				end_point = end_point_r.first,
				r = end_point_r.second
				;
			! end_point
				;
			end_point_r = test_and_split( s, k, i - 1, ti ),
				end_point = end_point_r.first,
				r = end_point_r.second
		) {
			shared_ptr<State> r_prime;

			r_prime = make_shared<State>();

			r->transition[ ti ] = r_prime;
			r->transition_label[ ti ] = OrderedPair( i, size_t(-1) );

			if ( oldr != root ) {
				suffix_links[ oldr ] = r;
			}

			oldr = r;

			canonize( suffix_links[ s ], k, i - 1 );
		}

		if ( oldr != root ) {
			suffix_links[ oldr ] = s;
		}

		return; // (s,k)
	}

	BoolStatePair test_and_split( shared_ptr<State> s, size_t k, size_t p, const char t ) {

		char tk;
		size_t k_prime;
		size_t p_prime;
		shared_ptr<State> s_prime;

		bool found_tk_transition;

		tk = text[ k ];
		found_tk_transition = findTkTransition( *s, tk, k_prime, p_prime, s_prime );

		if ( found_tk_transition && k <= p ) {

			if( t == text[ k_prime + p - k + 1 ] ) {

				return BoolStatePair( true, s );

			} else {

				// replace the tk-transition above by transitions

				shared_ptr<State> r = make_shared<State>();

				s->transition[ tk ] = r;
				s->transition_label[ tk ] = OrderedPair( k_prime, k_prime + p - k );

				r->transition[ tk ] = s_prime;
				r->transition_label[ tk ] = OrderedPair( k_prime + p - k + 1, p_prime );

				return BoolStatePair( false, r );
			}

		} else {

			bool tk_transition_found;

			tk = text[ k ];
			tk_transition_found = findTkTransition( *s, tk, k_prime, p_prime, s_prime );

			if ( ! tk_transition_found ) {

				return BoolStatePair( false, s );

			} else {

				return BoolStatePair( true, s );
			}
		}
	}

	void canonize( shared_ptr<State> &s, size_t & k, size_t p ) {
		if ( p < k ) {

			return; // (s,k)

		} else {

			char tk;
			size_t k_prime;
			size_t p_prime;
			shared_ptr<State> s_prime;

			for(
				tk = text[ k ],
					findTkTransition( *s, tk, k_prime, p_prime, s_prime )
					;
				true
					&& k <= p
					&& p_prime - k_prime <= p - k
					;
				tk = text[ k ],
					findTkTransition( *s, tk, k_prime, p_prime, s_prime )
			) {
				k = k + p_prime - k_prime + 1;
				s = s_prime;
			}

			return; // (s,k)
		}
	}

	string orderedPairToString( const OrderedPair & op ) {
		return text.substr( op.first, op.second + 1 );
	}

	static bool findTkTransition(
			// input
			const State & s, const char tk,
			// output
			size_t & k_prime,
			size_t & p_prime,
			shared_ptr<State> & s_prime
	) {
		bool r;
		auto it = s.transition.find( tk );

		if ( s.transition.end() == it ) {

			k_prime = size_t( -1 );
			p_prime = size_t( -1 );
			s_prime = nullptr;
			r = false;

		} else {

			const OrderedPair & label = s.transition_label.find( tk )->second;
			k_prime = label.first;
			p_prime = label.second;
			s_prime = it->second;
			r = true;

		}

		return r;
	}


	void convertToSuffixTreeNodeHelper( SuffixTreeNode * & suffix_tree_node, const shared_ptr<State> & prev_state, const shared_ptr<State> & state ) {
		if ( nullptr == suffix_tree_node && nullptr == prev_state ) {
			suffix_tree_node = new SuffixTreeNode();

			for( auto & kv: state->transition ) {
				convertToSuffixTreeNodeHelper( suffix_tree_node, state, kv.second );
			}

			return;
		}

		if ( state->transition.empty() ) {
			suffix_tree_node->leaf_number = state->leaf_number;
			return;
		}

		for( auto & kv: state->transition ) {

			char key = kv.first;

			shared_ptr<State> to_state = state->transition[ key ];
			OrderedPair label_indices = state->transition_label[ key ];
			string label = orderedPairToString( label_indices );

			suffix_tree_node->child[ label ] = new SuffixTreeNode();

			convertToSuffixTreeNodeHelper( suffix_tree_node, state, to_state );
		}
	}


	void to_string_helper( string & out, shared_ptr<State> & node ) {
		if ( nullptr == node ) {
			return;
		}

		out += "{";
		if ( node->transition.empty() ) {
			out += std::to_string( node->leaf_number );
		} else {
			size_t i = 0;
			size_t n = node->transition.size();
			for( auto & kv: node->transition ) {
				string label = orderedPairToString( node->transition_label[ kv.first ] );
				to_string_helper( out, kv.second );
				if ( i + 1 < n ) {
					out += ",";
				}
				i++;
			}
		}
		out += "}";
	}
};


class Solution {
public:
	SuffixTreeNode *buildSuffixTree( const string & text ) {
		Ukkonen ukk( text );
		return ukk.convertToSuffixTreeNode();
	}
};

ostream & operator<<( ostream & os, const Ukkonen & x ) {
	(void) x;
	return os;
}
