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

	// https://leetcode.com/problems/minimum-size-subarray/

	int minSubArrayLen(int s, vector<int>& nums) {
		// Assumptions
		// - s, n can be negative
		// - there can be multiple subarrays with the same length
		//
		// Observation
		// - Brute Force: O( N^3 ) time
		//   -> Generate all subarrays O( N^2 )
		//      -> within the same loop, compute the sum of the subarray O(N)
		//
		// Analysis
		//
		// - Sliding window approach
		//  -> keep two integers, L and R
		//  -> single loop, initialize L,R to zero
		//  -> keep track of the shortest length
		//  -> keep a running total (adding new values, and removing old ones)
		//
		// Also, the bonus question was to see if an O( N log N ) solution can
		// be found. It *cannot*. Even using DP to create a cumulative sum, and
		// then using a binary search on that monotonically increasing data would
		// only yield you the *first* subarray that worked, not the *shortest*!

		size_t L,R;
		int sum;
		size_t shortest;

		for( L = 0, R = 0, sum = 0, shortest = INT_MAX; L < nums.size() && R < nums.size(); ) {
			if ( 0 == L && 0 == R ) {
				sum = nums[ 0 ];
			}
			if ( sum < s ) {
				if ( R + 1 < nums.size() ) {
					R++;
					sum += nums[ R ];
				} else {
					if ( L + 1 < nums.size() ) {
						sum -= nums[ L ];
						L++;
					} else {
						break;
					}
				}
			} else {
				if ( R - L + 1 < shortest ) {
					shortest = R - L + 1;
				}
				if ( 1 == shortest ) {
					// shortest possible answer found, so break early
					break;
				}
				if ( L + 1 < nums.size() ) {
					sum -= nums[ L ];
					L++;
				}
			}
		}

		if ( INT_MAX == shortest ) {
			return 0;
		} else {
			return shortest;
		}
	}
};
