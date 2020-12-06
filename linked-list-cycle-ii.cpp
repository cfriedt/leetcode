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

#include <unordered_set>

using namespace std;

// https://leetcode.com/problems/linked-list-cycle-ii

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    unordered_set<ListNode *> visited;
    ListNode *it;
    for (it = head; it != NULL; it = it->next) {
      if (visited.end() != visited.find(it)) {
        return it;
      }
      visited.insert(it);
    }
    return it;
  }

  /*
    // Recursive solution (obviously better to use iterative)
    ListNode *helper(unordered_set<ListNode *> &visited, ListNode *n) {
      if (NULL == n) {
        return NULL;
      }
      if (visited.end() != visited.find(n)) {
        return n;
      }
      visited.insert(n);
      return helper(visited, n->next);
    }
  */
};
