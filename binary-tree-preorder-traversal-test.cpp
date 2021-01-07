/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "util/TreeNode.cpp"

#include "binary-tree-preorder-traversal.cpp"

class BinaryTreePreorderTraversal : public ::testing::Test {

public:

	BinaryTreePreorderTraversal() : root( nullptr ) {}

	string    input;
	TreeNode *root;
	vector<int>    expected_vector;
	vector<int>    actual_vector;
	Solution  soln;

	void mSetUp() {
		// needs to be called from within test case
		root = TreeNode_from_string( input );
	}

	void doTest() {
		actual_vector = soln.preorderTraversal( root );

		EXPECT_EQ( actual_vector, expected_vector );
	}

	virtual void TearDown() override {
		TreeNode_cleanup( root );
	}
};

TEST_F( BinaryTreePreorderTraversal, Test_1_null_2_3 ) {
	input = "[1,null,2,3]";
	expected_vector = vector<int>({1,2,3});
	mSetUp();
	doTest();
}
