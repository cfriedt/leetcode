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

#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:

	// https://leetcode.com/problems/longest-common-prefix/

	string longestCommonPrefix( vector<string>& strs) {

		if ( 0 == strs.size() ) {
			return "";
		}
		size_t i;
		for( i = 0; ; i++ ) {
			unordered_set<char> c;

			for( size_t j = 0; j < strs.size(); j++ ) {
				if ( i >= strs[ j ].length() ) {
					c.insert( char( -1 ) );
					break;
				}
				c.insert( strs[ j ][ i ] );
				if ( c.size() > 1 ) {
					break;
				}
			}

			if ( c.size() > 1 || c.end() != c.find( -1 ) ) {
				break;
			}
		}

		return strs[ 0 ].substr( 0, i );
	}

};
