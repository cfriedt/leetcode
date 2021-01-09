/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <algorithm>
#include <array>
#include <string>

#ifndef BIT
#define BIT(n) (1ULL << (n))
#endif

using namespace std;

// name: add-binary
// url: https://leetcode.com/problems/add-binary
// difficulty: 1

class Solution {
public:
  string addBinary(string a, string b) {
    // let's force a to always be the longer of the two
    if (b.size() > a.size()) {
      swap(a, b);
    }

    // a   b   c | sum  c
    // ------------------
    // 0   0   0 |  0   0
    // 0   0   1 |  1   0
    // 0   1   0 |  1   0
    // 0   1   1 |  0   1
    // 1   0   0 |  1   0
    // 1   0   1 |  0   1
    // 1   1   0 |  0   1
    // 1   1   1 |  1   1

    const array<char, 8> sum_lut = {
        '0', '1', '1', '0', '1', '0', '0', '1',
    };

    const array<bool, 8> carry_lut = {
        0, 0, 0, 1, 0, 1, 1, 1,
    };

    bool carry = false;
    string sum;

    if (a == b && a != "0") {
      sum = a;
      // simple multiplication by 2 => left shift by 1
      sum.push_back('0');
      return sum;
    }

    int i = a.size() - 1;
    int j = b.size() - 1;

    for (; i >= 0; --i, --j) {
      // bit[0] := carry
      // bit[1] := b[j]
      // bit[2] := a[i]
      uint8_t key = carry;
      if (j >= 0 && b[j] == '1') {
        key |= BIT(1);
      }
      if (a[i] == '1') {
        key |= BIT(2);
      }

      sum.push_back(sum_lut[key]);
      carry = carry_lut[key];
    }

    if (carry) {
      sum.push_back('1');
    }

    reverse(sum.begin(), sum.end());
    return sum;
  }
};
