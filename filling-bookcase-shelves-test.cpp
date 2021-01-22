/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "filling-bookcase-shelves.cpp"

using namespace std;

TEST(FillingBookcaseShelves, 1_1_2_3_2_3_1_1_1_1_1_1_1_2__4) {
  vector<vector<int>> books = {{1, 1}, {2, 3}, {2, 3}, {1, 1},
                               {1, 1}, {1, 1}, {1, 2}};
  int shelf_width = 4;
  int expected = 6;
  EXPECT_EQ(expected, Solution().minHeightShelves(books, shelf_width));
}

TEST(FillingBookcaseShelves, 1_3_2_4_3_2__6) {
  vector<vector<int>> books = {{1, 3}, {2, 4}, {3, 2}};
  int shelf_width = 6;
  int expected = 4;
  EXPECT_EQ(expected, Solution().minHeightShelves(books, shelf_width));
}

TEST(FillingBookcaseShelves, 7_3_8_7_2_7_2_5__10) {
  vector<vector<int>> books = {{7,3},{8,7},{2,7},{2,5}};
  int shelf_width = 10;
  int expected = 15;
  EXPECT_EQ(expected, Solution().minHeightShelves(books, shelf_width));
}
