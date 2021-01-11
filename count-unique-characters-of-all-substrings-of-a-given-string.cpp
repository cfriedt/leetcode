/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// clang-format off
// name: count-unique-characters-of-all-substrings-of-a-given-string
// url: https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string
// difficulty: 3
// clang-format on

// static vector<string> msgs;

class Solution {
public:
  using dp1_t = vector<vector<size_t>>;
  using dp2_t = vector<vector<vector<size_t>>>;

  int uniqueLetterString(string s) {

    const size_t N = s.size();
    dp1_t dp1 = dp1_t(N, vector<size_t>(N, -1));
    dp2_t dp2 = dp2_t(N, dp1_t(N, vector<size_t>(26, -1)));

    // for string s, with indices L, R where L <= R
    // UC(s,L,R) =               1, if L == R
    //           = UC(s,L,R-1) + 1, count(s,L,R-1,s[R]) == 0
    //           = UC(s,L,R-1) - 1, count(s,L,R-1,s[R]) == 1
    //           = UC(s,L,R-1)    , otherwise
    //
    // count(s,L,R,c) = count(s,L,R-1,c) + 1, c == s[R]
    //                = count(s,L,R-1,c)    , c != s[R]
    //                =                    1, L == R AND s[L] == c
    //                =                    0, L == R AND s[L] != c

    size_t num = 0;
    for (size_t L = 0, N = s.size(); L < N; ++L) {
      for (size_t R = N; R > L; --R) {
        num += UC(dp1, dp2, s, L, R - 1);
      }
    }

    //    for(auto& m: msgs) {
    //    	cout << m << endl;
    //    }

    return num;
  }

  static size_t count(dp2_t &dp2, const string &s, size_t L, size_t R, char c) {
    auto &n = dp2[L][R][c - 'A'];
    if (n != size_t(-1)) {
      return n;
    }

    if (L == R) {
      n = s[L] == c;
      // msgs.push_back("count(" + s.substr(L, R - L + 1) + ", " + string(1,c) +
      // "): " + to_string(n));
      return n;
    }

    auto m = count(dp2, s, L, R - 1, c);
    if (s[R] == c) {
      m++;
    }

    n = m;
    // msgs.push_back("count(" + s.substr(L, R - L + 1) + ", " + string(1,c) +
    // "): " + to_string(n));
    return n;
  }

  static size_t UC(dp1_t &dp1, dp2_t &dp2, const string &s, size_t L,
                   size_t R) {

    auto &n = dp1[L][R];
    if (n != size_t(-1)) {
      return n;
    }

    if (L == R) {
      n = 1;
      // msgs.push_back("UC(" + s.substr(L, R - L + 1) + "): " + to_string(n));
      return n;
    }

    n = UC(dp1, dp2, s, L, R - 1);
    auto m = count(dp2, s, L, R - 1, s[R]);

    switch (m) {
    case 0:
      ++n;
      break;
    case 1:
      --n;
      break;
    default:
      break;
    }

    ++m;
    dp2[L][R][s[R] - 'A'] = m;

    // msgs.push_back("UC(" + s.substr(L, R - L + 1) + "): " + to_string(n));
    return n;
  }
};
