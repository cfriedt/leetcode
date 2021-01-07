/*
 * Copyright (c) 2020 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include "util/ListNode.hpp"

class Solution {
public:
  void deleteNode(ListNode *node) {
    ListNode *prev = nullptr;
    for (ListNode *it = node; it != nullptr; prev = it, it = it->next) {
      if (it->next == nullptr) {
        if (prev != nullptr) {
          prev->next = nullptr;
        }
      } else {
        it->val = it->next->val;
      }
    }
  }
};
