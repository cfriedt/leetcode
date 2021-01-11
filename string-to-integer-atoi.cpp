/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <algorithm>
#include <array>
#include <climits>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  // https://leetcode.com/problems/string-to-integer-atoi

  int myAtoi(string str) {
    for (; str.length() > 0 && ' ' == str[0]; str = str.substr(1))
      ;
    if (0 == str.length()) {
      return 0;
    }
    int sign = '-' == str[0] ? -1 : +1;
    if ('-' == str[0] || '+' == str[0]) {
      str = str.substr(1);
    }

    if (str[0] < '0' || str[0] > '9') {
      return 0;
    }

    array<uint8_t, 10> decimal_digits;
    fill(decimal_digits.begin(), decimal_digits.end(), 0);
    size_t highest_pos = 0;
    for (size_t i = 0; str[0] >= '0' && str[0] <= '9';
         str = str.substr(1), i++) {
      if ('0' == str[0] && 0 == i) {
        i--;
        continue;
      }

      if (i >= decimal_digits.size()) {
        if (sign > 0) {
          return INT_MAX;
        } else {
          return INT_MIN;
        }
      }

      decimal_digits[i] = str[0] - '0';
      highest_pos = i;
    }
    reverse(decimal_digits.begin(), decimal_digits.begin() + highest_pos + 1);

    int accumulator = 0;
    for (size_t i = 0, fac = 1; i <= highest_pos; i++, fac *= 10) {
      uint64_t diff = ((uint64_t(1) << 31) - 1) - accumulator;
      uint64_t xx = decimal_digits[i] * fac;
      if (xx > diff) {
        if (sign > 0) {
          return INT_MAX;
        } else {
          return INT_MIN;
        }
      }
      accumulator += xx;
    }

    return accumulator * sign;
  }
};
