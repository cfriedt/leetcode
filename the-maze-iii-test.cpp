/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "the-maze-iii.cpp"

TEST(TheMazeIii, Test_lul) {
  vector<vector<int>> maze({
      {0, 0, 0, 0, 0},
      {1, 1, 0, 0, 1},
      {0, 0, 0, 0, 0},
      {0, 1, 0, 0, 1},
      {0, 1, 0, 0, 0},
  });
  vector<int> ball({4, 3});
  vector<int> hole({0, 1});

  string expected_string = "lul";
  string actual_string = Solution().findShortestWay(maze, ball, hole);

  EXPECT_EQ(actual_string, expected_string);
}

// UGH - this question is brutal!!!
// Need to throw in another check to see if
// there is a wall whenever changing directions!!!
TEST(TheMazeIii, Test_impossible) {
  vector<vector<int>> maze({
      {0, 0, 0, 0, 0},
      {1, 1, 0, 0, 1},
      {0, 0, 0, 0, 0},
      {0, 1, 0, 0, 1},
      {0, 1, 0, 0, 0},
  });
  vector<int> ball({4, 3});
  vector<int> hole({3, 0});

  string expected_string = "impossible";
  string actual_string = Solution().findShortestWay(maze, ball, hole);

  EXPECT_EQ(actual_string, expected_string);
}

// this one has a cycle in one of the possible paths
TEST(TheMazeIii, Test_r) {
  vector<vector<int>> maze({
      {0, 0, 1, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 1, 0},
      {1, 1, 0, 1, 1},
      {0, 0, 0, 0, 0},
  });
  vector<int> ball({1, 1});
  vector<int> hole({1, 2});

  string expected_string = "r";
  string actual_string = Solution().findShortestWay(maze, ball, hole);

  EXPECT_EQ(actual_string, expected_string);
}

// AUGAAHHGGHH!!! This is nuts!
// So the problem here, is likely that you *can* have a kind of cycle - the kind
// where you arrive at the same path space with a different direction!!!!
// So I need to change BreadCrumbs to be a pair<Node*,int> (int is a direction).
TEST(TheMazeIii, Test_cycle_with_different_dir) {
  vector<vector<int>> maze({
      {0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
      {0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0},
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 1},
      {1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1},
      {0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0},
      {0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0},
  });
  vector<int> ball({0, 4});
  vector<int> hole({1, 6});

  string expected_string = "rdluldrdrurdru";
  string actual_string = Solution().findShortestWay(maze, ball, hole);

  EXPECT_EQ(actual_string, expected_string);
}

TEST(TheMazeIii, Test_paths_that_cross) {
  vector<vector<int>> maze({
      {0, 1, 0, 0, 0},
      {0, 1, 0, 1, 0},
      {0, 0, 0, 0, 0},
      {1, 1, 0, 1, 1},
      {1, 1, 0, 1, 1},
  });
  vector<int> ball({4, 2});
  vector<int> hole({0, 0});

  string expected_string = "urdlu";
  string actual_string = Solution().findShortestWay(maze, ball, hole);

  EXPECT_EQ(actual_string, expected_string);
}

TEST(TheMazeIii, Test_naiive_dfs_will_not_cut_it) {
  vector<vector<int>> maze({
      {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0,
       0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
      {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0,
       0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
      {0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0,
       1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
      {1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0,
       1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
      {0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0,
       0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
      {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1,
       0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0,
       1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
      {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
       1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
      {0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
       0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1,
       0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
      {0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0,
       0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
      {1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0,
       1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
       0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
      {0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0,
       0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
      {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
       0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
      {1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
       0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
      {0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0,
       0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0},
      {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1,
       0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0,
       0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
      {1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0,
       0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0,
       0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0},
      {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1,
       0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
      {0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0,
       0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
      {1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0,
       1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
      {0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0,
       0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0},
      {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0,
       0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
      {0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0,
       1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
      {1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
       0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
      {0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0,
       0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0},
      {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0,
       0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
  });
  vector<int> ball({4, 3});
  vector<int> hole({10, 27});

  string expected_string = "drdrdrdrdrdru";
  string actual_string = Solution().findShortestWay(maze, ball, hole);

  EXPECT_EQ(actual_string, expected_string);
}

/*
TEST( TheMazeIii, Test_size_zero ) {
        vector<vector<int>> maze;
        vector<int> ball;
        vector<int> hole;

        string expected_string = "impossible";
        string actual_string = Solution().findShortestWay(maze, ball, hole);

        EXPECT_EQ(actual_string, expected_string);
}

TEST( TheMazeIii, Test_size_one ) {
        vector<vector<int>> maze({{0}});
        vector<int> ball({0,0});
        vector<int> hole({0,0});

        string expected_string = "";
        string actual_string = Solution().findShortestWay(maze, ball, hole);

        EXPECT_EQ(actual_string, expected_string);
}

TEST( TheMazeIii, Test_invalid_ball ) {
        vector<vector<int>> maze({
                {0,0,0,0,0},
                {1,1,0,0,1},
                {0,0,0,0,0},
                {0,1,0,0,1},
                {0,1,0,0,0},
        });
        vector<int> ball({50,50});
        vector<int> hole({0,0});

        string expected_string = "impossible";
        string actual_string = Solution().findShortestWay(maze, ball, hole);

        EXPECT_EQ(actual_string, expected_string);
}

TEST( TheMazeIii, Test_no_ball ) {
        vector<vector<int>> maze({
                {0,0,0,0,0},
                {1,1,0,0,1},
                {0,0,0,0,0},
                {0,1,0,0,1},
                {0,1,0,0,0},
        });
        vector<int> ball;
        vector<int> hole({0,0});

        string expected_string = "impossible";
        string actual_string = Solution().findShortestWay(maze, ball, hole);

        EXPECT_EQ(actual_string, expected_string);
}

TEST( TheMazeIii, Test_invalid_hole ) {
        vector<vector<int>> maze({
                {0,0,0,0,0},
                {1,1,0,0,1},
                {0,0,0,0,0},
                {0,1,0,0,1},
                {0,1,0,0,0},
        });
        vector<int> ball({0,0});
        vector<int> hole({50,50});

        string expected_string = "impossible";
        string actual_string = Solution().findShortestWay(maze, ball, hole);

        EXPECT_EQ(actual_string, expected_string);
}

TEST( TheMazeIii, Test_no_hole ) {
        vector<vector<int>> maze({
                {0,0,0,0,0},
                {1,1,0,0,1},
                {0,0,0,0,0},
                {0,1,0,0,1},
                {0,1,0,0,0},
        });
        vector<int> ball({0,0});
        vector<int> hole;

        string expected_string = "impossible";
        string actual_string = Solution().findShortestWay(maze, ball, hole);

        EXPECT_EQ(actual_string, expected_string);
}
*/

TEST(TheMazeIii, Test_dldl) {
  vector<vector<int>> maze({
      {0, 0, 0, 0, 0, 0, 0},
      {0, 0, 1, 0, 0, 1, 0},
      {0, 0, 0, 0, 1, 0, 0},
      {0, 0, 0, 0, 0, 0, 1},
  });
  vector<int> ball({0, 4});
  vector<int> hole({3, 0});

  string expected_string = "dldl";
  string actual_string = Solution().findShortestWay(maze, ball, hole);

  EXPECT_EQ(actual_string, expected_string);
}

/*
TEST( TheMazeIii, Test_too_big ) {
        vector<vector<int>> maze(300,vector<int>(300));
        vector<int> ball({1,1});
        vector<int> hole({0,0});

        string expected_string = "impossible";
        string actual_string = Solution().findShortestWay(maze, ball, hole);

        EXPECT_EQ(actual_string, expected_string);
}
*/

TEST(TheMazeIii, Test_rulululurdrulululululdrulululul) {
  vector<vector<int>> maze({
      {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0,
       0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
      {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1,
       0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
      {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0,
       1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
      {0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0,
       0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
      {0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0,
       0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0},
      {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1,
       0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0},
      {0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0,
       0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
      {1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0,
       1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
      {0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0,
       0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0},
      {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1,
       0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
      {0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
       1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
      {1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0,
       1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
      {0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0,
       0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0},
      {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1,
       0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0},
      {0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0,
       1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
      {1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0,
       1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
      {0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0,
       0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
      {0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1,
       0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
       0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
      {0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0,
       0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
      {0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0,
       0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0},
      {0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1,
       0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0,
       1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
      {0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0,
       1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
      {0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0,
       0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0},
      {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1,
       0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0,
       0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0,
       1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0,
       0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
      {0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
       0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1},
  });
  vector<int> ball({27, 5});
  vector<int> hole({2, 3});

  string expected_string = "rulululurdrulululululdrulululul";
  string actual_string = Solution().findShortestWay(maze, ball, hole);

  EXPECT_EQ(actual_string, expected_string);
}

TEST(TheMazeIii, Test_drdrdrdldl) {
  vector<vector<int>> maze({
      {0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
      {0, 0, 1, 0, 0, 1, 0, 0, 1, 0},
      {0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
      {0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
      {0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
      {0, 0, 1, 0, 0, 1, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
      {1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
      {0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
      {0, 0, 0, 0, 0, 1, 0, 0, 1, 0},
  });
  vector<int> ball({2, 4});
  vector<int> hole({7, 6});

  string expected_string = "drdrdrdldl";
  string actual_string = Solution().findShortestWay(maze, ball, hole);

  EXPECT_EQ(actual_string, expected_string);
}
