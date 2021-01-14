/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

// clang-format off
// name: divisor-game
// url: https://leetcode.com/problems/divisor-game
// difficulty: 1
// clang-format on

#include <climits>

using namespace std;

class Solution {
public:
  bool divisorGame(int N) {
    enum player {
      ALICE,
      BOB,
    };

    uint8_t loser;
    for (loser = ALICE; 1 != N; --N, loser ^= 1)
      ;
    return loser == BOB;
  }
};
