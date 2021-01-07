/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <unordered_set>

#include <gtest/gtest.h>

#include "util/TreeNode.cpp"

#include "find-duplicate-subtrees.cpp"

class FindDuplicateSubtrees : public ::testing::Test {

public:

	FindDuplicateSubtrees() : root( nullptr ) {}

	TreeNode *root;
	vector<TreeNode *> output;
	string    input;
	unordered_set<string>    expected_uss;
	unordered_set<string>    actual_uss;
	Solution  soln;

	void mSetUp() {
		// needs to be called from within test case
		root = TreeNode_from_string( input );
	}

	void doTest() {
		output = soln.findDuplicateSubtrees(root);
		for( auto & o: output ) {
			actual_uss.insert( TreeNode_to_string( o ) );
		}

		EXPECT_EQ( actual_uss, expected_uss );
	}

	virtual void TearDown() override {
		TreeNode_cleanup( root );
	}
};

TEST_F( FindDuplicateSubtrees, Test_1_2_3_4_null_2_4_null_null_4 ) {
	input = "[1,2,3,4,null,2,4,null,null,4]";
	expected_uss = unordered_set<string>({
		"[2,4]",
		"[4]",
	});
	mSetUp();
	doTest();
}
