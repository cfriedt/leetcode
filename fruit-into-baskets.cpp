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
#include <numeric>
#include <utility>

using namespace std;

class Solution {

	// https://leetcode.com/problems/fruit-into-baskets/

public:
	int totalFruit(vector<int>& tree) {

		if ( tree.size() <= 2 ) {
			return tree.size();
		}

		const size_t N = tree.size();

		// DP, FTW!
		// ================================
		// i        |   | 0 1 2 3 4 5 6 7 8
		// j        | 0 | 1 2 3 4 5 6 7 8 9
		// tree     |   | 1 0 0 0 1 0 4 0 4
		// type[0]  | - | 1 1 1 1 1 1 4 4 4
		// type[1]  | - | - 0 0 0 0 0 0 0 0
		// last[0]  | - | 0 0 0 0 4 4 6 6 8
		// last[1]  | - | - 1 2 3 3 5 5 7 7
		// count[0] | 0 | 1 1 1 1 2 2 1 1 2
		// count[1] | 0 | 0 1 2 3 3 4 1 2 2
		// most     | 0 | 1 2 3 4 5 6 6 6 6

		vector<vector<int>> type( N + 1, vector<int>({-1,-1}) );
		vector<vector<size_t>> last( N + 1, vector<size_t>({-1,-1}) );
		vector<vector<size_t>> count( N + 1, vector<size_t>({0,0}) );
		vector<size_t> most( N + 1, 0 );

		for( size_t j = 1; j <= N; j++ ) {

			size_t i = j - 1;

			if ( false ) {
			} else if ( -1 == last[ i ][ 0 ] ) {
				type[ i ][ 0 ] = tree[ i ];
				last[ i ][ 0 ] = i;
				count[ i ][ 0 ] = 1;
				if ( i > 0 ) {
					count[ i ][ 1 ] = count[ i - 1 ][ 1 ];
				}
			} else if ( -1 == last[ i ][ 1 ] ) {
				type[ i ][ 1 ] = tree[ i ];
				last[ i ][ 1 ] = i;
				count[ i ][ 1 ] = 1;
				if ( i > 0 ) {
					count[ i ][ 0 ] = count[ i - 1 ][ 0 ];
				}
			} else if ( tree[ i ] == type[ i - 1 ][ 0 ] ) {
				type[ i ][ 0 ] = type[ i - 1 ][ 0 ];
				type[ i ][ 1 ] = type[ i - 1 ][ 1 ];
				last[ i ][ 0 ] = i;
				last[ i ][ 1 ] = last[ i - 1 ][ 1 ];
				count[ i ][ 0 ] = count[ i - 1 ][ 0 ] + 1;
				count[ i ][ 1 ] = count[ i - 1 ][ 1 ];
			} else if ( tree[ i ] == type[ i - 1 ][ 1 ] ) {
				type[ i ][ 1 ] = type[ i - 1 ][ 1 ];
				type[ i ][ 0 ] = type[ i - 1 ][ 0 ];
				last[ i ][ 1 ] = i;
				last[ i ][ 0 ] = last[ i - 1 ][ 0 ];
				count[ i ][ 1 ] = count[ i - 1 ][ 1 ] + 1;
				count[ i ][ 0 ] = count[ i - 1 ][ 0 ];
			} else {
				if ( false ) {
				} else if ( tree[ i ] == type[ i - 1 ][ 0 ] ) {
					type[ i ][ 1 ] = tree[ i ];
					type[ i ][ 0 ] = type[ i - 1 ][ 0 ];
					last[ i ][ 1 ] = i;
					last[ i ][ 0 ] = last[ i - 1 ][ 0 ];
					if ( false ) {
					} else if ( -1 == last[ ] ) {
					}
				} else if ( tree[ i ] == type[ i - 1 ][ 1 ] ){

				}
			}
			size_t current_sum = count[ i ][ 0 ] + count[ i ][ 1 ];
			if ( i > 0 ) {
				most[ i ] = ( current_sum > most[ i - 1 ] ) ? current_sum : most[ i - 1 ];
			} else {
				most[ i ] = 1;
			}
		}

		return most;
	}
};
