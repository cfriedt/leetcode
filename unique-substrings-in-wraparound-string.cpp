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

#include <algorithm>
#include <numeric>
#include <array>

using namespace std;

// https://leetcode.com/problems/unique-substrings-in-wraparound-string/

class Solution {
public:
  // return the number of unique, non-empty substrings of the string p contained
  // within the "wraparound string" s=..[a-z][a-z][a-z]..
  //
  // we think this is a DP problem. there are 2 main requirements that need to
  // be satisfied if that is true
  // 1. has an optimal substructure
  // 2. has overlapping subproblems (implies recursion)
  //
  // notes:
  // - p can be extremely long (<= 10000 characters)
  // - substrings only need to be characterized by a pair of integers
  // - unique strings can be stored in an unordered_set<string> for O(1)
  // operations
  // - we can list all of the substrings in a binary tree structure with (0,N-1)
  // being the root node
  // - there are nCk + 1 = n!/(k!(n-k)!) + 1 substrings of p, where k = 2
  // (indices) and n = p.size()
  //   i.e. nC2 + 1 = n!/(2!(n-2)!) + 1. So for "zaba", n == 4, and there are
  //   4!/(2!(4-2)!) + 1 = 7 substrings in total but counting all possible
  //   substrings is O(N!) so we obviously want to not do that
  // - a string is a valid substring of s if the following holds
  //   R == L || p[R] - 'a' == (p[R - 1] - 'a' + 1) % 26
  // - the following recursion should hold true, and we can memoize count(i,j)
  //   count(L,R) = isValid(L,R)*isUnique(L,R) + count(L,R-1) + count(L+1,R)
  // - we can only count substrings once (either by reference or by value)

  int findSubstringInWraproundString(string p) {
    // number of valid substrings that end in a given letter of the alphabet
    vector<int> dp(26);
    int x = 0; // number of substrings
    for (size_t i = 0, N = p.size(); i < N; ++i) {
      if (i > 0 && (p[i] - p[i - 1] == 1 || p[i - 1] - p[i] == 25)) {
        ++x;
      } else {
	// either the first character or an invalid substring resets the counter
        x = 1;
      }
      dp[p[i] - 'a'] = max(x, dp[p[i] - 'a']);
    }
    return accumulate(dp.begin(), dp.end(), 0);
  }
};
