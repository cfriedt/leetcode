/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "valid-parentheses.cpp"

// ro / rc = round open / round close
// co / cc = curly open / curly close
// so / sc = square open / square close

TEST(ValidParentheses, Test_) {
  string s;
  bool expected_bool(true);
  bool actual_bool = Solution().isValid(s);
  EXPECT_EQ(actual_bool, expected_bool);
}

TEST(ValidParentheses, Test_ro_rc) {
  string s("()");
  bool expected_bool(true);
  bool actual_bool = Solution().isValid(s);
  EXPECT_EQ(actual_bool, expected_bool);
}

TEST(ValidParentheses, Test_ro_rc_so_sc_co_cc) {
  string s("()[]{}");
  bool expected_bool(true);
  bool actual_bool = Solution().isValid(s);
  EXPECT_EQ(actual_bool, expected_bool);
}

TEST(ValidParentheses, Test_ro_sc) {
  string s("(]");
  bool expected_bool(false);
  bool actual_bool = Solution().isValid(s);
  EXPECT_EQ(actual_bool, expected_bool);
}

TEST(ValidParentheses, Test_ro_so_rc_sc) {
  string s("([)]");
  bool expected_bool(false);
  bool actual_bool = Solution().isValid(s);
  EXPECT_EQ(actual_bool, expected_bool);
}

TEST(ValidParentheses, Test_co_so_sc_cc) {
  string s("{[]}");
  bool expected_bool(true);
  bool actual_bool = Solution().isValid(s);
  EXPECT_EQ(actual_bool, expected_bool);
}

TEST(ValidParentheses, Test_co) {
  string s("(");
  bool expected_bool(false);
  bool actual_bool = Solution().isValid(s);
  EXPECT_EQ(actual_bool, expected_bool);
}
