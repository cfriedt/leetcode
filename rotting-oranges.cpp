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

#include <unordered_set>
#include <vector>

using namespace std;

// https://leetcode.com/problems/rotting-oranges

using coord = pair<size_t, size_t>;

namespace std {

template <> struct hash<coord> {
  size_t operator()(const coord &k) const {
    return ((hash<size_t>()(k.first) ^ (hash<size_t>()(k.second) << 1)) >> 1);
  }
};

} // namespace std

class Solution {
public:
  int orangesRotting(vector<vector<int>> &grid) {
    // notes:
    // - if nfresh is 0 at the beginning, then the answer is zero
    // - at least one orange must be rotten at the beginning, otherwise the
    // answer is always -1
    // - if every orange is not connected 4-directionally, then the answer is
    // always -1
    //
    // - do a first scan of rotten oranges, adding coordinates to rotten
    //   if a) they are rotten, and b) if they have any surrounding non-rotten
    //   fruit

    const size_t M = grid.size();
    const size_t N = grid[0].size();

    size_t nfresh = 0;
    unordered_set<coord> rotten;

    for (size_t i = 0; i < M; ++i) {
      for (size_t j = 0; j < N; ++j) {
        if (grid[i][j] == 1) {
          ++nfresh;
          continue;
        }
        if (grid[i][j] == 2) {
          // check up
          if (i > 0 && grid[i - 1][j] == 1) {
            rotten.insert(coord(i, j));
            continue;
          }
          // check down
          if (i < M - 1 && grid[i + 1][j] == 1) {
            rotten.insert(coord(i, j));
            continue;
          }
          // check left
          if (j > 0 && grid[i][j - 1] == 1) {
            rotten.insert(coord(i, j));
            continue;
          }
          // check right
          if (j < N - 1 && grid[i][j + 1] == 1) {
            rotten.insert(coord(i, j));
            continue;
          }
        }
      }
    }

    for (int count = 0;; ++count) {

      unordered_set<coord> new_rotten;

      if (0 == nfresh) {
        return count;
      }

      if (0 == rotten.size()) {
        return -1;
      }

      for (auto &rot : rotten) {
        size_t i = rot.first;
        size_t j = rot.second;
        // rot up
        if (i > 0 && grid[i - 1][j] == 1) {
          grid[i - 1][j] = 2;
          new_rotten.insert(coord(i - 1, j));
        }
        // rot down
        if (i < M - 1 && grid[i + 1][j] == 1) {
          grid[i + 1][j] = 2;
          new_rotten.insert(coord(i + 1, j));
        }
        // rot left
        if (j > 0 && grid[i][j - 1] == 1) {
          grid[i][j - 1] = 2;
          new_rotten.insert(coord(i, j - 1));
        }
        // rot right
        if (j < N - 1 && grid[i][j + 1] == 1) {
          grid[i][j + 1] = 2;
          new_rotten.insert(coord(i, j + 1));
        }
      }

      nfresh -= new_rotten.size();
      rotten = new_rotten;
    }
  }
};
