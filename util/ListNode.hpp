/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef UTIL_LISTNODE_HPP_
#define UTIL_LISTNODE_HPP_

#include <string>

struct ListNode {
  int val;
  ListNode *next;
  explicit ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *ListNode_from_string(const std::string &s);
std::string ListNode_to_string(ListNode *head);

size_t ListNode_size(ListNode *head);

void ListNode_cleanup(ListNode **head);

#endif /* UTIL_LISTNODE_HPP_ */
