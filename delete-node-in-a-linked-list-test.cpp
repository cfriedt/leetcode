/*
 * Copyright (c) 2020 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "delete-node-in-a-linked-list.cpp"
#include "util/ListNode.cpp"

using namespace std;

TEST(DeleteNodeInALinkedList, 4_5_1_9__5) {
  ListNode *head = ListNode_from_string("4->5->1->9");
  ASSERT_EQ(head->next->val, 5);
  string expected = "4->1->9";
  Solution().deleteNode(head->next);
  string actual = ListNode_to_string(head);
  EXPECT_EQ(expected, actual);
}
