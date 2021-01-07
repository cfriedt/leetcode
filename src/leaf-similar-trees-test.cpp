/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "util/TreeNode.cpp"

#include "leaf-similar-trees.cpp"

using namespace std;

TEST(
    LeafSimilarTrees,
    3_5_1_6_2_9_8_null_null_7_4__3_5_1_6_7_4_2_null_null_null_null_null_null_9_8) {
  string root1s = "[3,5,1,6,2,9,8,null,null,7,4]";
  string root2s = "[3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]";
  TreeNode *root1 = TreeNode_from_string(root1s);
  TreeNode *root2 = TreeNode_from_string(root2s);
  EXPECT_EQ(true, Solution().leafSimilar(root1, root2));
}

TEST(LeafSimilarTrees, 1__1) {
  string root1s = "[1]";
  string root2s = "[1]";
  TreeNode *root1 = TreeNode_from_string(root1s);
  TreeNode *root2 = TreeNode_from_string(root2s);
  EXPECT_EQ(true, Solution().leafSimilar(root1, root2));
}

TEST(LeafSimilarTrees, 1__2) {
  string root1s = "[1]";
  string root2s = "[2]";
  TreeNode *root1 = TreeNode_from_string(root1s);
  TreeNode *root2 = TreeNode_from_string(root2s);
  EXPECT_EQ(false, Solution().leafSimilar(root1, root2));
}

TEST(LeafSimilarTrees, 1_2__2_2) {
  string root1s = "[1,2]";
  string root2s = "[2,2]";
  TreeNode *root1 = TreeNode_from_string(root1s);
  TreeNode *root2 = TreeNode_from_string(root2s);
  EXPECT_EQ(true, Solution().leafSimilar(root1, root2));
}

TEST(LeafSimilarTrees, 1_2_3__1_3_2) {
  string root1s = "[1,2,3]";
  string root2s = "[1,3,2]";
  TreeNode *root1 = TreeNode_from_string(root1s);
  TreeNode *root2 = TreeNode_from_string(root2s);
  EXPECT_EQ(false, Solution().leafSimilar(root1, root2));
}
