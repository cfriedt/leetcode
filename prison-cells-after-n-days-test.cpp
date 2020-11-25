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

#include "prison-cells-after-n-days.cpp"

TEST(PrisonCellsAfterNDays, 01011001_7) {
  vector<int> nums = {0, 1, 0, 1, 1, 0, 0, 1};
  int N = 7;
  vector<int> expected = {0, 0, 1, 1, 0, 0, 0, 0};
  vector<int> actual = Solution().prisonAfterNDays(nums, N);
  EXPECT_EQ(actual, expected);
}

TEST(PrisonCellsAfterNDays, 10101010_1) {
  vector<int> nums = {1, 0, 1, 0, 1, 0, 1, 0};
  int N = 1;
  vector<int> expected = {0, 1, 1, 1, 1, 1, 1, 0};
  vector<int> actual = Solution().prisonAfterNDays(nums, N);
  EXPECT_EQ(actual, expected);
}

TEST(PrisonCellsAfterNDays, 10010010_1000000000) {
  vector<int> nums = {1, 0, 0, 1, 0, 0, 1, 0};
  int N = 1000000000;
  vector<int> expected = {0, 0, 1, 1, 1, 1, 1, 0};
  vector<int> actual = Solution().prisonAfterNDays(nums, N);
  EXPECT_EQ(actual, expected);
}
