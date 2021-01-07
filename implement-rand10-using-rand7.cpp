/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <cmath>

using namespace std;

extern int rand7();

class Solution {
public:

	// https://leetcode.com/problems/implement-rand10-using-rand7/

	int rand10() {
		// Assumptions
		// -----------
		// rand7 is iid.
		//
		//
		// Observations
		// ------------
		//
		// * Cannot simply interpolate because we would lose resolution
		//   since 10 is larger that
		// * Note: 0 is *not* included in the distribution!
		//   I.e. given a uniform distribution, the expectation of
		//   rand7() is (1 + 7)/2 = 4 and the expectation of rand10 is
		//   (1 + 10)/2 = 5.5 .
		// * This is just like a 6-sided die-roll, where the expectation
		//   is, non-intuitively, 3.5.
		//
		// Thoughts
		// --------
		//
		// Originally, I was tempted to use the least-common-multiple
		// of 7 and 10, and then 8 and 11, and then scale,
		// but that method does not seem to work. I think what that method
		// actually does, is multiply the probability distributions, which
		// then makes the overall probability distribution more or less normal.
		//
		// TBH, I read this from the solution, and it's obvious now.
		// To get a random number in the range [1,10] from a generator
		// that gives you a range [1,7], simply add two random numbers
		// together, modulo 10, and reject samples that fall outside that range
		// It's the addition that preserves uniformity!!!
		//
		// Analysis
		// --------
		//
		// Best case scenario: O(1) (takes exactly 2 iterations, with zero rejections).
		// Worst case scenario: O(inf) (even though its statistically unlikely, it's
		//                              still possible to have numbers that add up to
		//                              greater than 10).
		//
		// Assuming IID (that is that the results of each rand7() are
		// independent), then the distribution of the sum of expected
		// values is also uniform.
		int idx;

		do {
			int row = rand7();
			int col = rand7();
			idx = col + (row - 1) * 7;
		} while( idx > 40 );

		return 1 + ( idx - 1 ) % 10;
	}
};
