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
				if ( key.back() < 0 ) {
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
