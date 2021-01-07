/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <algorithm>
#include <array>
#include <string>

using namespace std;

// https://leetcode.com/problems/implement-trie-prefix-tree/

class Trie {
public:

	// Note, a Trie is not a binary tree unless the alphabet size is 2.
	//
	// Generally, each node can have up to N subnodes, where
	// N is consistent among all nodes in a given Trie.
	//
	// The smaller the alphabet size is, the better in terms of
	// space utilization.
	//
	// Assumptions
	// -----------
	// * only dealing with lower-case ascii (alphabet size is 26)

	using idx_t = char;

	static constexpr size_t alphabet_size = 26;
	static constexpr idx_t alphabet_base = 'a';

	// * only need to know if an element exists or not, rather than
	//   the number of instances seen.

	using count_t = bool;

	struct TrieNode {
		count_t count;
		array<TrieNode *,alphabet_size> child;
		TrieNode() : count( 0 ) {
			fill( child.begin(), child.end(), nullptr );
		}
	};

	TrieNode root;

    Trie() {
    }

    void cleanup( TrieNode *n ) {
    	if ( nullptr == n ) {
    		return;
    	}
    	for( auto & it: n->child ) {
    		cleanup( it );
    	}
    	if ( & root != n ) {
    		delete n;
    	}
    }

	~Trie() {
		cleanup( & root );
	}

    void insert(string word) {

    	if ( "" == word ) {
    		return;
    	}

    	TrieNode *it = & root;

    	for( auto c: word ) {

    		c -= alphabet_base;

    		if ( nullptr == it->child[ c ] ) {
    			it->child[ c ] = new TrieNode();
    		}

    		it = it->child[ c ];
    	}

    	// indicate the presence of the inserted word
    	it->count += 1;
    }

    bool search(string word) {
    	if ( "" == word ) {
    		return true;
    	}

    	TrieNode *it = & root;

    	for( auto c: word ) {

    		c -= alphabet_base;

    		if ( nullptr == it->child[ c ] ) {
    			return false;
    		}

    		it = it->child[ c ];
    	}

    	return 0 != it->count;
    }

    bool startsWith(string prefix) {
    	if ( "" == prefix ) {
    		return true;
    	}

    	TrieNode *it = & root;

    	for( auto c: prefix ) {

    		c -= alphabet_base;

    		if ( nullptr == it->child[ c ] ) {
    			return false;
    		}

    		it = it->child[ c ];
    	}

    	return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
