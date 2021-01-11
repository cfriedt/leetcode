/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <vector>

#include <gtest/gtest.h>

#include "util/ListNode.cpp"

#include "odd-even-linked-list.cpp"

class OddEvenLinkedList : public ::testing::Test {
public:
  OddEvenLinkedList() : head(nullptr), output(nullptr) {}

protected:
  string input;
  ListNode *head;
  vector<ListNode *> nodes;
  ListNode *output;
  string expected_string;
  string actual_string;
  Solution soln;
  void mSetUp() { head = ListNode_from_string(input); }
  void doTest() {
    ListNode *output = soln.oddEvenList(head);
    actual_string = ListNode_to_string(output);
    EXPECT_EQ(actual_string, expected_string);
  }
  void TearDown() override {
    for (auto &n : nodes) {
      delete n;
    }
  }
};

TEST_F(OddEvenLinkedList, Test_1_2_3_4_5) {
  input = "1->2->3->4->5";
  expected_string = "1->3->5->2->4";
  mSetUp();
  doTest();
}

TEST_F(OddEvenLinkedList, Test_2_1_3_5_6_4_7) {
  input = "2->1->3->5->6->4->7";
  expected_string = "2->3->6->7->1->5->4";
  mSetUp();
  doTest();
}

TEST_F(OddEvenLinkedList, Test_nil) {
  input = "";
  expected_string = "";
  mSetUp();
  doTest();
}

TEST_F(OddEvenLinkedList, Test_1) {
  input = "1";
  expected_string = "1";
  mSetUp();
  doTest();
}
