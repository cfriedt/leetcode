/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

// clang-format off
// name: cut-off-trees-for-golf-event
// url: https://leetcode.com/problems/cut-off-trees-for-golf-event
// difficulty: 3
// clang-format on

#include <algorithm>
#include <deque>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  // convert row/col to key
  int make_key(int row, int col, int d = 0) {
    return (unsigned(d) << 16) | (unsigned(row) << 8) | unsigned(col);
  }

  // convert from key to row / col
  void rc(int key, int &row, int &col) {
    col = (key >> 0) & 0xff;
    row = (key >> 8) & 0xff;
  }

  int get_d(int key) { return (key >> 16) & 0xff; }

  int bfs(const vector<vector<int>> &forest, int a, int b) {
    const int rows = forest.size();
    const int cols = forest[0].size();

    // keep track of visited nodes
    unordered_set<int> visited;
    // queue for bfs, stack for dfs
    deque<int> q;

    q.push_back(a);
    visited.insert(a);

    while (!q.empty()) {
      int key = q.front();
      q.pop_front();
      visited.insert(key);

      int d = get_d(key);

      if ((key & 0xffff) == b) {
        return d;
      }

      int r, c;
      rc(key, r, c);

      for (auto &n : vector<vector<int>>{
               {r - 1, c}, {r, c + 1}, {r + 1, c}, {r, c - 1}}) {
        int nr = n[0];
        int nc = n[1];
        int nkey = make_key(nr, nc);

        if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) {
          continue;
        }

        if (forest[nr][nc] == 0) {
          continue;
        }

        if (visited.end() != visited.find(nkey)) {
          continue;
        }

        // here we do not add distance to the key
        visited.insert(nkey);

        // here we do add distance to the key
        nkey = make_key(nr, nc, d + 1);
        q.push_back(nkey);
      }
    }

    return -1;
  }

  int cutOffTree(vector<vector<int>> &forest) {
    /*

    The minimal total distance of trees in order from
    shortest to tallest is the sum of the minimal distances
    between trees in order.

    */

    const int rows = forest.size();
    const int cols = forest[0].size();
    vector<int> trees;
    int dist = 0;

    // collect all of the "trees" (i.e. cells > 1)
    // O(MN)
    for (auto row = 0; row < rows; ++row) {
      for (auto col = 0; col < cols; ++col) {
        if (forest[row][col] > 1) {
          trees.push_back(make_key(row, col));
        }
      }
    }

    // sort trees from smallest to largest
    sort(trees.begin(), trees.end(), [&](int a, int b) -> bool {
      int row_a, col_a;
      rc(a, row_a, col_a);

      int row_b, col_b;
      rc(b, row_b, col_b);

      return forest[row_a][col_a] < forest[row_b][col_b];
    });

    auto src = make_key(0, 0);
    for (auto tgt : trees) {
      auto d = bfs(forest, src, tgt);
      if (d == -1) {
        return -1;
      }
      dist += d;
      src = tgt;
    }

    return dist;
  }
};
