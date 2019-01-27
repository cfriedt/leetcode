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

#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:

	// https://leetcode.com/problems/missing-number/

	int missingNumber(vector<int>& nums) {
		// Assumptions:
		//
		// Observations:
		//
		// - the value of nums.size() will always be in the array
		// -
		//
		// Analysis:
		//
		// brute force: O( N^2 ) in time, O( 1 ) in space
		//
		// An alternative is to use a hash set, requires 2 loops, the first over the vector,
		// and the second over the set.
		//
		// O( N ) in time, O( N ) in space

		unordered_set<int> s;

		for( size_t i = 0; i < nums.size(); i++ ) {
			if ( (size_t) nums[ i ] < nums.size() ) {
				s.insert( nums[ i ] );
			}
		}
		for( size_t i = 0; i < nums.size(); i++ ) {
			if ( s.end() == s.find( i ) ) {
				return i;
			}
		}

		// corner-case ... all of the numbers from 0 to nums.size() - 1 are present
		// in the array, as-is, so the last remaining number of the "set" is nums.size() itself.
		return nums.size();
	}
};
