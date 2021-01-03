/*
 * MIT License
 *
 * Copyright (c) 2018 Christopher Friedt
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
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
