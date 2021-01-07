/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <vector>

using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    constexpr int VISITED = 0xff;
    enum dir {
      RIGHT,
      DOWN,
      LEFT,
      UP,
    };
    const int M = matrix.size();
    const int N = matrix[0].size();
    const size_t L = M * N;

    enum dir dir = RIGHT;
    vector<int> elements;

    for (int row = 0, col = 0; elements.size() < L;) {

      int &val = matrix[row][col];
      if (val != VISITED) {
        elements.push_back(val);
        val = VISITED;
      }

      switch (dir) {
      case RIGHT:
        if (col + 1 >= N || matrix[row][col + 1] == VISITED) {
          dir = DOWN;
        } else {
          ++col;
        }
        break;
      case DOWN:
        if (row + 1 >= M || matrix[row + 1][col] == VISITED) {
          dir = LEFT;
        } else {
          ++row;
        }
        break;
      case LEFT:
        if (col - 1 < 0 || matrix[row][col - 1] == VISITED) {
          dir = UP;
        } else {
          --col;
        }
        break;
      case UP:
        if (row - 1 < 0 || matrix[row - 1][col] == VISITED) {
          dir = RIGHT;
        } else {
          --row;
        }
        break;
      }
    }

    return elements;
  }
};
