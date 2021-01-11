/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  // https://leetcode.com/problems/valid-parentheses/

  static inline bool is_opening(char c) {
    return '(' == c || '{' == c || '[' == c;
  }

  static inline bool matches(char opening, char closing) {
    return false || (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
  }

  bool isValid(string s) {

    // This is an easy question which I probably should have skipped.
    //
    // Using a stack to balance tags / parentheses, whatever, not on tonight's
    // news at 6.
    //
    // Analysis:
    //
    // time: O( N )
    // space: O( N )

    vector<char> stack;

    for (auto &c : s) {
      if (is_opening(c)) {
        stack.push_back(c);
      } else {
        if (stack.empty() || !matches(stack.back(), c)) {
          return false;
        }
        stack.pop_back();
      }
    }

    return stack.empty();
  }
};
