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

#include <gtest.h>

#include <array>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
	ListNode() : ListNode( 0 ) {}
};

bool operator==( const ListNode & a, const ListNode & b ) {
	if ( a.val != b.val ) {
		return false;
	}

	if ( a.next == nullptr && b.next == nullptr ) {
		return true;
	}

	if ( a.next == nullptr || b.next == nullptr ) {
		return false;
	}

	return *a.next == *b.next;
}

#include "merge-k-sorted-lists.cpp"

TEST( MergeKSortedLists, Test_1_4_5__1_3_4__2_6 ) {

	array<ListNode,8> node{
		ListNode( 1 ), ListNode( 4 ), ListNode( 5 ),
		ListNode( 1 ), ListNode( 3 ), ListNode( 4 ),
		ListNode( 2 ), ListNode( 6 ),
	};

	node[ 0 ].next = & node[ 1 ];
	node[ 1 ].next = & node[ 2 ];
	node[ 2 ].next = nullptr;
	node[ 3 ].next = & node[ 4 ];
	node[ 4 ].next = & node[ 5 ];
	node[ 5 ].next = nullptr;
	node[ 6 ].next = & node[ 7 ];
	node[ 7 ].next = nullptr;


	vector<ListNode*> lists {
		& node[ 0 ],
		& node[ 3 ],
		& node[ 6 ],
	};

	array<ListNode,8> sorted_node {
		ListNode( 1 ), ListNode( 1 ), ListNode( 2 ), ListNode( 3 ), ListNode( 4 ), ListNode( 4 ), ListNode( 5 ), ListNode( 6 ),
	};
	for( size_t i = 0; i < sorted_node.size(); i++ ) {
		if ( i == sorted_node.size() - 1 ) {
			sorted_node[ i ].next = nullptr;
		} else {
			sorted_node[ i ].next = & sorted_node[ i + 1 ];
		}
	}

	ListNode expected_list; expected_list.next = & sorted_node[ 0 ];
	ListNode actual_list; actual_list.next = Solution().mergeKLists( lists );

	EXPECT_EQ( actual_list, expected_list );
}
