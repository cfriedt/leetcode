/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
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

	vector<string> letterCombinations( const string & digits ) {
		vector<string> r;
		if ( "" != digits ) {
			helper( r, "", digits );
		}
		return r;
	}

};
