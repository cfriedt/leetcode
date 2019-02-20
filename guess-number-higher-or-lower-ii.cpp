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

class Solution {
public:

	// https://leetcode.com/problems/guess-number-higher-or-lower-ii

	int getMoneyAmount(int n) {

		// Assumptions
		// - idea is not to guess as quickly as possible, but as cheaply as
		//   possible!
		//
		// - this does not correspond 1:1 with binary search
		//
		// e.g.
		//
		// Say N = 4
		// L   R    M   sum
		// 1   4    1   0
		// 2   4    3   1
		// 4   4    -   4
		//
		// is cheaper than a binary search, which would be
		// 1   4    2   0
		// 3   4    3   2
		// 4   4    -   5
		//
		// N   cost   choices
		// 1   0      1
		// 2   1      1,2
		// 3   3      1,2,3
		// 4   4      1,3,4
		// 5   6      2,4,5
		// 6   8      3,5,6
		// ...
		// 10  16
		//
		// [ 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 ]
		//
		// Say N = 5
		// 1 + 2 + 3 = 6
		// 1 + 3
		// 3   4    3   2
		// 4   4    -   5

		size_t sum = 0;

		if ( 1 == n ) {
			return 0;
		}

		int L, R;
		for( L = 1, R = n; L <= R; ) {

			int M;

			if ( L == R ) {
				return int( sum );
			}

			if ( 1 == (L % 2 ) ) {
				M = L;
			} else {
				if ( L > INT_MAX / 2 || R > INT_MAX / 2 ) {
					M = L/2 + R/2;
				} else {
					M = ( L + R ) / 2;
				}
			}

			if ( n == M ) {
				return int( sum );
			}

			L = M + 1;

			sum += M;
		}

		return -1;
	}
};
