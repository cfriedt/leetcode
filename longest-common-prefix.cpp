/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  // https://leetcode.com/problems/longest-common-prefix/

  string longestCommonPrefix(vector<string> &strs) {

    if (0 == strs.size()) {
      return "";
    }
    size_t i;
    for (i = 0;; i++) {
      unordered_set<char> c;

      for (size_t j = 0; j < strs.size(); j++) {
        if (i >= strs[j].length()) {
          c.insert(char(-1));
          break;
        }
        c.insert(strs[j][i]);
        if (c.size() > 1) {
          break;
        }
      }

      if (c.size() > 1 || c.end() != c.find(-1)) {
        break;
      }
    }

    return strs[0].substr(0, i);
  }
};
