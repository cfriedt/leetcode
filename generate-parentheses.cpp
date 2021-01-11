/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <vector>

using namespace std;

class Solution {
public:
  // https://leetcode.com/problems/generate-parentheses/

  vector<string> generateParenthesis(int n) {

    //
    // The recursive approach for generating strings seems sound.
    //
    // The analysis for this one is a bit tricky, and I would never be able
    // to pull this out of thin air in an interview.
    //
    // Also, I generally find it much more legible to read this code when it
    // is using a helper function, rather than just using the one gP() function.

    vector<string> result;
    helper(result, "", n, n);
    return result;
  }

protected:
  static void helper(vector<string> &result, string in_progress, int L, int R) {
    if (0 == L && 0 == R) {
      result.push_back(in_progress);
      return;
    }

    if (0 != L) {
      helper(result, in_progress + "(", L - 1, R);
    }

    if (0 != R && R > L) {
      helper(result, in_progress + ")", L, R - 1);
    }
  }
};
