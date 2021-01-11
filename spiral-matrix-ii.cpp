/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <vector>

using namespace std;

class Solution {
public:
  // https://leetcode.com/problems/spiral-matrix-ii

  vector<vector<int>> generateMatrix(int n) {
    // Analysis
    // O( N^2 ) (or O(N) ? )
    vector<vector<int>> r = vector<vector<int>>(n, vector<int>(n, 0));

    enum {
      RIGHT,
      DOWN,
      LEFT,
      UP,
      N_DIR,
    };

    int m;
    int dir;
    int row;
    int col;

    for (m = 1; m <= n * n; m++) {
      if (1 == m) {
        row = 0;
        col = 0;
        dir = RIGHT;
      }

      r[row][col] = m;

      if (n * n == m) {
        break;
      }

      switch (dir) {
      case RIGHT:
        if (col + 1 >= n || r[row][col + 1] != 0) {
          dir = DOWN;
          row++;
        } else {
          col++;
        }
        break;
      case DOWN:
        if (row + 1 >= n || r[row + 1][col] != 0) {
          dir = LEFT;
          col--;
        } else {
          row++;
        }
        break;
      case LEFT:
        if (0 == col || r[row][col - 1] != 0) {
          dir = UP;
          row--;
        } else {
          col--;
        }
        break;
      case UP:
        if (0 == row || r[row - 1][col] != 0) {
          dir = RIGHT;
          col++;
        } else {
          row--;
        }
        break;
      }
    }

    return r;
  }
};
