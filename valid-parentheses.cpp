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
#include <vector>

using namespace std;

class Solution {
public:

	// https://leetcode.com/problems/valid-parentheses/

	static inline bool is_opening( char c ) {
		return '(' == c || '{' == c || '[' == c;
	}

	static inline bool matches( char opening, char closing ) {
		return
			false
			|| ( opening == '(' && closing == ')' )
			|| ( opening == '{' && closing == '}' )
			|| ( opening == '[' && closing == ']' )
			;
	}

	bool isValid(string s) {

		// This is an easy question which I probably should have skipped.
		//
		// Using a stack to balance tags / parentheses, whatever, not on tonight's news at 6.
		//
		// Analysis:
		//
		// time: O( N )
		// space: O( N )

		vector<char> stack;

		for( auto & c: s ) {
			if ( is_opening( c ) ) {
				stack.push_back( c );
			} else {
				if ( stack.empty() || ! matches( stack.back(), c ) ) {
					return false;
				}
				stack.pop_back();
			}
		}

		return stack.empty();
	}
};
