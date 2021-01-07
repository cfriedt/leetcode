/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

// https://leetcode.com/problems/find-and-replace-pattern/

using namespace std;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {

	vector<string> r;
	unordered_set<string> cache;

	for( auto word: words ) {

		if ( word.size() != pattern.size() ) {
			throw invalid_argument( word + " and " + pattern + " are not the same length" );
		}

		if ( cache.end() != cache.find( word ) ) {
			r.push_back( word );
			continue;
		}

		if ( matches( word, pattern ) ) {
			cache.insert( word );
			r.push_back( word );
		}
	}

	return r;
    }

protected:
	bool matches( const string & word, const string & pattern ) {

		unordered_map<char,char> p;
		unordered_map<char,char> q;

		// cout << "checking word '" << word << "' against pattern '" << pattern << "'" << endl;

		for( size_t i = 0; i < word.size(); i++ ) {

			auto & a = word[ i ];
			auto & b = pattern[ i ];

			// cout << "comparing " << a << " and " << b << endl;

			auto it = p.find( a );
			if ( p.end() == it ) {
				auto it2 = q.find( b );
				if ( q.end() == it2 ) {
					// cout << "adding " << a << " -> " << b << endl;
					p[ a ] = b;
					q[ b ] = a;
				} else {
					// cout << it2->first  << " -> " << b << " already!!! returning false.." << endl;
					return false;
				}
			} else {
				if ( it->second != b ) {
					// cout << a << " -> " << it->second << " not " << b <<  "!!! returning false.." << endl;
					return false;
				}
			}
		}

		// cout << "returning true" << endl;

		return true;
	}
};
