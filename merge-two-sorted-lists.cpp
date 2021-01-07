/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
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
