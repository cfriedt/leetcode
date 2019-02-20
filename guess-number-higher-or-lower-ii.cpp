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

#include <climits>

using namespace std;

int guess( int num );

class Solution {
public:

	// https://leetcode.com/problems/guess-number-higher-or-lower-ii

	int getMoneyAmount(int n) {

		// Assumptions
		// - the idea is to guess the number as fast as possible
		// - assume n is large
		// - assume range is inclusive [1,n]
		// - if secret number is not in [1,n], return -1
		//
		// Observations
		// - numbers 1..n are already sorted :-)
		// - Brute force: O( N ) time, O( 1 ) space
		// - Binary Search: O( logN ) time, O( 1 ) space
		// - Want to identify the corner case that n < 1
		// - Want to identify the corner case that the secret number is < 1
		// - Want to identify the corner case that n is INT_MAX
		//
		// Clearly, a binary search is still better than linear search
		// because the linear search is a superset of the binary search.

		size_t sum = 0;

		int L, R;
		for( L = 1, R = n; L <= R; ) {

			int M;

			if ( L == INT_MAX && R == INT_MAX && 0 == guess( INT_MAX ) ) {
				return int( sum );
			}

			if ( L > INT_MAX / 2 || R > INT_MAX / 2 ) {
				M = L/2 + R/2;
			} else {
				M = ( L + R ) / 2;
			}

			int r = guess( M );

			if ( 0 == r ) {

				return int( sum );

			} else if ( -1 == r ) {

				if ( 1 == M ) {
					break;
				}

				R = M - 1;

			} else if ( +1 == r ) {

				if ( n == M ) {
					break;
				}

				L = M + 1;
			}

			sum += M;
		}

		return -1;
	}
};
