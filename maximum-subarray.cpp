/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  // https://leetcode.com/problems/maximum-subarray/

  int maxSubArray(vector<int> &nums) {
    if (nums.empty()) {
      return 0;
    }

    int max_sum = INT_MIN;
    int sum = 0;

    for (auto &n : nums) {
      sum += n;
      if (sum >= max_sum) {
        max_sum = sum;
      }
      if (sum < 0) {
        sum = 0;
      }
    }

    return max_sum;
  }
};
