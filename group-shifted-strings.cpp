/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// https://leetcode.com/problems/group-shifted-strings/

class Solution {
public:

	vector<vector<string>> groupStrings(vector<string>& strings) {
		vector<vector<string>> r;

		unordered_map<string,vector<string>> hmap;

		vector<string> length1s;

        if ( strings.empty() ) {
            return r;
        }

		// O( N )
		for( auto & s: strings ) {

			if ( 1 == s.size() ) {
				length1s.push_back( s );
				continue;
			}

			string key;
			for( size_t i = 1; i < s.size(); i++ ) {

				key.push_back( s[ i ] - s[ i - 1 ] );
				if ( int8_t(key.back()) < 0 ) {
					key.back() += 26;
				}
				key.back() += 'a';
			}
			hmap[ key ].push_back( s );
		}

		// O( N )
		for( auto kv: hmap ) {
			r.push_back( kv.second );
		}

		sort(
			r.begin(), r.end(),
			[] (const auto& lhs, const auto& rhs) {
			    return lhs.size() > rhs.size();
			}
		);

		// O(log(N))
		if ( length1s.size() > 0 ) {
			r.push_back( length1s );
		}

		return r;
	}
};
