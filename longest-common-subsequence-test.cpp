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

#include "longest-common-subsequence.cpp"

TEST(LongestCommonSubsequence, abcde_ace) {
  EXPECT_EQ(3, Solution().longestCommonSubsequence("abcde", "ace"));
}

TEST(LongestCommonSubsequence, abc_abc) {
  EXPECT_EQ(3, Solution().longestCommonSubsequence("abc", "abc"));
}

TEST(LongestCommonSubsequence, abc_def) {
  EXPECT_EQ(0, Solution().longestCommonSubsequence("abc", "def"));
}

TEST(LongestCommonSubsequence, pmjghexybyrgzczy_hafcdqbgncrcbihkd) {
  EXPECT_EQ(4, Solution().longestCommonSubsequence("pmjghexybyrgzczy",
                                                   "hafcdqbgncrcbihkd"));
}
