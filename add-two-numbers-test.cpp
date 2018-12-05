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

#include <array>

using namespace std;

#include <gtest.h>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

#include "add-two-numbers.cpp"

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

TEST( AddTwoNumbers, Test__2_4_3__5_6_4 ) {
	// 342 + 465 =	 807
	array<ListNode,3> l1a({ ListNode( 2 ), ListNode( 4 ), ListNode( 3 ) });
	array<ListNode,3> l2a({ ListNode( 5 ), ListNode( 6 ), ListNode( 4 ) });
	ListNode *l1 = & l1a[ 0 ];
	ListNode *l2 = & l2a[ 0 ];

	l1a[ 0 ].next = & l1a[ 1 ];
	l1a[ 1 ].next = & l1a[ 2 ];

	l2a[ 0 ].next = & l2a[ 1 ];
	l2a[ 1 ].next = & l2a[ 2 ];

	array<ListNode,3> expected_1a({ ListNode( 7 ), ListNode( 0 ), ListNode( 8 ) });
	ListNode *expected_l = & expected_1a[ 0 ];

	expected_l[ 0 ].next = & expected_l[ 1 ];
	expected_l[ 1 ].next = & expected_l[ 2 ];

	ListNode *actual_l = Solution().addTwoNumbers(l1, l2);

	EXPECT_EQ( *actual_l, *expected_l );
}

TEST( AddTwoNumbers, Test__9__1_9_9_9_9_9_9_9_9_9 ) {
	// 342 + 465 =	 807
	array<ListNode,1> l1a({ ListNode( 9 ) });
	array<ListNode,10> l2a({ ListNode( 1 ), ListNode( 9 ), ListNode( 9 ), ListNode( 9 ), ListNode( 9 ), ListNode( 9 ), ListNode( 9 ), ListNode( 9 ), ListNode( 9 ), ListNode( 9 ) });
	ListNode *l1 = & l1a[ 0 ];
	ListNode *l2 = & l2a[ 0 ];

	for( size_t i = 0; i < l2a.size() - 1; i++ ) {
		l2a[ i ].next = & l2a[ i + 1 ];
	}

	array<ListNode,11> expected_1a({ ListNode( 0 ), ListNode( 0 ), ListNode( 0 ), ListNode( 0 ), ListNode( 0 ), ListNode( 0 ), ListNode( 0 ), ListNode( 0 ), ListNode( 0 ), ListNode( 0 ), ListNode( 1 ) });
	ListNode *expected_l = & expected_1a[ 0 ];

	for( size_t i = 0; i < expected_1a.size() - 1; i++ ) {
		expected_1a[ i ].next = & expected_1a[ i + 1 ];
	}

	ListNode *actual_l = Solution().addTwoNumbers(l1, l2);

	EXPECT_EQ( *actual_l, *expected_l );
}

TEST( AddTwoNumbers, Test__1_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_1__5_6_4 ) {
	// 342 + 465 =	 807

	array<ListNode,31> l1a({ ListNode(1), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(1) });
	array<ListNode,3> l2a({ ListNode( 5 ), ListNode( 6 ), ListNode( 4 ) });
	ListNode *l1 = & l1a[ 0 ];
	ListNode *l2 = & l2a[ 0 ];

	for( size_t i = 0; i < l1a.size() - 1; i++ ) {
		l1a[ i ].next = & l1a[ i + 1 ];
	}
	for( size_t i = 0; i < l2a.size() - 1; i++ ) {
		l2a[ i ].next = & l2a[ i + 1 ];
	}

	array<ListNode,31> expected_1a({ ListNode(6), ListNode(6), ListNode(4), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(0), ListNode(1) });
	ListNode *expected_l = & expected_1a[ 0 ];

	for( size_t i = 0; i < expected_1a.size() - 1; i++ ) {
		expected_1a[ i ].next = & expected_1a[ i + 1 ];
	}

	ListNode *actual_l = Solution().addTwoNumbers(l1, l2);

	EXPECT_EQ( *actual_l, *expected_l );
}
