/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// https://leetcode.com/problems/unique-word-abbreviation/

class ValidWordAbbr {
public:
	explicit ValidWordAbbr(vector<string> dictionary) {
    	for( auto & word: dictionary ) {
    		string abbrv = abbreviate( word );
    		original.insert(word);
    		abbreviated[ abbrv ]++;
    	}
    }

    bool isUnique(string word) {
    	string abbrv = abbreviate( word );
    	size_t oc = original.count( word );
    	size_t ac = (abbreviated.end() == abbreviated.find( abbrv )) ? 0 : abbreviated[ abbrv ];
    	return 0 == ac || ( 1 == oc && 1 == ac );
    }

protected:
    unordered_map<string,size_t> abbreviated;
    unordered_set<string> original;

    string abbreviate( const string & word ) {
		string abbrv = word[ 0 ] + to_string( word.size() - 2 ) + word[ word.size() - 1 ];
		return abbrv;
    }
};
