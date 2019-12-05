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
