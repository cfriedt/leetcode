/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "generate-parentheses.cpp"

#include <unordered_set>

static unordered_set<string> toSet( vector<string> result ) {
	unordered_set<string> set;
	for( auto & x: result ) {
		set.insert( x );
	}
	return set;
}

TEST( GenerateParentheses, Test_3 ) {
	int n( 3 );

	unordered_set<string> expected_uss;

	expected_uss.insert( "((()))" );
	expected_uss.insert( "(()())" );
	expected_uss.insert( "(())()" );
	expected_uss.insert( "()(())" );
	expected_uss.insert( "()()()" );

	unordered_set<string> actual_uss = toSet( Solution().generateParenthesis(n));

	EXPECT_EQ( actual_uss, expected_uss );
}
