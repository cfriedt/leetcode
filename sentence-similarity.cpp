/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// https://leetcode.com/problems/sentence-similarity/

class Solution {
public:
  using ums = unordered_map<string, unordered_set<string>>;

  bool areSentencesSimilar(vector<string> &words1, vector<string> &words2,
                           vector<vector<string>> &pairs) {

    if (words1.size() != words2.size()) {
      return false;
    }

    ums to;

    for (auto &p : pairs) {
      if (p[0] == p[1]) {
        continue;
      }
      to[p[0]].insert(p[1]);
      to[p[1]].insert(p[0]);
    }

    for (size_t i = 0, N = words1.size(); i < N; ++i) {
      if (!similar(words1[i], words2[i], to)) {
        return false;
      }
    }

    return true;
  }

  bool similar(const string &w1, const string &w2, const ums &to) {
    if (w1 == w2) {
      return true;
    }

    if (directMapping(w1, w2, to)) {
      return true;
    }

    return false;
  }

  bool directMapping(const string &w1, const string &w2, const ums &to) {
    auto it1 = to.find(w1);

    if (to.end() == it1) {
      return false;
    }

    for (auto &s1 : it1->second) {
      if (w2 == s1) {
        return true;
      }
    }

    return false;
  }
};
