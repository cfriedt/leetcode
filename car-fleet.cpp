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
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:

	// https://leetcode.com/problems/car-fleet/

	int carFleet(int target, vector<int>& position, vector<int>& speed) {

	    (void) target;
	    (void) position;
	    (void) speed;

	    // The idea here is that each car starts off as an independent fleet of one
	    // then, instead of a fast fleet overtaking a slow fleet in front of it,
	    // the two fleets merge and travel at the same speed as the slow fleet.
	    // If a fast fleet is in front of a slow fleet, or if two adjacent fleets
	    // have the same velocity, then they will not merge.

	    // Approach A:

	    // One way to solve this would be to compute the gcd of all speeds, and
	    // then use that as a delta-time to evaluate positions, speeds, and fleet
	    // membership at discrete time "ticks".

	    // Approach B:

	    // Another way to solve this would be to only ever look at the fastest
	    // fleet. This will require maintaining something like a max-heap based
	    // on speed and maybe something like a vector to keep track of position
	    // and order.

	    // The up-side to Approach A is that it's kind of simple.
	    // The down-side to Approach A is that its time-complexity is dependent
	    // on the input arguments. GCD evaluation is O(T) using subtraction
	    // and O(log(T)) using division.
	    //
	    // Overall, we're looking at O(NT + log(T)) since 1/C * T "ticks" need
	    // to be evaluated approximately N times in addition to the GCD.

	    // The up-side to Approach B is that it's not dependent on the
	    // numerical value of target. We're only ever considering the fastest
	    // fleet (as it has the potential to finish race or merge with a fleet
	    // in front of it.
	    //
	    // This approach is a bit tricky though. If we use a pointers to the
	    // element in the speed vector, then building the max heap will require
	    // O(Nlog(N)) complexity.

	    // evaluating the problem requires
	    // a time-complexity that is dependent on the target rather than the
	    // number of items.



	    return 0;
	}
};
