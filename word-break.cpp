/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

// https://leetcode.com/problems/word-break/
// https://leetcode.com/problems/word-break/discuss/43814/C%2B%2B-Dynamic-Programming-simple-and-fast-solution-(4ms)-with-optimization

#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  bool wordBreak(const string &s, const vector<string> &wordDict) {
    unordered_set<string> wd(wordDict.begin(), wordDict.end());
    return wordBreak(s, wd);
  }

protected:
  bool wordBreak(const string &s, const unordered_set<string> &wordDict) {
    if (wordDict.size() == 0)
      return false;

    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;

    for (int i = 1; i <= int(s.size()); i++) {
      for (int j = i - 1; j >= 0; j--) {
        if (dp[j]) {
          string word = s.substr(j, i - j);
          if (wordDict.find(word) != wordDict.end()) {
            dp[i] = true;
            break; // next i
          }
        }
      }
    }

    return dp[s.size()];
  }
};
