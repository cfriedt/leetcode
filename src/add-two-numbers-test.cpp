/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <array>

using namespace std;

#include <gtest/gtest.h>

#include "util/ListNode.cpp"

#include "add-two-numbers.cpp"

class AddTwoNumbers : public ::testing::Test {

public:

	AddTwoNumbers() : l1( nullptr ), l2( nullptr ), output( nullptr ) {}

	string    l1_str;
	string    l2_str;
	ListNode *l1;
	ListNode *l2;
	ListNode *output;
	string    expected_string;
	string    actual_string;
	Solution  soln;

	void mSetUp() {
		// needs to be called from within test case
		l1 = ListNode_from_string( l1_str );
		l2 = ListNode_from_string( l2_str );
	}

	void doTest() {
		output = soln.addTwoNumbers( l1, l2 );
		actual_string = ListNode_to_string( output );

		EXPECT_EQ( actual_string, expected_string );
	}

	virtual void TearDown() override {
		ListNode_cleanup( & l1 );
		ListNode_cleanup( & l2 );
		ListNode_cleanup( & output );
	}
};

TEST_F( AddTwoNumbers, Test__2_4_3__5_6_4 ) {
	// 342 + 465 =	 807
	l1_str = "2->4->3";
	l2_str = "5->6->4";
	expected_string = "7->0->8";
	mSetUp();
	doTest();
}

TEST_F( AddTwoNumbers, Test__9__1_9_9_9_9_9_9_9_9_9 ) {
	l1_str = "9";
	l2_str = "1->9->9->9->9->9->9->9->9->9";
	expected_string = "0->0->0->0->0->0->0->0->0->0->1";
	mSetUp();
	doTest();
}

TEST_F( AddTwoNumbers, Test__1_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_1__5_6_4 ) {
	l1_str = "1->0->0->0->0->0->0->0->0->0->0->0->0->0->0->0->0->0->0->0->0->0->0->0->0->0->0->0->0->0->1";
	l2_str = "5->6->4";
	expected_string = "6->6->4->0->0->0->0->0->0->0->0->0->0->0->0->0->0->0->0->0->0->0->0->0->0->0->0->0->0->0->1";
	mSetUp();
	doTest();
}
