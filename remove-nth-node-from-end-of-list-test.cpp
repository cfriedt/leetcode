/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "util/ListNode.cpp"

#include "remove-nth-node-from-end-of-list.cpp"

class RemoveNthNodeFromEndOfList : public ::testing::Test {

public:
  RemoveNthNodeFromEndOfList() : n(-1), head(nullptr), output(nullptr) {}

  int n;
  ListNode *head;
  ListNode *output;
  string input;
  string expected_string;
  string actual_string;
  Solution soln;

  void mSetUp() {
    // needs to be called from within test case
    head = ListNode_from_string(input);
  }

  void doTest() {
    output = soln.removeNthFromEnd(head, n);
    actual_string = ListNode_to_string(output);

    EXPECT_EQ(actual_string, expected_string);
  }

  virtual void TearDown() override { ListNode_cleanup(&output); }
};

TEST_F(RemoveNthNodeFromEndOfList, Test_1_2_3_4_5__2) {
  input = "1->2->3->4->5";
  n = 2;
  expected_string = "1->2->3->5";

  mSetUp();
  doTest();
}
