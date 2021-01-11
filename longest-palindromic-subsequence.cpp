/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  // https://leetcode.com/problems/longest-palindromic-subsequence
  // https://leetcode.com/problems/longest-palindromic-subsequence/discuss/99151/super-simple-solution-using-reversed-string/238112
  // https://en.wikipedia.org/wiki/Longest_common_subsequence_problem
  // https://en.wikipedia.org/wiki/Longest_common_substring_problem
  // https://en.wikipedia.org/wiki/Longest_palindromic_substring

  int longestPalindromeSubseq(const string &s) {

    // Analysis:
    //
    // The simplest way to check to see if a string is a palindrome
    // is to reverse the string, and perform a standard string comparison.
    //
    // The longest common subsequence algorithm for 2 strings, of length
    // M and N is O( MN ) time and O( MN ) in space using a DP approach.
    //
    // The longest palindromic subsequence problem is reduced to an
    // an application of the LCS algorithm with the original string
    // and it's reverse.
    //
    // This algorithm is therefore O( N^2 ) time and space.

    if (s.empty())
      return 0;

    string x = s;
    string y = x;
    reverse(y.begin(), y.end());

    return lcs(x, y);
  }

protected:
  int lcs(const string &x, const string &y) {

    // LCS( Xi, Yj ) =
    // 1) 0: i == 0 || j == 0
    // 2) LCS( X[i-1], Y[i-1] ) + X[i]
    // 3) max( LCS( X[i-1],Y[i]), LCS( X[i], Y[i-1] ) )
    //
    // Note: the original strings are 1-indexed from
    // 1..m for X and 1..n for Y

    // X = cbbd, Y = dbbc
    // LCS( X[4], Y[4] ) =
    //    = max( LCS( X[3],Y[4] ), LCS( X[4], Y[3] ) )
    //    = max( LCS( cbb, dbbc ), LCS( cbbd, dbb ) )
    //    ..
    //    = max( LCS(c,), LCS(,d) ) + bb
    //    = bb

    // MAJOR PROBLEM with going from i = 1:M, j = 1:N though, as shown on the
    // wikipedia: there is a "sometimes off by 1" error!! Rather than try to
    // find the strange corner-case that fixes the off-by-one error, going from
    // i=M:1, j=N:1 seems to avoid it altogether.

    const size_t M = x.size();
    const size_t N = y.size();

    vector<vector<int>> dp(M + 1, vector<int>(N + 1));

    for (size_t i = 0; i <= M; i++) {
      dp[i][N] = 0;
    }
    for (size_t j = 0; j <= N; j++) {
      dp[M][j] = 0;
    }

    for (size_t i = M - 1; i != size_t(-1); i--) {
      for (size_t j = N - 1; j != size_t(-1); j--) {

        if (x[i] == y[j]) {

          // e.g. LCS( a, a ) = LCS( , ) + ""
          // e.g. LCS( ba, ca ) = LCS( b, c ) + a

          dp[i][j] = 1 + dp[i + 1][j + 1];
        } else {

          // e.g. LCS( b, c ) = max( LCS(b,), LCS(,c) ) = 0
          // e.g. LCS( ab, ac ) = max( LCS( ab, a ), LCS( a, ac ) )
          //                    = max( max( LCS( a, a ), LCS( ab, ) ), max( LCS(
          //                    a, a ), LCS( ,ac ) ) )

          dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
        }
      }
    }

    return dp[0][0];
  }
};
