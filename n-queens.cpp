/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <array>
#include <unordered_set>
#include <vector>

#ifndef BIT
#define BIT(n) (1ULL << (n))
#endif

using namespace std;

// name: n-queens
// url: https://leetcode.com/problems/n-queens
// difficulty: 3

/*
Observations:
- at most 1 queen may be on each row
- at most 1 queen may be on each column
- at most 1 queen may be on a given up diagonal
- at most 1 queen may be on a given down diagonal
- with some examples, we see that
- Q(1) = 1, Q(2) = 0, Q(3) = 0, Q(4) = 2
- Additionally, we see that the number of diagonals = 2n - 1
- However, the naive solution is
  C(N,1) * C(N-1,1) * C(N-2,1) .. C(1,1) => O(N!)
  with N = 9, there are 362880 unique paths to choose and an internet search
  reveals that there are 352 unique solutions.
- for N = 9 we can represent rows, cols, up diagonals and down diagonals each
with a uint32_t the N = 4 solution shows that the result of the first solution
can be reflected vertically and horizontally to come up with valid solutions.
The solutions might not always be unique but they are valid.
- on the same topic, rotations of one solution will also result in other valid
solutions
- reducing the amount of time it takes to determine a path is incorrect could
very well be a good strategy to improving times. so it might be worth it to find
a good way to encode partial paths.
- If we follow the row-major convention, then we can encode a path by specifying
only the column that a queen occupies on each row.
- With that, it becomes obvious that we a search is over when it is of length N
- However, we can also determine much earlier if a particular placement is legal
by examining the state at each subsequent iteration.
- Using row-major / column encoding should allow us to also specify partial
paths. So if we have exhaused all possible paths after a path of length = 2, we
can add that path, as well as all of its mirrors and rotations, to a list of bad
paths.
- For the N = 9 case, each column can be 1 byte. If there are 362880 * 9 =
3265920 bytes to encode every possible path, so that's not even that bad.
- I might just use a string to encode the path, because at least it's hashable
by default.
*/

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

  vector<vector<string>> solveNQueens(int n) {
    unordered_set<string> paths;
    vector<vector<string>> output;

    Q(n, paths, "", 0, 0, 0);

    for (auto &p : paths) {
      vector<string> soln;
      for (size_t i = 0, N = p.size(); i < N; i += n) {
        soln.push_back(p.substr(i, n));
      }
      output.push_back(soln);
    }

    return output;
  }
};
