/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

using namespace std;

// https://leetcode.com/problems/linked-list-cycle-ii

#define CYCLE 0xc7c1e

class Solution {
public:
  // this solution is destructive of the input, but it's O(1) space complexity
  ListNode *detectCycle(ListNode *head) {
    ListNode *it;
    for (it = head; it != NULL; it = it->next) {
      if (it->val == CYCLE) {
        return it;
      }
      it->val = CYCLE;
    }
    return it;
  }
};
