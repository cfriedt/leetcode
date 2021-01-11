/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

// clang-format off
#include "util/TreeNode.cpp"
// clang-format on

#include "binary-tree-maximum-path-sum.cpp"

using namespace std;

TEST(BinaryTreeMaximumPathSum, 1_2_3) {
  TreeNode *root = TreeNode_from_string("[1,2,3]");
  EXPECT_EQ(6, Solution().maxPathSum(root));
}

TEST(BinaryTreeMaximumPathSum, n10_9_20_null_null_15_7) {
  TreeNode *root = TreeNode_from_string("[-10,9,20,null,null,15,7]");
  EXPECT_EQ(42, Solution().maxPathSum(root));
}

TEST(BinaryTreeMaximumPathSum, n3) {
  TreeNode *root = TreeNode_from_string("[-3]");
  EXPECT_EQ(-3, Solution().maxPathSum(root));
}

TEST(BinaryTreeMaximumPathSum, 1_n2_n3_1_3_n2_null_n1) {
  TreeNode *root = TreeNode_from_string("[1,-2,-3,1,3,-2,null,-1]");
  EXPECT_EQ(3, Solution().maxPathSum(root));
}

// This actually seems to be a kind of bug in LeetCode's binary tree builder
// Basically, if a BT node is NULL, then it's children don't need to be
// specified, even if there are valid nodes following. Seems a little
// inconsistent.
// See also util/TreeNode-test.cpp
TEST(BinaryTreeMaximumPathSum, 5_4_8_11_null_13_4_7_2_null_null_null_1) {
  TreeNode *root =
      TreeNode_from_string("[5,4,8,11,null,13,4,7,2,null,null,null,1]");
  EXPECT_EQ(48, Solution().maxPathSum(root));
}
