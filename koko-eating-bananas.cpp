/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>

using namespace std;

static inline int eval( vector<int> piles, int K ) {
	int acc = 0;
	for( auto & p: piles ) {
		acc += int( ceil( p / double( K ) ) );
	}
	return acc;
}

class Solution {
public:

	// https://leetcode.com/problems/koko-eating-bananas/

	int minEatingSpeed(vector<int>& piles, int H) {

		// Assumptions:
		// - Invalid inputs are the following, but there is no need to check them.
		//   Assume the inputs are not poorly conditioned.
		//   - element of piles is negative
		//   - H <= 0
		//   - H < piles.length
		//   - N == piles.size() > 0 (implied by above rules)
		// - 1 <= piles.length <= 10^4
		// - piles.length <= H <= 10^9
		// - 1 <= piles[i] <= 10^9
		//
		// Extra Questions:
		// - Does the ordering of piles matter? No
		// - Does piles have duplicate elements? Maybe

		// Observations:
		// - brute force would just have K start at 1 and then increment until
		//   sum( i = 0, i < N - 1, ceil( piles[ i ] / K ) <= H
		// - what is the upper bound of K? max(piles)
		// - what is the lower bound of K? 1 (being a positively-defined int)
		//
		// Let's say that Z = max(piles)
		//
		// Then this algorithm becomes
		//   - O( N * Z )
		//   - if N and M are large, then this is approximately O( N ^ 2 ).
		//
		// I feel like we should be able to do better than O( N * Z ).
		//
		// If we sort the piles, then we get the minimum and maximum pile sizes. I'm not
		// sure yet if it helps to have the minimum pile size, but we know the maximum K is
		// equal to the maximum pile size.
		//
		// Sorting is O( N log N ) in time, and this can be done in-place with heap sort
		// since ordering does not matter, thus space complexity is O( 1 ).
		//
		// We can do a binary search in [1,Z] and check the N elements of
		// piles each time, for a O( N log Z ) in time and O( 1 ) in space.
		//
		// The complexity for this algorithm is therefore O( N ( log N + log Z ) ) in time and
		// O( 1 ) in space.
		//
		// I think the catch in this case is to just ensure that I can implement a binary search
		// easily enough.
		//
		// Assuming that the above algorithm is good, let's do eeeeat!

		int K = -1;

		// O( N log N ) time, O( 1 ) space (hopefully)
		sort( piles.begin(), piles.end() );
		int upper = piles.back();
		int Z = upper;

#if 1
		// binary search + comparison for each of piles
		// O( log Z ) time, O( 1 ) space

		for( int L = 1, R = Z; L <= R; ) {

			int M = (L + R) / 2;

			// evaluate potential K
			// O( N ) time, O( 1 ) space
			int acc = eval( piles, M );

			if ( acc <= H ) {
				if ( -1 == K || M < K ) {
					K = M;
				}
			}

			if ( acc > H ) {
				L = M + 1;
			} else {
				R = M - 1;
			}
		}
#else
		// brute force
		// O( Z ) time, O( 1 ) space
		for( K = 1; K <= Z; K++ ) {
			// evaluate potential K
			// O( N ) time, O( 1 ) space
			int acc = eval( piles, K );
			if ( acc <= H ) {

				break;
			}
		}
#endif

		return K;
	}
};
