/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "task-scheduler.cpp"

using namespace std;

TEST(TaskScheduler, AAABBB_2) {
  vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
  int n = 2;
  EXPECT_EQ(8, Solution().leastInterval(tasks, n));
}

TEST(TaskScheduler, AAABBB_0) {
  vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
  int n = 0;
  EXPECT_EQ(6, Solution().leastInterval(tasks, n));
}

TEST(TaskScheduler, AAAAAABCDEFG_2) {
  vector<char> tasks = {'A', 'A', 'A', 'A', 'A', 'A',
                        'B', 'C', 'D', 'E', 'F', 'G'};
  int n = 2;
  EXPECT_EQ(16, Solution().leastInterval(tasks, n));
}

TEST(TaskScheduler, AAABBB_50) {
  vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
  int n = 50;
  EXPECT_EQ(104, Solution().leastInterval(tasks, n));
}

TEST(TaskScheduler, AAABBBCCCDDE_2) {
  vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B',
                        'C', 'C', 'C', 'D', 'D', 'E'};
  int n = 2;
  EXPECT_EQ(12, Solution().leastInterval(tasks, n));
}

TEST(TaskScheduler, AABCDEFGHIJKLMNOPQRSTUVWXYZ_2) {
  vector<char> tasks = {'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                        'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q',
                        'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
  int n = 31;
  EXPECT_EQ(33, Solution().leastInterval(tasks, n));
}

TEST(TaskScheduler, ABCDEABCDE_4) {
  vector<char> tasks = {'A', 'B', 'C', 'D', 'E', 'A', 'B', 'C', 'D', 'E'};
  int n = 4;
  EXPECT_EQ(10, Solution().leastInterval(tasks, n));
}

TEST(TaskScheduler, ABCDEFGHIJKLMNOPQRSTUVWXYZ_15) {
  vector<char> tasks = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                        'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                        'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
  int n = 15;
  EXPECT_EQ(26, Solution().leastInterval(tasks, n));
}
