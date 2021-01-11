/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <vector>

using namespace std;

class Solution {
public:
  // https://leetcode.com/problems/remove-duplicates-from-sorted-array/

  int removeDuplicates(vector<int> &nums) {

    if (0 == nums.size()) {
      return 0;
    }

    size_t i, j;
    for (i = 0, j = 0; i < nums.size(); i++) {
      if (nums[i] != nums[j]) {
        j++;
        nums[j] = nums[i];
      }
    }
    return j + 1;
  }
};
