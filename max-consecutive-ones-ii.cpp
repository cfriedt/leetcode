/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <vector>

using namespace std;

class Solution {
public:

	// https://leetcode.com/problems/max-consecutive-ones-ii

	int findMaxConsecutiveOnes(vector<int>& nums) {
		// Assumptions:
		// - nums.size() == 0 => 0
		// - nums.size() == 1 => 1
		//
		// Observations:
		// - only really makes sense to flip a 0 to a 1, because
		//   flipping zeros have no effect other than to shorten the max
		//   consecutive run of 1's
		// - Brute Force: O( N^2 ) time O(1) space. We can do better in time.
		//
		// What if we just remember the indices of the 0's? This could even
		// just be put into a vector, named 'indices'
		//
		// Use two ints to iterate over indices vector, and two ints to
		// look at the indices in nums.
		//
		// int i <-- to refer to indices in 'indices'
		// int left_idx, right_idx <-- to refer to indices in 'nums'
		// set both left and right to zero
		// let right go first.
		// when i gets to a number, look at the number after it.
		// - if there is no number after it, then set right_idx to nums.size() - 1
		// - if there is a number after it, then set right_idx to indices[ right ] - 1
		// - left_idx refers to zero in nums.
		// - the longest run will be is right_idx - left_idx + 1
		// - compare max_consec (initially 0) to right_idx - left_idx + 1 and replace
		//   if appropriate
		// - if there are still numbers after i, then set left_idx to right_idx
		//    and continue exploring with right idx. repeating over and over
		// - each index is evaluated maximally once
		//
		// total complexity: O( N ) + O( N ) time, O( N ) space (worst-case)

		if ( nums.size() <= 1 ) {
			return nums.size();
		}

		vector<int> indices;

		for( size_t i = 0; i < nums.size(); i++ ) {
			if ( 0 == nums[ i ] ) {
				indices.push_back( i );
			}
		}

		if ( 0 == indices.size() ) {
			return nums.size();
		}

		size_t max_consecutive = 0;
		for( size_t i = 0, left = 0, right = 0; i < indices.size(); i++ ) {
			if ( 0 == i ) {
				left = 0;
			} else {
				left = indices[ i - 1 ] + 1;
			}
			if ( i + 1 < indices.size() ) {
				right = indices[ i + 1 ] - 1;
			} else {
				right = nums.size() - 1;
			}
			size_t len = right - left + 1;
			if ( len > max_consecutive ) {
				max_consecutive = len;
			}
		}

		return max_consecutive;
	}
};
