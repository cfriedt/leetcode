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

#include <gtest/gtest.h>

#include "split-a-string-in-balanced-strings.cpp"

TEST(SplitAStringInBalancedStrings, Test_RLRRLLRLRL) {
  string input = "RLRRLLRLRL";
  vector<string> expected_vs = {
      "RL",
      "RRLL",
      "RL",
      "RL",
  };
  int expected_int = expected_vs.size();
  int actual_int = Solution().balancedStringSplit(input);
  EXPECT_EQ(actual_int, expected_int);
}

TEST(SplitAStringInBalancedStrings, Test_RLLLLRRRLR) {
  string input = "RLLLLRRRLR";
  vector<string> expected_vs = {
      "RL",
      "LLLRRR",
      "LR",
  };
  int expected_int = expected_vs.size();
  int actual_int = Solution().balancedStringSplit(input);
  EXPECT_EQ(actual_int, expected_int);
}

TEST(SplitAStringInBalancedStrings, Test_LLLLRRRR) {
  string input = "LLLLRRRR";
  vector<string> expected_vs = {
      "LLLLRRRR",
  };
  int expected_int = expected_vs.size();
  int actual_int = Solution().balancedStringSplit(input);
  EXPECT_EQ(actual_int, expected_int);
}

TEST(SplitAStringInBalancedStrings, Test_RLRRRLLRLL) {
  string input = "RLRRRLLRLL";
  vector<string> expected_vs = {
      "RL",
      "RRRLLRLL",
  };
  int expected_int = expected_vs.size();
  int actual_int = Solution().balancedStringSplit(input);
  EXPECT_EQ(actual_int, expected_int);
}
