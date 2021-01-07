/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <vector>

using namespace std;

class Solution {
public:

	// https://leetcode.com/problems/diagonal-traverse/

	vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
		//[
		// [ 1, 2, 3 ],
		// [ 4, 5, 6 ],
		// [ 7, 8, 9 ]
		//]
		// => [1,2,4,7,5,3,6,8,9]

		// Let M = the number of rows and N = the number of columns
		//
		// Address individual cells as matrix[m][n], 0 >= n,m < M
		//
		// The special case is where M == N, and the matrix is square.

		const size_t M = matrix.size();
		const size_t N = ( M >= 1 ) ? matrix[ 0 ].size() : 0;

		// What about when N != M ?
		//
		//[
		// [ 1, 2, 3 ],
		// [ 4, 5, 6 ],
		//]
		// => [1,2,4,5,3,6]

		// r is always M*N elements long

		vector<int> r( M*N, 0 );

		typedef enum {
			UP,
			DOWN,
		} dir_t;

		size_t m = 0;
		size_t n = 0;
		dir_t dir = UP;

		for( size_t i = 0; i < r.size(); i++ ) {

			r[ i ] = matrix[ m ][ n ];

			if ( false ) {
			} else if ( UP == dir ) {

				// boundary conditions going up / right

				if ( 0 == m ) {

					// we've hit the top of the matrix

					// reverse direction
					dir = DOWN;

					if ( n < N - 1 ) {
						// we've hit the top of the matrix, but not the corner
						// move to the next column but stay on the same row
						n++;
					} else {
						// we've hit the top-right corner of the matrix
						// move one row down but stay in the same column
						m++;
					}
				} else {

					// we have not hit the top of the matrix

					if ( n < N - 1 ) {
						// regular update in up direction - no boundary conditions
						m--;
						n++;
					} else {
						// we've hit the right wall of the matrix
						// move one row down but stay in the same column
						// reverse direction
						m++;
						dir = DOWN;
					}
				}
			} else if ( DOWN == dir ) {

				// boundary conditions going down / left

				if ( 0 == n ) {

					// we've hit the left of the matrix

					// reverse direction
					dir = UP;

					if ( m < M - 1 ) {
						// we've hit the left of the matrix, but not the corner
						// move to the next row but stay on the same column
						m++;
					} else {
						// we've hit the bottom-left corner of the matrix
						// move one column right but stay in the same row
						n++;
					}
				} else {

					// we have not hit the left wall of the matrix

					if ( m < M - 1 ) {
						// regular update in down direction - no boundary conditions
						m++;
						n--;
					} else {
						// we've hit the bottom wall of the matrix
						// move one column right but stay in the same row
						// reverse direction
						n++;
						dir = UP;
					}
				}
			}
		}

		return r;
	}
};
