/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "remove-comments.cpp"

using namespace std;

TEST(RemoveComments, example1) {
  vector<string> source = {"/*Test program */",
                           "int main()",
                           "{ ",
                           "  // variable declaration ",
                           "int a, b, c;",
                           "/* This is a test",
                           "   multiline  ",
                           "   comment for ",
                           "   testing */",
                           "a = b + c;",
                           "}"};

  vector<string> expected = {"int main()",   "{ ",         "  ",
                             "int a, b, c;", "a = b + c;", "}"};
  EXPECT_EQ(expected, Solution().removeComments(source));
}

TEST(RemoveComments, example2) {
  vector<string> source = {"a/*comment", "line", "more_comment*/b"};

  vector<string> expected = {"ab"};
  EXPECT_EQ(expected, Solution().removeComments(source));
}

TEST(RemoveComments, example3) {
  vector<string> source = {"a//*b//*c", "blank", "d/*/e*//f"};

  vector<string> expected = {"a", "blank", "d/f"};
  EXPECT_EQ(expected, Solution().removeComments(source));
}

TEST(RemoveComments, example4) {
  vector<string> source = {"a / /*b// */c"};

  vector<string> expected = {"a / c"};
  EXPECT_EQ(expected, Solution().removeComments(source));
}
