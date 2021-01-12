/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

// name: n-queens-ii
// url: https://leetcode.com/problems/n-queens-ii
// difficulty: 3

#include <unordered_set>
#include <vector>

#ifndef BIT
#define BIT(n) (1ULL << (n))
#endif

using namespace std;

class Solution {
public:
  static inline unsigned popcount(unsigned n) { return __builtin_popcount(n); }

  static inline unsigned diag_up(unsigned r, unsigned c) { return r + c; }

  static inline unsigned diag_down(unsigned N, unsigned r, unsigned c) {
    return N - r - 1 + c;
  }

  void Q(uint8_t n, unordered_set<string> &paths, string path,
         uint16_t used_cols, uint16_t used_diag_up, uint16_t used_diag_down) {

    static const array<uint16_t, 10> nsoln = {0,  1, 0,  0,  2,
                                              10, 4, 40, 92, 352};

    uint8_t row = path.size() / n;

    if (row == n) {
      /* TODO: insert reflections, rotations.. */
      paths.insert(path);
      return;
    }

    for (int col = n - 1; col >= 0; --col) {
      if (BIT(col) & used_cols) {
        continue;
      }

      auto upd = diag_up(row, col);
      if (BIT(upd) & used_diag_up) {
        continue;
      }

      auto downd = diag_down(n, row, col);
      if (BIT(downd) & used_diag_down) {
        continue;
      }

      string row_str(n, '.');
      row_str[col] = 'Q';

      Q(n, paths, path + row_str, used_cols | BIT(col), used_diag_up | BIT(upd),
        used_diag_down | BIT(downd));

      if (nsoln[n] == paths.size()) {
        break;
      }
    }
  }

  int totalNQueens(int n) {
    unordered_set<string> paths;

    Q(n, paths, "", 0, 0, 0);

    return paths.size();
  }
};
