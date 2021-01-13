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

#include "roman-to-integer.cpp"

TEST(RomanToInteger, II) { EXPECT_EQ(2, Solution().romanToInt("II")); }
TEST(RomanToInteger, XII) { EXPECT_EQ(12, Solution().romanToInt("XII")); }
TEST(RomanToInteger, XXVII) { EXPECT_EQ(27, Solution().romanToInt("XXVII")); }
TEST(RomanToInteger, IV) { EXPECT_EQ(4, Solution().romanToInt("IV")); }
TEST(RomanToInteger, IX) { EXPECT_EQ(9, Solution().romanToInt("IX")); }
TEST(RomanToInteger, DCXXI) { EXPECT_EQ(621, Solution().romanToInt("DCXXI")); }
TEST(RomanToInteger, MCMXCIV) {
  EXPECT_EQ(1994, Solution().romanToInt("MCMXCIV"));
}
