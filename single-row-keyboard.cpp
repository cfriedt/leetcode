/*
 * Copyright (c) 2019 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <array>
#include <cmath>
#include <string>

using namespace std;

// https://leetcode.com/problems/single-row-keyboard/

class Solution {
public:
  int calculateTime(string keyboard, string word) {

    array<uint8_t, 26> kbm;

    for (size_t i = 0, M = keyboard.size(); i < M; ++i) {
      kbm[keyboard[i] - 'a'] = uint8_t(i);
    }

    int time = 0;
    int8_t prev_pos = 0;
    for (auto &c : word) {
      c -= 'a';
      int8_t pos = kbm[c];
      time += abs(pos - prev_pos);
      prev_pos = pos;
    }

    return time;
  }
};
