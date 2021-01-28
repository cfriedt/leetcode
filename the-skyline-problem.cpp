/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

// clang-format off
// name: the-skyline-problem
// url: https://leetcode.com/problems/the-skyline-problem
// difficulty: 3
// clang-format on

#include <vector>

using namespace std;

enum {
  LEFT,
  RIGHT,
  HEIGHT,
};

enum {
  X,
  Y,
};

template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  for (int i = 0, N = v.size(); i < N; ++i) {
    os << v[i];
    if (i < N - 1) {
      os << ",";
    }
  }
  os << "]";
  return os;
}

class Solution {
public:
  vector<vector<int>> getSkyline(vector<vector<int>> &B) {
    vector<vector<int>> S;
    int xmin = B[0][LEFT];
    int xmax = xmin;

    for (auto &b : B) {
      xmax = max(xmax, b[RIGHT]);
    }

    vector<int> h(xmax - xmin + 1, 0);
    for (auto &b : B) {
      for (auto x = b[LEFT]; x <= b[RIGHT]; ++x) {
        h[x - xmin] = max(h[x - xmin], b[HEIGHT]);
      }
    }

    // cout << "h: " << h << endl;

    S.push_back(vector<int>{xmin, h[0]});
    for (int x = xmin + 1; x <= xmax; ++x) {
      auto &h_curr = h[x - xmin];
      auto &h_prev = h[x - xmin - 1];

      if (h_curr == h_prev) {
        continue;
      }

      if (h_curr > h_prev) {
        S.push_back(vector<int>{x, h_curr});
      } else {
        S.push_back(vector<int>{x - 1, h_curr});
      }

      // cout << "S: " << S << endl;
    }

    S.push_back(vector<int>{xmax, 0});

    // cout << "S: " << S << endl;

    return S;
  }
};
