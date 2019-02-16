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

using namespace std;

class Solution {
public:

	// https://leetcode.com/problems/valid-palindrome-ii

	bool validPalindrome(string s) {

		// Assumptions
		// -----------
		// - "" and "x" are palindromes of course ;-)
		//
		// Observations
		// ------------
		// - brute force is O( 3N^2 ) time and O( N ) space
		// - can do better
		// - checking palindroms is easy in O( N ) with 2 ptrs / ints
		// - however when we detect a mismatch there are t options:
		//   -> remove the char on the left or the char on the right
		// - would be best to reuse the work that we have already done
		//
		// Analysis
		// --------
		// O(N) (because the recursion is only performed once, and continues
		// from the branching point, so it's technically O( 2N )
		//
		// O(N) space (we copy strings).
		//
		// reursive impl for brevity.

		return isPal( s );
	}

protected:
	bool isPal( string s, bool allow_erase = true ) {
		for( size_t L = 0, R = s.size() - 1; L < R; L++, R-- ) {
			if ( s[ L ] == s[ R ] ) continue;
			if ( ! allow_erase ) return false;
			s = s.substr( L, R - L + 1 );
			string s2 = s;
			s = s.erase( 0, 1 );
			s2 = s2.erase( s2.size() - 1, 1 );
			return isPal( s, false ) || isPal( s2, false );
		}
		return true;
	}
};
