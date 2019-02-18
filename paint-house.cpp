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
#include <vector>

using namespace std;

class Solution {
public:

	// https://leetcode.com/problems/paint-house/

	int minCost(vector<vector<int>>& costs) {

		// The most important thing to understand here is the
		// recurrance:
		//
		// When you *choose* to paint the final house, i, a certain colour,
		// j, then costs[ i ][ j ] inherits the additional cost of the *minimum*
		// of costs[ i - 1 ][ (j + 1) % 3 ] and costs[ i - 1 ][ (j + 2) % 3 ].
		//
		// That recurrance has to be calculated from 0 to i - 1 before i is
		// calculated.
		//
		// You then have to *choose* the minimum of the costs that have percolated
		// up to house i.
		//
		// That was not at all clear to my when I tried this question.
		//
		// My solution was adapted from some Java code I saw online.
		//
		// O( N ) time and O( 1 ) space.

		const int N = costs.size();

		if ( 0 == N ) {
			return 0;
		}

		for( int i = 1; i < N; i++ ) {
			costs[ i ][ 0 ] += min( costs[ i - 1 ][ 1 ], costs[ i - 1 ][ 2 ] );
			costs[ i ][ 1 ] += min( costs[ i - 1 ][ 0 ], costs[ i - 1 ][ 2 ] );
			costs[ i ][ 2 ] += min( costs[ i - 1 ][ 0 ], costs[ i - 1 ][ 1 ] );
		}

		return min( costs[ N - 1 ][ 0 ], min( costs[ N - 1 ][ 1 ], costs[ N - 1 ][ 2 ] ) );
	}
};
