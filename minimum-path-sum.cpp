/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:

	// https://leetcode.com/problems/minimum-path-sum

	int minPathSum(vector<vector<int>>& grid) {
		// Assumptions
		// - elements in the grid can be signed (i.e. positive & negative)
		// - the grid is large!
		// - not necessarily square
		//
		// Observations
		// - Since we are starting at the top-left and moving to the bottom-right
		//   there are only 2 directions we need to consider: Down & Right.
		// - From each space, there are 2 choices to be made.
		// - However, for # rows M and # cols N we must choose Right exactly N-1
		//   times, and Down exactly M-1 times. There are M + N - 1 spaces to
		//   travers, so the question reduces to "how many ways are there to
		//   choose Down M - 1 times.
		// - In total, there are C( M + N - 2, M - 1 ) possible paths.
		// - So the complexity is already O(N!).
		// - However, we are quick to realize that the cost travelling to a
		//   particular square is minimum of the cost of getting to the square to
		//   the left of it and the cost of getting to the square above it,
		//   PLUS the cost of the square itself.
		// - If we are iterating from left to right, and then top to bottom in
		//   this array, then it is obvious that the cost of getting to
		//   each square is recursively defined by those before it.
		// - That is the sort of problem that lends itself very well to dynamic
		//   programming.
		//
		// Analysis
		// - Say the cost of getting to each square can be computed in linear
		//   time assuming that we store and reuse the results of previous
		//   calculations. Time complexity is O( MN ) - i.e. linear in the
		//   number of squares
		// - We visit and store the result sof each node once. Space complexity
		//   is O( MN ) - i.e. linear in the number of squares.
		//

		const size_t M = grid.size();
		const size_t N = (0 == M) ? 0 : grid[ 0 ].size();

		for( size_t row = 0; row < M; row++ ) {
			for( size_t col = 0; col < N; col++ ) {
				int cost_from_above;
				int cost_from_left;
				if ( 0 == row ) {
					cost_from_above = 0;
				} else {
					cost_from_above = grid[ row - 1 ][ col ];
				}
				if ( 0 == col ) {
					cost_from_left = 0;
				} else {
					cost_from_left = grid[ row ][ col - 1 ];
				}
				if ( false ) {
				} else if ( 0 == row || 0 == col ) {
					grid[ row ][ col ] += cost_from_left + cost_from_above;
				} else {
					grid[ row ][ col ] += min( cost_from_left, cost_from_above );
				}
			}
		}

		// Example
		// grid:   cost:
		// [1,3,1]      [1,4,5]
		// [1,5,1]      [2,7,6]
		// [4,2,1]      [6,8,7]
		//
		//            cost  cost
		// row   col  above left grid[r][c] cost[r][c]
		// 0     0    0     0    1          1
		// 0     1    0     1    3          4
		// 0     2    0     4    1          5
		// 1     0    1     0    1          2
		// 1     1    4     2    5          7
		// 1     2    5     7    1          6
		// 2     0    2     0    4          6
		// 2     1    7     6    2          8
		// 2     2    6     8    1          7

		return grid[ M - 1 ][ N - 1 ];
	}
};
