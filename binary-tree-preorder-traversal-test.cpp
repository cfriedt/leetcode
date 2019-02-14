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
