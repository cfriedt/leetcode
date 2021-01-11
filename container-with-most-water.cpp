/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  // https://leetcode.com/problems/container-with-most-water

  int maxArea(vector<int> &height) {

    int highest = 0;

    for (size_t l = 0, r = height.size() - 1; l < r;) {
      highest = max(highest, int((r - l) * min(height[l], height[r])));
      if (height[l] < height[r]) {
        l++;
      } else {
        r--;
      }
    }

    return highest;
  }
};
