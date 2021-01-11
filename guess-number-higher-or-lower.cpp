/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <climits>

using namespace std;

int guess(int num);

class Solution {
public:
  // https://leetcode.com/problems/guess-number-higher-or-lower

  int guessNumber(int n) {

    // Assumptions
    // - the idea is to guess the number as fast as possible
    // - assume n is large
    // - assume range is inclusive [1,n]
    // - if secret number is not in [1,n], return -1
    //
    // Observations
    // - numbers 1..n are already sorted :-)
    // - Brute force: O( N ) time, O( 1 ) space
    // - Binary Search: O( logN ) time, O( 1 ) space
    // - Want to identify the corner case that n < 1
    // - Want to identify the corner case that the secret number is < 1
    // - Want to identify the corner case that n is INT_MAX

    int L, R;
    for (L = 1, R = n; L <= R;) {

      int M;

      if (L == R) {
        if (0 == guess(INT_MAX)) {
          return INT_MAX;
        }
        return -1;
      }

      if (L > INT_MAX / 2 || R > INT_MAX / 2) {
        M = L / 2 + R / 2;
      } else {
        M = (L + R) / 2;
      }

      int r = guess(M);

      if (0 == r) {

        return M;

      } else if (-1 == r) {

        if (1 == M) {
          break;
        }

        R = M - 1;

      } else if (+1 == r) {

        if (n == M) {
          break;
        }

        L = M + 1;
      }
    }

    return -1;
  }
};
