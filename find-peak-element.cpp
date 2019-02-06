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

	//https://leetcode.com/problems/find-peak-element

    int findPeakElement(vector<int>& nums) {

        // Assumptions
        // 1) no runs of numbers (stated in q's assumptions), i.e. no plateaus
        // 2) nums[ -1 ] == nums[ n ] = -inf
        // 3) [] is invalid (see observations below)
        //
        // Observations
        // 1) it follows from assumption 2, that
        //    a) the 0th element in [0] is a peak, just as the 0th element in [-5000] is a peak
        //    b) in [12], the 1st element (2) is a peak
        //    c) in [21], the 0th element (2) is a peak
        //    d) [] has no peaks, as [-inf,-inf] creates a plateau
        // 2) generally, a peak element is one, where
        //    let 0 <= i < n,
        //    let prev = (0 == i) ? INT_MIN : nums[ i - 1 ]
        //    let next = (n == i + 1 ) ? INT_MIN : nums[ i + 1 ]
        //
        // Is it possible to slide a window of length 3 along from the 0th to the (n-1)th element in the array
        // and find a peak? Since any peak will do, and since it can be assumed that there are no plateaus, that should be fine, but we
        // will verify that.
        //
        // Analysis
        //
        // Since we are making 2 comparison for every element, the algorithm is O( N ) in time and O( 1 ) in space
        // (only 2 additional stack variables are needed).
        //
        // Oh yeesh! I just read that the algorithm should be O( log N ) in complexity.
        //
        // That makes it more interesting!
        //
        // One data structure that I know is O( log N ) just for insertion is the heap, but in order to build the heap, N insertions are necessary which
        // would make it O( N log N ), which I do not think is acceptible.
        //
        // Another algorithm I'm aware of that is O( log N ) is binary search. Can binary search be used here? I don't think so.
        //
        // I think I'll just try to do it linearly in the time that I have.

        // Corner Case
        //
        // The nums = [INT_MIN] - in that case (in fact any case where size is 1, just return index 0)

        if ( 0 == nums.size() ) {
            return -1;
        }

        if ( 1 == nums.size() ) {
            return 0;
        }

        for( size_t i = 0; i < nums.size(); i++ ) {
            int prev = ( 0 == i ) ? INT_MIN : nums[ i - 1 ];
            int next = ( nums.size() == i + 1 ) ? INT_MIN : nums[ i + 1 ];
            if ( nums[ i ] > prev && nums[ i ] > next ) {
                return i;
            }
        }

        // I won't assume that every problem set contains a peak, and will just return -1 if no peak exists
        return -1;
    }
};
