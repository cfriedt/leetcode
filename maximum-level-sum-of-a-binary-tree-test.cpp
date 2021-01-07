/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <string>

#include <gtest/gtest.h>

#include "util/TreeNode.cpp"

#include "maximum-level-sum-of-a-binary-tree.cpp"

using namespace std;

TEST( MaximumLevelSumOfABinaryTree, Test_empty ) {
    TreeNode *root = TreeNode_from_string("[]");
    int expected_int = 0;
    int actual_int = Solution().maxLevelSum(root);
    EXPECT_EQ( actual_int, expected_int );
}

TEST( MaximumLevelSumOfABinaryTree, Test_1_7_0_7_n8_null_null ) {
    TreeNode *root = TreeNode_from_string("[1,7,0,7,-8,null,null]");
    int expected_int = 2;
    int actual_int = Solution().maxLevelSum(root);
    EXPECT_EQ( actual_int, expected_int );
}

TEST( MaximumLevelSumOfABinaryTree, Test_989_null_10250_98693_n89388_null_null_null_n32127 ) {
    TreeNode *root = TreeNode_from_string("[989,null,10250,98693,-89388,null,null,null,-32127]");
    int expected_int = 2;
    int actual_int = Solution().maxLevelSum(root);
    EXPECT_EQ( actual_int, expected_int );
}

TEST( MaximumLevelSumOfABinaryTree, Test_5_3_2 ) {
    TreeNode *root = TreeNode_from_string("[5,3,2]");
    int expected_int = 1;
    int actual_int = Solution().maxLevelSum(root);
    EXPECT_EQ( actual_int, expected_int );
}
