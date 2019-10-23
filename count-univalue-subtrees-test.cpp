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

#include <gtest/gtest.h>

#include "util/TreeNode.cpp"

#include "count-univalue-subtrees.cpp"

// An empty tree should return 0
TEST( CountUnivalueSubtrees, Test_empty ) {
    string input = "[]";
    TreeNode *root = TreeNode_from_string( input );
    int expected_int = 0;
    int actual_int = Solution().countUnivalSubtrees(root);
    EXPECT_EQ( actual_int, expected_int );
}

// An tree with 1 node should return 1
TEST( CountUnivalueSubtrees, Test_one ) {
    string input = "[42]";
    TreeNode *root = TreeNode_from_string( input );
    int expected_int = 1;
    int actual_int = Solution().countUnivalSubtrees(root);
    EXPECT_EQ( actual_int, expected_int );
}

// A tree with all unique values should return the same number as
// the number of non-null leaf nodes
TEST( CountUnivalueSubtrees, Test_all_unique ) {
    string input = "[1,2,3,4,5,6,7]";
    TreeNode *root = TreeNode_from_string( input );
    int expected_int = 4;
    int actual_int = Solution().countUnivalSubtrees(root);
    EXPECT_EQ( actual_int, expected_int );
}

// A full tree with all the same values should return the number of subtrees
// (i.e. the number of nodes)
TEST( CountUnivalueSubtrees, Test_all_same ) {
    string input = "[5,5,5,5,5,5,5]";
    TreeNode *root = TreeNode_from_string( input );
    int expected_int = 7;
    int actual_int = Solution().countUnivalSubtrees(root);
    EXPECT_EQ( actual_int, expected_int );
}

// the example given by leetcode
TEST( CountUnivalueSubtrees, Test_5_1_5_5_5_null_5 ) {
	string input = "[5,1,5,5,5,null,5]";
	TreeNode *root = TreeNode_from_string( input );
	int expected_int = 4;
	int actual_int = Solution().countUnivalSubtrees( root );
	EXPECT_EQ( actual_int, expected_int );
}

// failed test case from leetcode
// failed because I did not recognize that 2 pieces of information needed
// to be returned from each invocation of recurse():
// 1) whether or not the subtree was unival
// 2) the count of the unival subtrees
TEST( CountUnivalueSubtrees, Test_7_82_82_n79_98_98_n79_n79_null_n28_n24_n28_n24_null_n79_null_97_65_n4_null_3_n4_65_3_null_97 ) {
    string input = "[7,82,82,-79,98,98,-79,-79,null,-28,-24,-28,-24,null,-79,null,97,65,-4,null,3,-4,65,3,null,97]";
    TreeNode *root = TreeNode_from_string( input );
    int expected_int = 8;
    int actual_int = Solution().countUnivalSubtrees( root );
    EXPECT_EQ( actual_int, expected_int );
}
