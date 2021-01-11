/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  // https://leetcode.com/problems/missing-number/

  int missingNumber(vector<int> &nums) {
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
    // An alternative is to use a hash set, requires 2 loops, the first over the
    // vector, and the second over the set.
    //
    // O( N ) in time, O( N ) in space

    unordered_set<int> s;

    for (size_t i = 0; i < nums.size(); i++) {
      if ((size_t)nums[i] < nums.size()) {
        s.insert(nums[i]);
      }
    }
    for (size_t i = 0; i < nums.size(); i++) {
      if (s.end() == s.find(i)) {
        return i;
      }
    }

    // corner-case ... all of the numbers from 0 to nums.size() - 1 are present
    // in the array, as-is, so the last remaining number of the "set" is
    // nums.size() itself.
    return nums.size();
  }
};
