/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "binary-tree-zigzag-level-order-traversal.cpp"
#include "util/TreeNode.cpp"

using namespace std;

TEST(BinaryTreeZigZagLevelOrderTraversal, 3_9_20_null_null_15_7) {
  string input = "[3,9,20,null,null,15,7]";
  TreeNode *root = TreeNode_from_string(input);
  vector<vector<int>> expected = {
      {3},
      {20, 9},
      {15, 7},
  };
  EXPECT_EQ(expected, Solution().zigzagLevelOrder(root));
}
