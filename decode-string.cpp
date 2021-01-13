/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

// clang-format off
// name: decode-string
// url: https://leetcode.com/problems/decode-string
// difficulty: 2
// clang-format on

#include <vector>

using namespace std;

class Solution {
public:
  string decodeString(string s) {
    // maintain stacks (lifo queues) for both lefts and rights
    // it takes O(N) time to go through s and populate them

    // possible optimization:
    // technically speaking, there can be maximally N/4 lefts and N/4 rights
    // so maybe it just makes sense to preallocate that amount and keep
    // an L and R handy.
    // the question says that s will be maximally 30 characters.
    // so that would allow us to be O(1) space (except for the output
    // which is proportional in length to the input, so O(N)).

    stringstream ss;
    vector<size_t> nums;
    uint8_t lefts = 0;
    vector<string> strs;
    string num;
    bool have_number = false;

    for (size_t i = 0, N = s.size(); i < N; ++i) {
      if ('[' == s[i]) {
        // we can now parse the number string that precedes the '[' character
        nums.push_back(stoi(num));
        num.clear();
        ++lefts;
        strs.push_back("");

      } else if (']' == s[i]) {

        auto j = nums.back();
        string t = strs.back();

        nums.pop_back();
        lefts--;
        strs.pop_back();

        if (nums.size() > 0) {
          for (; j > 0; --j) {
            strs.back() += t;
          }
        } else {
          for (; j > 0; --j) {
            ss << t;
          }
        }

      } else if ('0' <= s[i] && s[i] <= '9') {
        have_number = true;
        num.push_back(s[i]);
      } else if ('a' <= s[i] && s[i] <= 'z') {
        if (!have_number || lefts == 0) {
          ss << s[i];
        } else {
          strs.back().push_back(s[i]);
        }
      }
    }

    return ss.str();
  }
};
