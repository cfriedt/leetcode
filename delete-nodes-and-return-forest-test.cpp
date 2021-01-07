/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <vector>

#include <gtest/gtest.h>

#include "util/Forest.cpp"
#include "delete-nodes-and-return-forest.cpp"

using namespace std;

class DeleteNodesAndReturnForest : public ::testing::Test {

public:

    DeleteNodesAndReturnForest() : root( nullptr ), expected_size(0), actual_size(0) {}

    vector<int> to_delete;
    TreeNode *root;
    vector<TreeNode *> output;
    string    input;
    unordered_set<string> expected_uss;
    unordered_set<string> actual_uss;
    Solution  soln;
    size_t expected_size;
    size_t actual_size;

    void mSetUp() {
        // needs to be called from within test case
        root = TreeNode_from_string( input );
    }

    void doTest() {
        output = soln.delNodes( root, to_delete );
	actual_size = output.size();
	EXPECT_EQ( actual_size, expected_size );

	vector<string> vs_output = Forest_to_string( output );

	for( auto & s: vs_output ) {
		actual_uss.insert( s );
	}
        EXPECT_EQ( actual_uss, expected_uss );
    }

    virtual void TearDown() override {
        Forest_cleanup( output );
    }
};

TEST_F( DeleteNodesAndReturnForest, Test_1_2_3_4_5_6_7__3_5 ) {
    input = "[1,2,3,4,5,6,7]";
    to_delete = vector<int>{{3, 5}};
    expected_size = 3;
    expected_uss = unordered_set<string>{{ "[1,2,null,4]", "[6]", "[7]" }};
    mSetUp();
    doTest();
}
