/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <vector>

using namespace std;

class Solution {

public:

	// https://leetcode.com/problems/unique-paths-ii/

	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

		// Assumptions
		// - all directions allowed (i later reread the question and saw that)
		//   my assumption was invalid. Oh well, I have a generalized answer
		// - goal is not to find optimal paths, but all paths (see above)
		// - no irregular vectors in argument
		// - N rows, M columns
		// - cell contents are either 0 or 1
		//
		// Observations
		// - kind of like a graph and adjacency matrix
		// - not a DAG - has cycles (actually, it is a DAG now, see above)
		// - depth first search / recursion likely a good solution
		// - However, if there are no obstacles, it reduces to nCk
		// - If there are obstacles on the start or finish spaces, there
		//   are zero paths.
		//
		// Analysis
		// - brute force would likely be in the order of O(N^4) or something
		//   I won't even bother.
		// - Using DFS, we have O( |N| + |E| ), where N are the number of
		//   spaces on the graph, and E are the number of edges (I guess these
		//   are a vector and a matrix).
		// - Will need to detect cycles, so keep a collection of visited nodes
		//   for each path (max size is M)
		// - Will need to keep a set of unique paths - size P. They will all
		//   have a length M, since we are limited to Down / Right.
		// - It will take O( N ) time to build the graph, where N is the number
		//   of nodes.
		//
		// Further DFS Analysis
		//
		// - The upper bound on the number of paths that would need to be
		//   stored would be when there are no obstacles,
		//   so up to C( M + N - 2, M - 1 ) paths.
		// - That can be a lot, so storage of those paths would be an issue
		//   at larger sizes.
		// - For a 10x10 grid, that's "only" 48,620 paths to store.
		// - For a 20x20 grid, that quickly blows up to 35 billion!!!
		// - For the purpose of this problem, we likely don't need to remember
		//   the individual paths so much as just count how many there are, so
		//   DFS is already likely overkill here.
		// - There will be a maximum of M * N nodes contributing to the time
		//   complexity making it at least O( N^2 ). Bad but better than the
		//   brute force method (so far).
		// - If the only two directions allowed are Down and Right, then
		//   the upper bound on the number of edgest is expressable as
		//   M*N - N - M.
		// - Therefore, the total time complexity of this approach is something
		//   on the order of O( 2MN - M - N ), so still approximately O( N^2 ).
		// - For a DFS
		//   maximum
		//
		// OK, throw DFS into the garbage.
		//
		// The best we're likely going to see is linear on the number of spaces
		// in the grid, or more precisely, O( MN ). We can only visit each node
		// once.
		//
		// I had to look at the solution to get the algorithm, so here goes.
		//
		// The trick is, that it is only possible to get to a given cell
		// from the cell above it or the cell to the left of it.
		//
		// We can keep track of the number of ways to get to a cell by keeping a
		// record in all non-obstacle cells.
		//
		// Obstacle cells should be set to zero when we encounter them since there
		// is no way that any path that leads to them can contribute to the total
		// number of paths.



		size_t M = obstacleGrid.size();
		size_t N = ( 0 == M ) ? 0 : obstacleGrid[0].size();

		if ( 0 == N || 0 == M ) {
			return 1;
		}

		for( size_t row = 0; row < M; row++ ) {
			for( size_t col = 0; col < N; col++ ) {
				if ( 0 == row && 0 == col ) {
					if ( 1 == obstacleGrid[row][col] ) {
						return 0;
					}
					obstacleGrid[row][col] = 1;
					continue;
				}
				if ( 1 == obstacleGrid[row][col] ) {
					obstacleGrid[row][col] = 0;
					continue;
				}
				size_t sum = 0;
				if ( col > 0 && obstacleGrid[row][col - 1] != 0 ) {
					sum += obstacleGrid[row][col - 1];
				}
				if ( row > 0 && obstacleGrid[row - 1][col] != 0 ) {
					sum += obstacleGrid[row - 1][col];
				}
				obstacleGrid[row][col] = sum;
			}
		}

		return obstacleGrid[M - 1][N - 1];
	}
};
