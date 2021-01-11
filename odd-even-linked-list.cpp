/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <cstddef>

using namespace std;

class Solution {
public:
  // https://leetcode.com/problems/odd-even-linked-list/

  ListNode *oddEvenList(ListNode *head) {
    // Assumptions:
    // - 1-indexed, so the head pointer is '1'
    //
    // Observations:
    // - maintain e.g. a bool to indicate whether we are serving even or odd
    // - maintain a pointer to first / last element in odd / even
    // - makes appending O(1) and lets us keep a reference for
    //   concatenating at the end
    // - visit each node exactly once, O( N ) in time and O( 1 ) in space

    if (nullptr == head) {
      return nullptr;
    }

    enum {
      ODD,
      EVEN,
    };

    ListNode *m_head[2]{};
    ListNode *m_tail[2]{};

    ListNode *it = head;
    bool odd = ODD;
    for (; it; it = it->next, odd ^= 1) {
      if (nullptr == m_head[odd]) {
        m_head[odd] = m_tail[odd] = it;
      } else {
        m_tail[odd]->next = it;
        m_tail[odd] = m_tail[odd]->next;
      }
    }
    m_tail[ODD]->next = m_head[EVEN];
    if (nullptr != m_tail[EVEN]) {
      m_tail[EVEN]->next = nullptr;
    }

    return m_head[ODD];
  }
};
