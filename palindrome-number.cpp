/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

class Solution {
public:
  // https://leetcode.com/problems/palindrome-number

  bool isPalindrome(int x) {

    if (0 == x) {
      return true;
    }

    if (x < 0) {
      return false;
    }

    int y = 0;
    for (int z = x; z != 0;) {
      y *= 10;
      y += z % 10;
      z /= 10;
    }

    return y == x;
  }
};
