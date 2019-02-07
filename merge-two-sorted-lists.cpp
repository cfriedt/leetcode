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
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

class Solution {
public:

	// https://leetcode.com/problems/merge-two-sorted-lists/

	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode root(0);
		ListNode *it = nullptr;
		for( ; l1 || l2; ) {
			ListNode *least;
			if ( false ) {
			} else if ( l1 && l2 ) {
				if ( l1->val <= l2->val ) {
					least = l1;
				} else {
					least = l2;
				}
			} else if ( l1 ) {
				least = l1;
			} else {
				least = l2;
			}
			if ( least == l1 ) {
				l1 = l1->next;
			} else {
				l2 = l2->next;
			}
			if ( ! it ) {
				root.next = least;
				it = root.next;
			} else {
				it->next = least;
				it = it->next;
			}
		}
		return root.next;
	}
};
