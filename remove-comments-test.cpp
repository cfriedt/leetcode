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
