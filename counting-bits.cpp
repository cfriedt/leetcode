/*
 * Copyright (c) 2019 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <array>
#include <vector>

using namespace std;

class Solution {
public:
  // https://leetcode.com/problems/counting-bits/

  vector<int> countBits(int num) {
    vector<int> r(num + 1, 0);
    for (int i = 0; i <= num; i++) {
      r[i] = ones(i);
    }
    return r;
  }

protected:
  static const array<int, 16> lut;

  static int ones(uint8_t x) { return lut[x & 0xf] + lut[(x >> 4) & 0xf]; }

  static int ones(int x) {
    uint8_t *px = (uint8_t *)&x;
    return ones(px[0]) + ones(px[1]) + ones(px[2]) + ones(px[3]);
  }
};

const array<int, 16> Solution::lut = array<int, 16>{{
    0,
    1,
    1,
    2,
    1,
    2,
    2,
    3,
    1,
    2,
    2,
    3,
    2,
    3,
    3,
    4,
}};
