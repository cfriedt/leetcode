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

#include <gtest.h>

#include "util/TreeNode.cpp"

#include "delete-node-in-a-bst.cpp"

#include <unordered_map>

#include <array>
#include <climits>
#include <memory>
#include <string>
#include <sstream>

class DeleteNodeInABst : public ::testing::Test {

public:

	DeleteNodeInABst() : key( -1 ), root( nullptr ), output( nullptr ) {}

	int key;
	TreeNode *root;
	TreeNode *output;
	string    input;
	string    expected_string;
	string    actual_string;
	Solution  soln;

	void mSetUp() {
		// needs to be called from within test case
		root = TreeNode_from_string( input );
	}

	void doTest() {
		output = soln.deleteNode( root, key );
		actual_string = TreeNode_to_string( output );

		EXPECT_EQ( actual_string, expected_string );
	}

	virtual void TearDown() override {
		TreeNode_cleanup( output );
	}
};

TEST_F( DeleteNodeInABst, Test_5_3_6_2_4_null_7__3 ) {
	input = "[5,3,6,2,4,null,7]";
	key = 3;
	expected_string = "[5,4,6,2,null,null,7]";

	mSetUp();
	doTest();
}

TEST_F( DeleteNodeInABst, Test_5__5 ) {
	input = "[5]";
	key = 5;
	expected_string = "[]";

	mSetUp();
	doTest();
}

TEST_F( DeleteNodeInABst, Test_5__7 ) {
	input = "[5]";
	key = 7;
	expected_string = "[5]";

	mSetUp();
	doTest();
}

TEST_F( DeleteNodeInABst, Test_5_3_7_2_null_6_8__7 ) {

	//      5
	//    3   7
	//  2    6  8

	input = "[5,3,7,2,null,6,8]";
	key = 7;
	expected_string = "[5,3,8,2,null,6]";

	mSetUp();
	doTest();
}

TEST_F( DeleteNodeInABst, Test_1_null_2 ) {
	input = "[1,null,2]";
	key = 1;
	expected_string = "[2]";

	mSetUp();
	doTest();
}

TEST_F( DeleteNodeInABst, Test_5_3_6_2_4_null_7__5 ) {
	input = "[5,3,6,2,4,null,7]";
	key = 5;
	expected_string = "[6,3,7,2,4]";

	mSetUp();
	doTest();
}

TEST_F( DeleteNodeInABst, Test_3_1_4_null_2__1 ) {
	input = "[3,1,4,null,2]";
	key = 1;
	expected_string = "[3,2,4]";

	mSetUp();
	doTest();
}
