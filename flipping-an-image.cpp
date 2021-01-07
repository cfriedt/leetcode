/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A) {
    const size_t rows = A.size();
    const size_t cols = (rows > 0) ? A[0].size() : 0;

    for (size_t row = 0; row < rows; ++row) {
      auto &v = A[row];
      reverse(v.begin(), v.end());
      for (size_t col = 0; col < cols; ++col) {
        v[col] ^= 1;
      }
    }

    return A;
  }
};
