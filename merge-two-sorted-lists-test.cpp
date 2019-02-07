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

#include "merge-two-sorted-lists.cpp"

class MergeTwoSortedLists : public ::testing::Test {

public:

	MergeTwoSortedLists() : l1( nullptr ), l2( nullptr ), output( nullptr ) {}

	string s1;
	string s2;
	ListNode *l1;
	ListNode *l2;
	ListNode *output;
	string    expected_string;
	string    actual_string;
	Solution  soln;

	void mSetUp() {
		// needs to be called from within test case
		l1 = ListNode_from_string( s1 );
		l2 = ListNode_from_string( s2 );
	}

	void doTest() {
		output = soln.mergeTwoLists(l1, l2);
		actual_string = ListNode_to_string( output );

		EXPECT_EQ( actual_string, expected_string );
	}

	virtual void TearDown() override {
		ListNode_cleanup( & l1 );
		ListNode_cleanup( & l2 );
		ListNode_cleanup( & output );
	}
};


TEST_F( MergeTwoSortedLists, Test_1_2_4__1_3_4 ) {
	s1 = "1->2->4";
	s2 = "1->3->4";
	expected_string = "1->1->2->3->4->4";
	mSetUp();
	doTest();
}
