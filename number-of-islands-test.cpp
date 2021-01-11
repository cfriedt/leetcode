/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "number-of-islands.cpp"

static void fixup(vector<vector<char>> &grid) {
  for (auto &row : grid) {
    for (auto &col : row) {
      if ('1' != col) {
        col = '0';
      }
    }
  }
}

TEST(NumberOfIslands, Test_example1) {
  vector<vector<char>> grid{
      {'1', '1', '1', '1', ' '},
      {'1', '1', ' ', '1', ' '},
      {'1', '1', ' ', ' ', ' '},
      {' ', ' ', ' ', ' ', ' '},
  };
  fixup(grid);
  int expected_int = 1;
  int actual_int = Solution().numIslands(grid);
  EXPECT_EQ(actual_int, expected_int);
}

TEST(NumberOfIslands, Test_example2) {
  vector<vector<char>> grid{
      {'1', '1', ' ', ' ', ' '},
      {'1', '1', ' ', ' ', ' '},
      {' ', ' ', '1', ' ', ' '},
      {' ', ' ', ' ', '1', '1'},
  };
  fixup(grid);
  int expected_int = 3;
  int actual_int = Solution().numIslands(grid);
  EXPECT_EQ(actual_int, expected_int);
}

TEST(NumberOfIslands, Test_donut) {
  vector<vector<char>> grid{
      {' ', '1', '1', '1', ' '},
      {' ', '1', ' ', '1', ' '},
      {' ', '1', '1', '1', ' '},
  };
  fixup(grid);
  int expected_int = 1;
  int actual_int = Solution().numIslands(grid);
  EXPECT_EQ(actual_int, expected_int);
}

TEST(NumberOfIslands, Test_c) {
  vector<vector<char>> grid{
      {' ', '1', '1', '1', ' '},
      {' ', '1', ' ', ' ', ' '},
      {' ', '1', '1', '1', ' '},
  };
  fixup(grid);
  int expected_int = 1;
  int actual_int = Solution().numIslands(grid);
  EXPECT_EQ(actual_int, expected_int);
}

TEST(NumberOfIslands, Test_mirror_c) {
  vector<vector<char>> grid{
      {' ', '1', '1', '1', ' '},
      {' ', ' ', ' ', '1', ' '},
      {' ', '1', '1', '1', ' '},
  };
  fixup(grid);
  int expected_int = 1;
  int actual_int = Solution().numIslands(grid);
  EXPECT_EQ(actual_int, expected_int);
}

TEST(NumberOfIslands, Test_u_umlaut) {
  vector<vector<char>> grid{
      {' ', '1', ' ', '1', ' '}, {' ', ' ', ' ', ' ', ' '},
      {' ', '1', ' ', '1', ' '}, {' ', '1', ' ', '1', ' '},
      {' ', '1', '1', '1', ' '},
  };
  fixup(grid);
  int expected_int = 3;
  int actual_int = Solution().numIslands(grid);
  EXPECT_EQ(actual_int, expected_int);
}

TEST(NumberOfIslands, Test_x) {
  vector<vector<char>> grid{
      {'1', ' ', ' ', ' ', '1'}, {' ', '1', ' ', '1', ' '},
      {' ', ' ', '1', ' ', ' '}, {' ', '1', ' ', '1', ' '},
      {'1', ' ', ' ', ' ', '1'},
  };
  fixup(grid);
  int expected_int = 9;
  int actual_int = Solution().numIslands(grid);
  EXPECT_EQ(actual_int, expected_int);
}

TEST(NumberOfIslands, Test_snek) {
  vector<vector<char>> grid{
      {' ', '1', '1', '1', '1'}, {' ', ' ', ' ', ' ', '1'},
      {'1', '1', '1', ' ', '1'}, {'1', ' ', ' ', ' ', '1'},
      {'1', '1', '1', '1', '1'},
  };
  fixup(grid);
  int expected_int = 1;
  int actual_int = Solution().numIslands(grid);
  EXPECT_EQ(actual_int, expected_int);
}

TEST(NumberOfIslands, Test_great_big_sea) {
  vector<vector<char>> grid{
      {' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' '},
      {' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' '},
      {' ', ' ', ' ', ' ', ' '},
  };
  fixup(grid);
  int expected_int = 0;
  int actual_int = Solution().numIslands(grid);
  EXPECT_EQ(actual_int, expected_int);
}

TEST(NumberOfIslands, Test_empty) {
  vector<vector<char>> grid;
  fixup(grid);
  int expected_int = 0;
  int actual_int = Solution().numIslands(grid);
  EXPECT_EQ(actual_int, expected_int);
}

TEST(NumberOfIslands, Test_noColumns) {
  vector<vector<char>> grid(500, vector<char>());
  fixup(grid);
  int expected_int = 0;
  int actual_int = Solution().numIslands(grid);
  EXPECT_EQ(actual_int, expected_int);
}

TEST(NumberOfIslands, Test_vzigzag) {
  vector<vector<char>> grid{
      {'1', '1', '1', '1', '1'}, {' ', ' ', ' ', ' ', '1'},
      {'1', '1', '1', '1', '1'}, {'1', ' ', ' ', ' ', ' '},
      {'1', '1', '1', '1', '1'},
  };
  fixup(grid);
  int expected_int = 1;
  int actual_int = Solution().numIslands(grid);
  EXPECT_EQ(actual_int, expected_int);
}

TEST(NumberOfIslands, Test_hzigzag) {
  vector<vector<char>> grid{
      {'1', ' ', '1', '1', '1'}, {'1', ' ', '1', ' ', '1'},
      {'1', ' ', '1', ' ', '1'}, {'1', ' ', '1', ' ', '1'},
      {'1', '1', '1', ' ', '1'},
  };
  fixup(grid);
  int expected_int = 1;
  int actual_int = Solution().numIslands(grid);
  EXPECT_EQ(actual_int, expected_int);
}

// currently not considering "lakes"
TEST(NumberOfIslands, Test_fillIslandTest) {
  vector<vector<char>> grid{
      {'1', '1', '1', '1', ' ', ' '}, {' ', '1', ' ', '1', ' ', ' '},
      {'1', '1', '1', '1', '1', '1'}, {'1', ' ', ' ', '1', ' ', '1'},
      {'1', ' ', ' ', '1', '1', '1'}, {'1', '1', '1', '1', ' ', '1'},
  };
  fixup(grid);
  int expected_int = 1;
  int actual_int = Solution().numIslands(grid);
  EXPECT_EQ(actual_int, expected_int);
}

// what about an island within an island???

TEST(NumberOfIslands, Test_recursion) {
  vector<vector<char>> grid{
      {'1', '1', '1', '1', '1', '1'}, {'1', ' ', ' ', ' ', ' ', '1'},
      {'1', ' ', '1', '1', ' ', '1'}, {'1', ' ', ' ', ' ', ' ', '1'},
      {'1', '1', '1', ' ', '1', '1'},
  };
  fixup(grid);
  int expected_int = 2;
  int actual_int = Solution().numIslands(grid);
  EXPECT_EQ(actual_int, expected_int);
}

TEST(NumberOfIslands, Test_islandWithinIsland) {
  vector<vector<char>> grid{
      {'1', '1', '1', '1', '1'}, {'1', ' ', ' ', ' ', '1'},
      {'1', ' ', '1', ' ', '1'}, {'1', ' ', ' ', ' ', '1'},
      {'1', '1', '1', '1', '1'},
  };
  fixup(grid);
  int expected_int = 2;
  int actual_int = Solution().numIslands(grid);
  EXPECT_EQ(actual_int, expected_int);
}

TEST(NumberOfIslands, Test_islandWithinIslandWithDiag) {
  vector<vector<char>> grid{
      {'1', '1', '1', '1', '1'}, {'1', ' ', ' ', ' ', '1'},
      {'1', ' ', '1', ' ', '1'}, {'1', ' ', ' ', '1', '1'},
      {'1', '1', '1', '1', '1'},
  };
  fixup(grid);
  int expected_int = 2;
  int actual_int = Solution().numIslands(grid);
  EXPECT_EQ(actual_int, expected_int);
}

TEST(NumberOfIslands, Test_perimeterShouldOnlyInclude2AroundCorners) {
  vector<vector<char>> grid{
      {'1', ' ', ' ', ' '}, {'1', '1', '1', ' '}, {'1', ' ', '1', ' '},
      {'1', ' ', '1', '1'}, {'1', ' ', '1', ' '}, {' ', '1', '1', ' '},
      {'1', '1', ' ', ' '},
  };
  fixup(grid);
  int expected_int = 1;
  int actual_int = Solution().numIslands(grid);
  EXPECT_EQ(actual_int, expected_int);
}

TEST(NumberOfIslands, Test_big) {
  vector<vector<char>> grid{
      {'1', ' ', ' ', '1', '1', '1', ' ', '1', '1', ' ',
       ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {'1', ' ', ' ', '1', '1', ' ', ' ', '1', ' ', ' ',
       ' ', '1', ' ', '1', ' ', '1', ' ', ' ', '1', ' '},
      {' ', ' ', ' ', '1', '1', '1', '1', ' ', '1', ' ',
       '1', '1', ' ', ' ', ' ', ' ', '1', ' ', '1', ' '},
      {' ', ' ', ' ', '1', '1', ' ', ' ', '1', ' ', ' ',
       ' ', '1', '1', '1', ' ', ' ', '1', ' ', ' ', '1'},
      {' ', ' ', ' ', ' ', ' ', ' ', ' ', '1', '1', '1',
       ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {'1', ' ', ' ', ' ', ' ', '1', ' ', '1', ' ', '1',
       '1', ' ', ' ', ' ', ' ', ' ', ' ', '1', ' ', '1'},
      {' ', ' ', ' ', '1', ' ', ' ', ' ', '1', ' ', '1',
       ' ', '1', ' ', '1', ' ', '1', ' ', '1', ' ', '1'},
      {' ', ' ', ' ', '1', ' ', '1', ' ', ' ', '1', '1',
       ' ', '1', ' ', '1', '1', ' ', '1', '1', '1', ' '},
      {' ', ' ', ' ', ' ', '1', ' ', ' ', '1', '1', ' ',
       ' ', ' ', ' ', '1', ' ', ' ', ' ', '1', ' ', '1'},
      {' ', ' ', '1', ' ', ' ', '1', ' ', ' ', ' ', ' ',
       ' ', '1', ' ', ' ', '1', ' ', ' ', ' ', '1', ' '},
      {'1', ' ', ' ', '1', ' ', ' ', ' ', ' ', ' ', ' ',
       ' ', '1', ' ', ' ', '1', ' ', '1', ' ', '1', ' '},
      {' ', '1', ' ', ' ', ' ', '1', ' ', '1', ' ', '1',
       '1', ' ', '1', '1', '1', ' ', '1', '1', ' ', ' '},
      {'1', '1', ' ', '1', ' ', ' ', ' ', ' ', '1', ' ',
       ' ', ' ', ' ', ' ', ' ', '1', ' ', ' ', ' ', '1'},
      {' ', '1', ' ', ' ', '1', '1', '1', ' ', ' ', ' ',
       '1', '1', '1', '1', '1', ' ', '1', ' ', ' ', ' '},
      {' ', ' ', '1', '1', '1', ' ', ' ', ' ', '1', '1',
       ' ', ' ', ' ', '1', ' ', '1', ' ', ' ', ' ', ' '},
      {'1', ' ', ' ', '1', ' ', '1', ' ', ' ', ' ', ' ',
       '1', ' ', ' ', ' ', '1', ' ', '1', ' ', '1', '1'},
      {'1', ' ', '1', ' ', ' ', ' ', ' ', ' ', ' ', '1',
       ' ', ' ', ' ', '1', ' ', '1', ' ', ' ', ' ', ' '},
      {' ', '1', '1', ' ', ' ', ' ', '1', '1', '1', ' ',
       '1', ' ', '1', ' ', '1', '1', '1', '1', ' ', ' '},
      {' ', '1', ' ', ' ', ' ', ' ', '1', '1', ' ', ' ',
       '1', ' ', '1', ' ', ' ', '1', ' ', ' ', '1', '1'},
      {' ', ' ', ' ', ' ', ' ', ' ', '1', '1', '1', '1',
       ' ', '1', ' ', ' ', ' ', '1', '1', ' ', ' ', ' '},
  };
  fixup(grid);
  int expected_int = 58;
  int actual_int = Solution().numIslands(grid);
  EXPECT_EQ(actual_int, expected_int);
}
