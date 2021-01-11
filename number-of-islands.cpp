/*
 * Copyright (c) 2019 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <algorithm>
#include <array>
#include <iostream>
#include <sstream>
#include <unordered_set>
#include <vector>

using namespace std;

// https://leetcode.com/problems/number-of-islands/

using Grid = vector<vector<char>>;
using coord = pair<ssize_t, ssize_t>;

namespace std {

template <> struct hash<coord> {
  size_t operator()(const coord &key) const {
    constexpr uint64_t seed = 0x1234abcd5678ef90;
    hash<ssize_t> hasher;
    return seed ^ hasher(key.first) ^ hasher(key.second);
  }
};

constexpr coord UP = coord(-1, 0);
constexpr coord DOWN = coord(1, 0);
constexpr coord LEFT = coord(0, -1);
constexpr coord RIGHT = coord(0, 1);

coord operator+(const coord &lhs, const coord &rhs) {
  coord r(lhs);
  r.first += rhs.first;
  r.second += rhs.second;
  return r;
}

} // namespace std

class Solution {
public:
  int numIslands(vector<vector<char>> &grid) {

    // so my strategy here is more of an open-ended exploration algorithm
    // but it basically involves

    // 1) linear search through the grid - O(MN)
    // 2) tracing the perimeter around an island - probably bounded by O(MN)
    // 3) filling-in an island, so that it's internal pixels are > 0 as well
    //    possibly O(K), where K is the number of 1's
    // 4) eroding an island to "sink" it, i.e. turning it to all-zeros
    //    (so that the algorithm can continue without interfere with the
    //    remainder of the grid - correction - binary masking O(K)
    // 5) increment island-counter by 1
    //
    // So overall this algorithm is probably O(MNK) or O(N^3) if M, N, and K are
    // similar
    //
    // There may be a better DP solution..
    //
    // I previously thought about implementing an edge & corner detection
    // algorithm which is nice because it's linear, but it seems more
    // complicated, generally, and we're not necessarily looking for

    const size_t M = grid.size();
    if (0 == M) {
      return 0;
    }
    const size_t N = grid[0].size();
    if (0 == N) {
      return 0;
    }

    int n_islands = 0;
    for (size_t row = 0; row < M; row++) {
      for (size_t col = 0; col < N; col++) {
        if ('1' == grid[row][col]) {
          coord c(row, col);
          island isle(grid, c);
          fillIsland(isle);
          markVisited(isle);
          n_islands++;
        }
      }
    }

    return n_islands;
  }

protected:
  struct island {

    explicit island(Grid &g, const coord &c) : grid(g), head(c) {}

    Grid &grid;
    coord head;
    unordered_set<coord> dirt;

    char getGrid(const coord &c) const { return grid[c.first][c.second]; }

    bool inBounds(const coord &c) {
      return true && c.first >= 0 && c.first < ssize_t(grid.size()) &&
             c.second >= 0 && c.second < ssize_t(grid[0].size());
    }
  };

  void fillIsland(island &isle) {
    // for now, ignore any potential "lakes" assume that islands are solid.

    // The typical strategy for this is to take a seed point and "grow" it
    // recursively. This function isn't designed to be recursive though, so
    // maybe just having a set of seed points to check should be fine

    unordered_set<coord> seeds;

    seeds.insert(isle.head);

    for (; !seeds.empty();) {

      coord seed = *seeds.begin();
      seeds.erase(seed);
      isle.dirt.insert(seed);

      for (auto &x :
           array<coord, 4>{seed + UP, seed + DOWN, seed + LEFT, seed + RIGHT}) {
        if (isle.inBounds(x) && '1' == isle.getGrid(x) &&
            isle.dirt.end() == isle.dirt.find(x)) {
          seeds.insert(x);
        }
      }
    }
  }

  void markVisited(island &isle) {
    // actually, we don't even need to do an erode, because we just need to
    // binary mask the original grid
    for (auto &d : isle.dirt) {
      isle.grid[d.first][d.second] = '0';
    }
  }
};
