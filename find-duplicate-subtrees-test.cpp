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

#include <algorithm>
#include <array>

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode( int x ) : val( x ), left( nullptr ), right( nullptr ) {}
};

bool operator==( const TreeNode & a, const TreeNode & b ) {
	if ( a.val != b.val ) {
		return false;
	}

	if (
		false
		|| ( nullptr == a.left && nullptr != b.left )
		|| ( nullptr == b.left && nullptr != a.left )
	) {
		return false;
	}

	if (
		false
		|| ( nullptr == a.right && nullptr != b.right )
		|| ( nullptr == b.right && nullptr != a.right )
	) {
		return false;
	}

	return
		true
		&& (
			false
			|| ( nullptr == a.left && nullptr == b.left )
			|| *a.left == *b.left
		)
		&& (
			false
			|| ( nullptr == a.right && nullptr == b.right )
			|| *a.right == *b.right
		)
		;
}

#include "find-duplicate-subtrees.cpp"

TEST( FindDuplicateSubtrees, Test_Example1 ) {
	array<TreeNode,7> nodes{ TreeNode( 1 ), TreeNode( 2 ), TreeNode( 3 ), TreeNode( 4 ), TreeNode( 2 ), TreeNode( 4 ), TreeNode( 4 ) };

	nodes[ 0 ].left  = & nodes[ 1 ];
	nodes[ 0 ].right = & nodes[ 2 ];

	nodes[ 1 ].left  = & nodes[ 3 ];

	nodes[ 2 ].left  = & nodes[ 4 ];
	nodes[ 2 ].right = & nodes[ 5 ];

	nodes[ 4 ].left = & nodes[ 6 ];

	vector<TreeNode *> expected_vt = vector<TreeNode *>{ & nodes[ 1 ], & nodes[ 3 ] };
	vector<TreeNode *> actual_vt = Solution().findDuplicateSubtrees( & nodes[ 0 ] );

	EXPECT_EQ(actual_vt.size(), expected_vt.size());

	sort( expected_vt.begin(), expected_vt.end() );
	sort( actual_vt.begin(), actual_vt.end() );

	for( size_t i = 0; i < min( actual_vt.size(), expected_vt.size() ); i++ ) {
		EXPECT_EQ( *actual_vt[i], *expected_vt[i] );
	}
}
