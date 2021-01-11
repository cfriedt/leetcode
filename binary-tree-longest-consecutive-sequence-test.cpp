/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "util/TreeNode.cpp"

#include "binary-tree-longest-consecutive-sequence.cpp"

TEST(BinaryTreeLongestConsecutiveSequence,
     Test_1_null_3_null_null_2_4_null_null_null_null_null_null_null_5) {
  string input = "[1,null,3,2,4,null,null,null,5]";
  TreeNode *root = TreeNode_from_string(input);
  int expected_int = 3; // 3,4,5
  int actual_int = Solution().longestConsecutive(root);
  EXPECT_EQ(actual_int, expected_int);
}

TEST(BinaryTreeLongestConsecutiveSequence, Test_2_null_3_2_null_1) {
  string input = "[2,null,3,2,null,1]";
  TreeNode *root = TreeNode_from_string(input);
  int expected_int = 2; // 2,3
  int actual_int = Solution().longestConsecutive(root);
  EXPECT_EQ(actual_int, expected_int);
}
