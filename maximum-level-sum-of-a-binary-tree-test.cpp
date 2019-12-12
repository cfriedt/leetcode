/*
 * MIT License
 *
 * Copyright (c) 2018 Christopher Friedt
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
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
