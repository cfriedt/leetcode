/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

	// https://leetcode.com/problems/add-two-numbers/

	uint64_t toInteger( ListNode *l ) {
		ListNode *it;
		uint64_t accu;
		uint64_t factor;
		for( accu = 0, factor = 1, it = l; nullptr != it; accu += factor * it->val, it = it->next, factor *= 10 );
		return accu;
	}

	ListNode *toList( uint64_t x ) {
		if ( 0 == x ) {
			return new ListNode( 0 );
		}
		ListNode *root, *it;
		for( root = new ListNode( x % 10 ), it = root; 0 != x; x /= 10, it->next = ( 0 == x ) ? nullptr : new ListNode( x % 10 ), it = it->next );
		return root;
	}

	size_t listLength( ListNode *l ) {
		size_t r;
		for( r = 0; nullptr != l; r++, l = l->next );
		return r;
	}

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

		// The lists l1 and l2 are non-empty (assume that also means non-null).
		// l1 and l2 represent non-negative integers.
		// The lists l1 and l2 are given in reverse order.
		// Each node in l1 and l2 contain a single digit.
		// The two numbers do not contain any leading zeros

		// The numbers should be added together and returned as a linked list, also in reverse order.

		// This is relatively easy, it seems, like long addition.
		//
		// One way of going about this is to create two methods
		// int toInteger(ListNode *)
		// ListNode *toList(int)
		//
		// 1) convert each of the lists to an integer O( N + M )
		// 2) add the integers O( 1 )
		// 3) convert the sum to a list O( max( N, M )  )

		size_t len1 = listLength( l1 );
		size_t len2 = listLength( l2 );

		if ( len1 >= 19 || len2 >= 19 ) {

			// for very large numbers, that cannot be represented in 64-bits

			int carry = 0;
			ListNode *root, *it;
			for( root = new ListNode( 0 ), it = root; !( nullptr == l1 && nullptr == l2 ); ) {
				int sum = carry;
				sum += ( nullptr == l1 ) ? 0 : l1->val;
				sum += ( nullptr == l2 ) ? 0 : l2->val;
				carry = sum / 10;
				it->val = sum % 10;

				l1 = ( nullptr == l1 ) ? nullptr : l1->next;
				l2 = ( nullptr == l2 ) ? nullptr : l2->next;

				uint8_t st = 0;
				st |= nullptr == l1 ? 0 : 1;
				st |= nullptr == l2 ? 0 : 2;

				if ( !( 0 == st && 0 == carry ) ) {
					it->next = new ListNode( 0 );
					it = it->next;
					if ( 0 == st && carry != 0 ) {
						it->val = carry;
					}
				}
			}
			return root;

		} else {
			// shortcut

			uint64_t x1 = toInteger( l1 );
			uint64_t x2 = toInteger( l2 );
			uint64_t r = x1 + x2;
			ListNode *rl = toList( r );
			return rl;
		}
	}
};
