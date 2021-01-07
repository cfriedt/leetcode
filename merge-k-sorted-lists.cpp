/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

using heapEntry = pair<int,size_t>;

struct is_le {
	bool operator()( heapEntry & a, heapEntry & b ) {
		// return true if b <= a
		return b.first <= a.first;
	}
};

class Solution {
public:

	// https://leetcode.com/problems/merge-k-sorted-lists/

	/**
	 * Definition for singly-linked list.
	 * struct ListNode {
	 *     int val;
	 *     ListNode *next;
	 *     ListNode(int x) : val(x), next(NULL) {}
	 * };
	 */

	static void listPopHead( ListNode **head ) {
		if ( nullptr != head && nullptr != *head ) {
			*head = (*head)->next;
		}
	}

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		// Assumptions:
		// - A null ListNode is the empty list
		// - OK to return a dynamically allocated result (i.e. user frees)
		// - No need to check if lists are sorted or not.
		// - ListNodes in "lists" can be null
		// - Assume that vals are sorted by natural ordering
		// - Assume negatives OK
		//
		// Analysis:
		//
		// The naive approach would be to perform some sorting algorithm on the
		// K first elements of each sorted list *every time* the lowest element is to be
		// added to the output list. That approach is inefficient because it discards
		// the previous work of sorting the list of K first elements.
		//
		// In fact, we don't actually care whether the K first elements are entirely sorted,
		// we just want to know which is the lowest. Therefore, best to use a min-heap.
		// If each list is (on average) L elements long, then the time-complexity
		// is O( L K log K ), but since L is an average figure (i.e. a constant),
		// it reduces to O( K log K ). The space complexity is O( K ) elements of temporary
		// storage in the min-heap.
		//
		// The min-heap will actually need to store pairs of (int,size_t) where the size_t
		// portion is the index of the list that the int came from. This makes it possible to
		// pop the head of each list after heapification.
		//
		// Will need a listAppend() method and a listPopHead() method.
		//
		// Example:
		// Input:
		// [
		//   1->4->5,
		//   1->3->4,
		//   2->6
		// ]
		// Output: 1->1->2->3->4->4->5->6

		ListNode head(0);
		ListNode *tail = nullptr;

		vector<heapEntry> minh;

		// create the initial min-heap
		for( size_t i = 0; i < lists.size(); i++ ) {
			if ( nullptr == lists[ i ] ) {
				continue;
			}
			minh.push_back( heapEntry( lists[ i ]->val, i ) );
			push_heap( minh.begin(), minh.end(), is_le() );
		}

		// while lists is not full of nullptr
		for( ; ! minh.empty(); ) {

			// the lowest number is at the front of the minh
			pop_heap( minh.begin(), minh.end(), is_le() );
			// don't actually pop the item off the list until later, to avoid unnecessary reallocation

			// after pop_heap() the lowest number (plus list index) is at the back of minh
			size_t list_with_lowest_value = minh.back().second;

			// append the ListNode with the lowest val to the output list
			// we keep track of the tail so that this operation is O( 1 )
			if ( nullptr == tail ) {
				tail = lists[ list_with_lowest_value ];
				head.next = tail;
			} else {
				tail->next = lists[ list_with_lowest_value ];
				tail = tail->next;
			}

			listPopHead( & lists[ list_with_lowest_value ] );

			if ( nullptr == lists[ list_with_lowest_value ] ) {
				minh.pop_back();
			} else {
				minh.back().first = lists[ list_with_lowest_value ]->val;
				minh.back().second = list_with_lowest_value;
				push_heap( minh.begin(), minh.end(), is_le() );
			}
		}

		if ( nullptr != tail ) {
			tail->next = nullptr;
		}

		return head.next;
	}
};
