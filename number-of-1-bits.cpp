/*
 * Copyright (c) 2020 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <vector>

using namespace std;

class Solution {
public:
  int hammingWeight(uint32_t n) { return __builtin_popcount(n); }
};
