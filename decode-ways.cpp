/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <string>
#include <vector>

using namespace std;

// https://leetcode.com/problems/minimum-path-sum
//
// I tried a number of solutions, and even tried
// to do it backwards. But what I didn't see is
// the thing that this person obviously saw
// https://goo.gl/HEDfoL

// In this case, the trick is to start at the back. It's possible
// to start forming the recursion as soon as you look into inputs 0 to 110, or
// possibly earlier.
//                substr(i,2)
// s      dp[i]   within (0,26]?  dp[i+1] dp[i+2]   comment
// --------------------------------------------------------
// 0        0     0               -       -         sequence staring with 0 is
// not in the mapping 00..09   0     00              -       -         sequence
// staring with 0 is not in the mapping 1..9     1     1               -       -
// establishes value for 1..9 10       1     1               0       - uses
// previously computed value for 0 11..19   2     1               1       - uses
// previously computed value for 1..9 20       1     1               0       -
// uses previously computed value for 0 21..26   2     1               1       -
// uses previously computed value for 1..6 27..29   1     0               1 -
// uses previously computed value for 7..9 30..99   1     0               1 -
// uses previously computed value for 1..9 100      1     1               0 -
// uses previously computed value for 0 101..109 2     1               0       1
// uses previously computed value for 0, 1..9 110      1     1               1
// 0         uses previousl computed value for 1..9, 0 111      3     1 1 1 uses
// previousl computed value for 1..9, 1..9
//..
//
// This is a good example of when DP can use a more than 1 element of history.

class Solution {
public:
  int numDecodings(const string &s) {

    if (s.empty()) {
      return 0;
    }

    vector<int> dp(s.size() + 1, 0);
    dp[s.size()] = 1;
    dp[s.size() - 1] = ('0' == s[s.size() - 1]) ? 0 : 1;

    for (int i = s.size() - 2; i >= 0; i--) {
      if ('0' == s[i])
        continue;
      string t = s.substr(i, 2);
      int x = stoi(t);
      if (x <= 26) {
        dp[i] = dp[i + 1] + dp[i + 2];
      } else {
        dp[i] = dp[i + 1];
      }
    }

    return dp[0];
  }
};
