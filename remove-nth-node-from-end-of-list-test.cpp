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

#include "util/ListNode.cpp"

#include "remove-nth-node-from-end-of-list.cpp"

class RemoveNthNodeFromEndOfList : public ::testing::Test {

public:

	RemoveNthNodeFromEndOfList() : n( -1 ), head( nullptr ), output( nullptr ) {}

	int n;
	ListNode *head;
	ListNode *output;
	string    input;
	string    expected_string;
	string    actual_string;
	Solution  soln;

	void mSetUp() {
		// needs to be called from within test case
		head = ListNode_from_string( input );
	}

	void doTest() {
		output = soln.removeNthFromEnd( head, n );
		actual_string = ListNode_to_string( output );

		EXPECT_EQ( actual_string, expected_string );
	}

	virtual void TearDown() override {
		ListNode_cleanup( & output );
	}
};

TEST_F( RemoveNthNodeFromEndOfList, Test_1_2_3_4_5__2 ) {
	input = "1->2->3->4->5";
	n = 2;
	expected_string = "1->2->3->5";

	mSetUp();
	doTest();
}
