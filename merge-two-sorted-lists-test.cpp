/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "util/ListNode.cpp"

#include "merge-two-sorted-lists.cpp"

class MergeTwoSortedLists : public ::testing::Test {

public:
  MergeTwoSortedLists() : l1(nullptr), l2(nullptr), output(nullptr) {}

  string s1;
  string s2;
  ListNode *l1;
  ListNode *l2;
  vector<ListNode *> mess;
  ListNode *output;
  string expected_string;
  string actual_string;
  Solution soln;

  void mSetUp() {
    // needs to be called from within test case
    l1 = ListNode_from_string(s1);
    l2 = ListNode_from_string(s2);
    mess.resize(ListNode_size(l1) + ListNode_size(l2));
    size_t i = 0;
    for (auto it = l1; nullptr != it; it = it->next, i++) {
      mess[i] = it;
    }
    for (auto it = l2; nullptr != it; it = it->next, i++) {
      mess[i] = it;
    }
  }

  void doTest() {
    output = soln.mergeTwoLists(l1, l2);
    actual_string = ListNode_to_string(output);

    EXPECT_EQ(actual_string, expected_string);
  }

  virtual void TearDown() override {
    for (auto m : mess) {
      delete m;
    }
  }
};

TEST_F(MergeTwoSortedLists, Test_1_2_4__1_3_4) {
  s1 = "1->2->4";
  s2 = "1->3->4";
  expected_string = "1->1->2->3->4->4";
  mSetUp();
  doTest();
}
