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

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:

	// https://leetcode.com/problems/two-sum/

	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> r;

		//
		// Assumptions:
		// - there is always exactly one solution for a given set of inputs
		// - you may only use the same element once
		//

		// Analysis:
		//
		// Brute force approach is O( N^2 ), where you iterate indices i & j over all
		// possible combinations. Naturally, you would start at j = i in the the inner
		// loop to avoid checking both (i,j) and (j,i), which is equivalent to generating all
		// unique combinations of two elements without ordering.
		// However, O( N^2 ) is bad and it easily gets out of hand for anything over 10000.
		// There is likely a better way to do it.
		//
		// It can likely be done linearly O( 2N ) => O( N )
		// E.g. for [2,7,11,15], 9
		//
		// O( N )
		// Put the values into a hash table where the key == nums[ i ] and the value == i
		//
		// Look through the list one more time to find a complement
		// O( N )
		// i    nums[ i ]   9 - nums[ i ]     seen 9 - nums[ i ]
		// 0       2            7                   no
		// 1       7            2                   yes! => return i, and the index of the 9 - nums[ i ] value
		//
		// It's unlikely that this problem can be solved in sub-linear time with e.g. sorting
		// becuase the sorting itself is N lg N.

		unordered_map<int,int> nums_observed;

		// first pass both adds items to the map and checks if each new item's complement has already been added
		// this is a shortcut for the case
		for( int i = 0; i < (int)nums.size(); i++ ) {
			int complement = target - nums[ i ];
			auto it = nums_observed.find( complement );
			if ( nums_observed.end() != it ) {
				r = vector<int>({ it->second, i });
				break;
			}
			nums_observed[ nums[ i ] ] = i;
		}

		return r;
	}
};
