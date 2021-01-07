/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:

	// https://leetcode.com/problems/pascals-triangle/

	vector<vector<int>> generate( int numRows ) {
		// Assumptions: r > 0
		//
		// Example:
		//
		// Input: 5
		// Output:
		// [
		// 	    [1],
		//     [1,1],
		//    [1,2,1],
		//   [1,3,3,1],
		//  [1,4,6,4,1]
		// ]
		//
		// Observations:
		// - row i has i elements
		// - I believe there was some relationship between nCr and Pascal's triangle, like the kth item is
		//   the nth row is equal to nCr,
		//   but factorial computation can be slow, and you don't really end up reusing previous calculations
		//   well unless you use a hash table of some kind. That would be one approach.
		// - another approach is to add the numbers above to the left and above to the right (if they exist)
		//
		// Let's outline the algorithm
		//
		// row     i     Lprnt      Rprnt      S   comment
		// ===============================================
		// 0       0     -          -          1   - initial conditions
		// 1       0     -          0          1   - sum is row[0][0]
		// 1       1     -          0          1   - sum is row[0][0]
		// 2       0     -          1          1   - row[1][0]
		// 2       1     0          1          2   - row[1][0] + row[1][1]
		// 2       2     1          -          1   - row[1][0] + row[1][1]
		// ...
		//
		// Analysis:
		// - if N == numRows, then there are O( Sum(1,5) )
		// - using the recurrence relation, a(n) = Sum(k=1:n){ k } = n(n + 1)/2
		// - therefore, this algorithm is O(N^2)
		//
		// It's possible that this could be sped up with a hash map doing factorial calculations
		// but my intuition tells me that's unlikely, and a better solution
		// eludes me at the present time, so let's say we're ok to code up this example.
		//
		// Also, just discovered that the copy + reverse does *not* actually speed things
		// up based on a scientifically tractable sample size of 1 ;-)

		vector<vector<int>> r;

		//constexpr size_t min_row_to_use_symmetry_copy = SIZE_MAX;

		for( size_t row = 0; (int)row < numRows; row++ ) {

			r.push_back( vector<int>( row + 1 ) );

			for( size_t i = 0; i < row + 1; i++ ) {

				int sum = 0;

				if ( 0 == row ) {
					sum = 1;
#if 0
				} else if ( row >= min_row_to_use_symmetry_copy ) {
					// shortcut due to symmetry:
					// reverse and copy half of the row to the other side
					// note, this speedup only makes sense if the copy operation
					// is cheaper than a few memory fetches and additions
					// would likely involve simd, which typically works in
					// multiples of 16, on average, but some benchmarking could
					// give the specific value on a given architecture.

					size_t L = row + 1;
					size_t N = L / 2;
					size_t M;
					if ( 0 == L % 2 ) {
						// if the row is even in length, say L = 4, we want to copy the first
						// L / 2 elements to the L / 2 memory location.
						M = L / 2;
					} else {
						// if the row is odd in length, say L = 3, we want to copy the first
						// L / 2 elements to the L / 2 + 1 memory location
						M = L / 2 + 1;
					}

					copy( & r[ row ][ 0 ], & r[ row ][ N ], & r[ row ][ M ] );
					reverse( & r[ row ][ M ], & r[ row ][ row ] );

					break;
#endif
				}

				if ( i > 0 ) {
					sum += r[ row - 1 ][ i - 1 ];
				}

				if ( i < row ) {
					sum += r[ row - 1 ][ i ];
				}

				r[ row ][ i ] = sum;
			}
		}

		// Now let's verify our algorithm for row 2. We expect [1,2,1]
		//
		// In the inner loop, we'll be going from i = 0 to 2
		//
		// for row = 2, i = 0
		//      ( 0 > 0 ) => false
		//      ( 0 + 1 < 2 ) => true, so add r[ 1 ][ 0 ], which is 1
		//      r[2][0] => 1

		return r;
	}
};
