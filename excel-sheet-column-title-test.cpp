/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "excel-sheet-column-title.cpp"

using namespace std;

TEST(ExcelSheeColumnTitle, 1) { EXPECT_EQ("A", Solution().convertToTitle(1)); }

TEST(ExcelSheeColumnTitle, 28) {
  EXPECT_EQ("AB", Solution().convertToTitle(28));
}
