/*
 * MIT License
 *
 * Copyright (c) 2018 Christopher Friedt
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
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
