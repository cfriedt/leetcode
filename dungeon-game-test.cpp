/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "dungeon-game.cpp"

TEST(DungeonGame, Test_n2_n3_3__n5_n10_1__10_30_n5) {
  vector<vector<int>> dungeon({{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}});
  int expected_int = 7;
  int actual_int = Solution().calculateMinimumHP(dungeon);
  EXPECT_EQ(actual_int, expected_int);
}

// this is a good test, because the net HP is positive, but if we
// don't have sufficient HP to withstand the first attack (i.e. an HP of
// at least 16, then we die.
TEST(DungeonGame, Test_n15_15_1) {
  vector<vector<int>> dungeon({{-15, 15, 1}});
  int expected_int = 16;
  int actual_int = Solution().calculateMinimumHP(dungeon);
  EXPECT_EQ(actual_int, expected_int);
}

TEST(DungeonGame, Test_1_1_1) {
  vector<vector<int>> dungeon({{1, 1, 1}});
  int expected_int = 1;
  int actual_int = Solution().calculateMinimumHP(dungeon);
  EXPECT_EQ(actual_int, expected_int);
}

// this is a good test, because the net is positive, but we need to not only
// withstand the first attack, but subsequent attacks as well.
TEST(DungeonGame, Test_n7_n15_7_15_1) {
  vector<vector<int>> dungeon({{-7, -15, 7, 15, 1}});
  int expected_int = 23;
  int actual_int = Solution().calculateMinimumHP(dungeon);
  EXPECT_EQ(actual_int, expected_int);
}

// this is a good test, because the net is zero, but we still need to
// account for withstanding attacks
TEST(DungeonGame, Test_n1_1_n1_1) {
  vector<vector<int>> dungeon({{-1, 1, -1, 1}});
  int expected_int = 2;
  int actual_int = Solution().calculateMinimumHP(dungeon);
  EXPECT_EQ(actual_int, expected_int);
}

// this is a good test, because the net is zero, and all effects are zero.
TEST(DungeonGame, Test_0_0) {
  vector<vector<int>> dungeon({{0, 0}});
  int expected_int = 1;
  int actual_int = Solution().calculateMinimumHP(dungeon);
  EXPECT_EQ(actual_int, expected_int);
}

// this is a good test, because the net is zero, and all effects are zero.
TEST(DungeonGame, Test_nil) {
  vector<vector<int>> dungeon;
  int expected_int = 1;
  int actual_int = Solution().calculateMinimumHP(dungeon);
  EXPECT_EQ(actual_int, expected_int);
}

// this is a good test, because the net is zero, and all effects are zero.
TEST(DungeonGame, Test_0_5__n2_n3) {
  vector<vector<int>> dungeon({{0, 5}, {-2, -3}});
  int expected_int = 1;
  int actual_int = Solution().calculateMinimumHP(dungeon);
  EXPECT_EQ(actual_int, expected_int);
}
