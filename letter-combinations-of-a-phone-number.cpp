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

#include <array>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:

	// https://leetcode.com/problems/letter-combinations-of-a-phone-number

	const array<string,10> lut{{
		"",
		"",
		"abc",
		"def",
		"ghi",
		"jkl",
		"mno",
		"pqrs",
		"tuv",
		"wxyz",
	}};


	void helper( vector<string> & results, string prefix, string digits ) {
		if ( "" == digits ) {
			results.push_back( prefix );
			return;
		}
		size_t idx = digits[ 0 ] - '0';
		string next_digits = digits.substr( 1 );
		for( auto c: lut[ idx ] ) {
			string next_prefix = prefix + string(1,c);
			helper( results, next_prefix, next_digits );
		}
	}

	vector<string> letterCombinations( string digits ) {
		vector<string> r;
		if ( "" != digits ) {
			helper( r, "", digits );
		}
		return r;
	}

};
