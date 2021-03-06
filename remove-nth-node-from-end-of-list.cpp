/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <array>

using namespace std;

class Solution {
public:
  // https://leetcode.com/problems/remove-nth-node-from-end-of-list

  ListNode *removeNthFromEnd(ListNode *head, int n) {

    // first what I would probably do is reverse the list
    // it should be fairly straight forward to do this in-place

    // then it would be much easier to remove the nth element

    // then I would just reverse the list again

    // The time complexity is O( 3N ) => O( N ), which isn't horrible
    // The space complexity is O( 1 )

    if (nullptr == head) {
      return nullptr;
    }

    head = reverseList(head);

    ListNode *it;
    ListNode *prev;
    int i;
    for (i = 1, prev = nullptr, it = head; i < n && nullptr != it;
         prev = it, it = it->next, i++)
      ;

    if (nullptr == it) {
      return nullptr;
    }

    if (nullptr == prev) {
      head = it->next;
    } else {
      prev->next = it->next;
    }

    head = reverseList(head);

    return head;
  }

  // the head of the returned list is actually the node at the end
  ListNode *reverseList(ListNode *head) {
    ListNode *it = head;
    ListNode *prev = nullptr;
    ListNode *next;
    for (; nullptr != it;) {
      next = it->next;
      if (nullptr == prev) {
        it->next = nullptr;
      } else {
        it->next = prev;
      }
      prev = it;
      it = next;
    }

    return prev;
  }
};
