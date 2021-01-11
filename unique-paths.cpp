/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <stdexcept>

using namespace std;

class Solution {
public:
  // https://leetcode.com/problems/unique-paths/

  void helper(int r, int d, int m, int n, int &paths) {

    // e.g. m = n = 1
    // paths = 1

    // e.g. m = 2, n = 2
    // paths = 2

    // shortcut
    if (1 == m || 1 == n) {
      paths = 1;
      return;
    }

    if (m - 1 == r && n - 1 == d) {
      paths++;
      return;
    }
    // This complexity is O ( M * N ), or O( N^2 )
    // not very efficient unfortunately
    if (r < m - 1) {
      helper(r + 1, d, m, n, paths);
    }
    if (d < n - 1) {
      helper(r, d + 1, m, n, paths);
    }
  }

  size_t fact(size_t n) {
    if (0 == n) {
      return 1;
    }
    if (1 == n) {
      return 1;
    }
    size_t r = n * fact(n - 1);
    return r;
  }

  size_t choose(size_t n, size_t r) {
    size_t num = 1;
    for (size_t m_n = n; m_n > r; m_n--) {
      num *= m_n;
    }

    size_t den = fact(n - r);

    size_t quot = num / den;

    return quot;
  }

  int uniquePaths(int m, int n) {
    // in this case, m is the number of columns and n is the number
    // of rows.

    // termination condition:
    // the goal is reached when moves right is equal to m - 1
    // and moves down is equal to n - 1.

    // the problem can be solved with a forward recursion
    // that begins at the top-left of the board
    // However, the time complexity of that is O( M * N ) or O( N^2 ) when N ==
    // M int paths = 0; helper( 0, 0, m, n, paths ); return paths;

    // I think it can be broken down to just plain old arithmetic though
    // There will always be a total of L moves.
    // L = M - 1 + N - 1 = M + N - 2
    //
    // After working through a couple of examples, it becomes obvious that
    // the answer is C( M + N - 2, M - 1 ). However, the "choose" function
    // is poorly conditioned (i.e. is subject to integer overflow for big
    // numbers).
    //
    // My solution is to just use size_t and pre-simplify the numerator.

    if (m <= 0 || n <= 0) {
      return 0;
    }

    if (1 == m || 1 == n) {
      return 1;
    }

    return choose(m + n - 2, max(m - 1, n - 1));
  }
};
