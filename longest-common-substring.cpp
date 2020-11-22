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

#include <string>

using namespace std;

// sorry, this url actually doesn't exist :(
// https://leetcode.com/problems/longest-common-substring/

// this one might be somewhat similar
// https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
  string longestCommonSubstring(string x, string y) {
    /*
    Similar to the longest common subsequence problem, except this one
    requires that subsequence characters are adjacent to one another
    forming a continuous string.

    Consider when the last characters in the two strings match, i.e. x[m] ==
    y[n]

    LCSuffix(x, m, y, n) = LCSuffix(x, m - 1, y, n - 1) + x[m]

    For example, LCSuffix("a", 1, "a", 1) = LCSuffix("", 0, "", 0) + "a", or
    LCSuffix("abc", 3, "aabc", 4) = LCSuffix("ab", 2, "aab", 3) + "c"
                                  = LCSuffix("a", 1, "aa", 2) + "b" + "c"
                                  = LCSuffix("", 0, "a", 1) + "a" + "b" + "c"
                                  = "" + "a" + "b" + "c"

    However, when the last two characters in the two strings do not match, i.e.
    x[m] != y[n],

    LCSuffix(x, m, y, n) = 0

    and it becomes necessary to check 2 separate paths:
    1) where the last character is discarded from x
    2) where the last character is discarded from y

    For example,
    LCSuffix("a", 1, "b", 1) = max(LCSuffix("", i, "", j)), i in [0, 0], j in
    [0, 0] = "".

    However, a non-trivial example illustrates that this process is O(MN) or
    O(N^2) in both time and space. Using a suffix tree reduces the time
    complexity to O(M + N), and that is why

    E.g. LCSuffix("abab", 4, "baba", 4)

        b a b a
      0 0 0 0 0
    a 0 0 1 0 1
    b 0 1 0 2 0
    a 0 0 2 0 3
    b 0 1 0 3 0

    The best we can do with a DP solution is to take advantage of the optimal
    substructure property to give us the table above. Space complexity can be
    reduced to O(M + N) because we only need the current and previous rows to
    arrive at the correct solution.

    Technically speaking as well, there can be multiple longest common
    substrings, and this algorithm only returns the first of those.

    */
    // build LUT
    const size_t m = x.size();
    const size_t n = y.size();
    int maxlen = 0;
    int endingindex = m;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (size_t i = 1; i <= m; ++i) {
      for (size_t j = 1; j <= n; ++j) {
        if (x[i - 1] == y[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
          // cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
          /* MUST BE >= here for this algorithm to work properly */
          if (dp[i][j] >= maxlen) {
            maxlen = dp[i][j];
            endingindex = i;
            // cout << x.substr(endingindex - maxlen , maxlen) << " maxlen: " <<
            // maxlen << " endingindex: " << endingindex << endl;
          }
        }
      }
    }

    return x.substr(endingindex - maxlen, maxlen);
  }
};
