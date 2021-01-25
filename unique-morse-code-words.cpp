/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

// clang-format off
// name: unique-morse-code-words
// url: https://leetcode.com/problems/unique-morse-code-words
// difficulty: 1
// clang-format on

#include <array>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int uniqueMorseRepresentations(vector<string> &words) {
    static const array<string, 26> alphabet = {
        ".-",   "-...", "-.-.", "-..",  ".",   "..-.", "--.",  "....", "..",
        ".---", "-.-",  ".-..", "--",   "-.",  "---",  ".--.", "--.-", ".-.",
        "...",  "-",    "..-",  "...-", ".--", "-..-", "-.--", "--.."};

    unordered_set<string> xforms;
    for (auto &w : words) {
      string s;
      for (auto c : w) {
        s += alphabet[c - 'a'];
      }
      xforms.insert(s);
    }

    return xforms.size();
  }
};
