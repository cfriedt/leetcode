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
