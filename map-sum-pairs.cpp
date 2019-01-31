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

// https://leetcode.com/problems/map-sum-pairs/

#include <array>
#include <unordered_map>
#include <memory>

using namespace std;

class MapSum {
public:

	struct trie_node {
		int val;
		array<shared_ptr<trie_node>,26> child;
		trie_node() : trie_node( int( 0 ) ) {}
		trie_node( int val ) : val( val ) {}
	};
	shared_ptr<trie_node> root;

    /** Initialize your data structure here. */
    MapSum() {
    	root = make_shared<trie_node>();
    }

    void insert(string key, int val) {
    	auto node = root;
    	for( size_t i = 0; i < key.length(); i++ ) {
    		size_t c = size_t( key[ i ] ) - size_t( 'a' );
    		if ( i == key.length() - 1 ) {
    			if ( ! node->child[ c ] ) {
    				node->child[ c ] = make_shared<trie_node>( val );
    			} else {
    				node->child[ c ]->val = val;
    			}
    			break;
    		}
    		if ( ! node->child[ c ] ) {
        		node->child[ c ] = make_shared<trie_node>();
    		}
    		node = node->child[ c ];
    	}
    }

    static int sum_helper( shared_ptr<trie_node> node  ) {
    	int r = node->val;
    	for( auto c: node->child ) {
    		if ( c ) {
    			r += sum_helper( c );
    		}
    	}
    	return r;
    }
    int sum(string prefix) {
    	auto node = root;
    	for( auto ch: prefix ) {
    		size_t c = size_t( ch ) - size_t( 'a' );
    		auto next = node->child[ c ];
    		if ( ! next ) {
    			return 0;
    		}
    		node = next;
    	}
    	return sum_helper( node );
    }
};
