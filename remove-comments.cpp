/*
 * Copyright (c) 2020 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> removeComments(vector<string> &source) {
    vector<string> out;
    string orphan;
    bool in_block = false;

    for (auto &s : source) {
      size_t i = 0;

      if (in_block) {
        size_t pos2 = s.find("*/");
        if (string::npos == pos2) {
          continue;
        }

        s.erase(0, pos2 + 2);
        s = orphan + s;
        in_block = false;
        i = orphan.size();
      }

      for (; i < s.size();) {
        size_t pos = s.find("/", i);
        if (pos == string::npos) {
          break;
        }

        if (s[pos + 1] != '/' && s[pos + 1] != '*') {
          i = pos + 2;
          continue;
        }

        if (s[pos + 1] == '/') {
          s.erase(pos);
          break;
        }

        if (s[pos + 1] != '*') {
          i = pos + 2;
          continue;
        }

        size_t pos2 = s.find("*/", pos + 2);
        if (string::npos == pos2) {
          s.erase(pos);
          orphan = s;
          in_block = true;
          break;
        }

        s.erase(pos, pos2 - pos + 2);
        i = pos;
      }

      if (!s.empty() && !in_block) {
        out.push_back(s);
      }
    }

    return out;
  }
};
