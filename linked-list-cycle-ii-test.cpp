/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <vector>

#include <gtest/gtest.h>

#include "util/ListNode.cpp"

#include "linked-list-cycle-ii.cpp"

TEST(LinkedListCycleIi, Test_3_2_0_n4__1) {
  vector<ListNode> nodes = {
      ListNode(3),
      ListNode(2),
      ListNode(0),
      ListNode(-4),
  };
  nodes[0].next = &nodes[1];
  nodes[1].next = &nodes[2];
  nodes[2].next = &nodes[3];
  nodes[3].next = &nodes[1];
  EXPECT_EQ(&nodes[1], Solution().detectCycle(&nodes[0]));
}

TEST(LinkedListCycleIi, Test_1_2__0) {
  vector<ListNode> nodes = {
      ListNode(1),
      ListNode(2),
  };
  nodes[0].next = &nodes[1];
  nodes[1].next = &nodes[0];
  EXPECT_EQ(&nodes[0], Solution().detectCycle(&nodes[0]));
}

TEST(LinkedListCycleIi, Test_1_n1) {
  vector<ListNode> nodes = {
      ListNode(1),
  };
  nodes[0].val = 1;
  nodes[0].next = NULL;
  EXPECT_EQ(NULL, Solution().detectCycle(&nodes[0]));
}
