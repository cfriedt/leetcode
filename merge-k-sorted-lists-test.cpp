/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <array>
#include <vector>

#include <gtest/gtest.h>

#include "util/ListNode.cpp"

using namespace std;

#include "merge-k-sorted-lists.cpp"

class MergeKSortedLists : public ::testing::Test {

public:

	MergeKSortedLists() : output( nullptr ) {}

	vector<string> input;
	vector<ListNode*> lists;
	ListNode *output;
	string    expected_string;
	string    actual_string;
	Solution  soln;

	void mSetUp() {
		// needs to be called from within test case
		for( auto & s: input ) {
			lists.push_back( ListNode_from_string( s ) );
		}
	}

	void doTest() {
		output = soln.mergeKLists( lists );
		actual_string = ListNode_to_string( output );

		EXPECT_EQ( actual_string, expected_string );
	}

	virtual void TearDown() override {
		for( auto & l: lists ) {
			ListNode_cleanup( & l );
		}
		ListNode_cleanup( & output );
	}
};

TEST_F( MergeKSortedLists, Test_1_4_5__1_3_4__2_6 ) {

	input = vector<string>({
		"1->4->5",
		"1->3->4",
		"2->6",
	});
	expected_string = "1->1->2->3->4->4->5->6";

	mSetUp();
	doTest();
}
