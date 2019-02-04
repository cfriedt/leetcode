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

#include <unordered_set>

#include <gtest.h>

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
		for( auto & o: output ) {
			TreeNode_cleanup( o );
		}
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
