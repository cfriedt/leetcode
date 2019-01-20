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

#include <vector>

using namespace std;

class Solution {
public:

	// https://leetcode.com/problems/generate-parentheses/

	vector<string> generateParenthesis(int n) {

		//
		// The recursive approach for generating strings seems sound.
		//
		// The analysis for this one is a bit tricky, and I would never be able
		// to pull this out of thin air in an interview.
		//
		// Also, I generally find it much more legible to read this code when it
		// is using a helper function, rather than just using the one gP() function.

		vector<string> result;
		helper( result, "", n, n );
		return result;
	}

protected:
	static void helper( vector<string> & result, string in_progress, int L, int R ) {
		if ( 0 == L && 0 == R ) {
			result.push_back( in_progress );
			return;
		}

		if ( 0 != L ) {
			helper( result, in_progress + "(", L - 1, R );
		}

		if ( 0 != R && R > L ) {
			helper( result, in_progress + ")", L, R - 1);
		}
	}
};
