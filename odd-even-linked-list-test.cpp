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

#include <gtest.h>

#include "util/ListNode.cpp"

#include "odd-even-linked-list.cpp"

class OddEvenLinkedList : public ::testing::Test {
public:
	OddEvenLinkedList() : head( nullptr ), output( nullptr ) {}
protected:
	string input;
	ListNode *head;
	vector<ListNode *> nodes;
	ListNode *output;
	string expected_string;
	string actual_string;
	Solution soln;
	void mSetUp() {
		head = ListNode_from_string( input );
	}
	void doTest() {
		ListNode *output = soln.oddEvenList(head);
		actual_string = ListNode_to_string( output );
		EXPECT_EQ( actual_string, expected_string );
	}
	void TearDown() override {
		for( auto & n: nodes ) {
			delete n;
		}
	}
};

TEST_F( OddEvenLinkedList, Test_1_2_3_4_5 ) {
	input = "1->2->3->4->5";
	expected_string = "1->3->5->2->4";
	mSetUp();
	doTest();
}

TEST_F( OddEvenLinkedList, Test_2_1_3_5_6_4_7 ) {
	input = "2->1->3->5->6->4->7";
	expected_string = "2->3->6->7->1->5->4";
	mSetUp();
	doTest();
}

TEST_F( OddEvenLinkedList, Test_nil ) {
	input = "";
	expected_string = "";
	mSetUp();
	doTest();
}

TEST_F( OddEvenLinkedList, Test_1 ) {
	input = "1";
	expected_string = "1";
	mSetUp();
	doTest();
}
