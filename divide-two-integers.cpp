/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
  // https://leetcode.com/problems/divide-two-integers

  int divide(int dividend, int divisor) {

    if (0 == dividend) {
      return 0;
    }

    if (0 == divisor) {
      if (dividend > 0) {
        return INT_MAX;
      } else {
        return INT_MIN;
      }
    }

    if (1 == divisor) {
      return dividend;
    }

    if (-1 == divisor && INT_MIN == dividend) {
      return INT_MAX;
    }

    if (-1 == divisor) {
      return -dividend;
    }

    int quotient = 0;

    if (INT_MIN == dividend && INT_MIN == divisor) {
      return 1;
    }

    if (INT_MIN == dividend) {
      quotient++;
      dividend += abs(divisor);
    }

    if (INT_MIN == divisor) {
      return 0;
    }

    bool neg = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0);

    dividend = abs(dividend);
    divisor = abs(divisor);

    for (;;) {

      // return integer version of dividend / divisor
      if (0 == dividend) {
        break;
      }

      if (divisor > dividend) {
        break;
      }

      quotient++;
      dividend -= divisor;
    }

    if (neg) {
      quotient = -quotient;
    }

    return quotient;
  }
};
