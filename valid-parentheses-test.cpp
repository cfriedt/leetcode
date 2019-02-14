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

#include "valid-parentheses.cpp"

// ro / rc = round open / round close
// co / cc = curly open / curly close
// so / sc = square open / square close

TEST( ValidParentheses, Test_ ) {
	string s;
	bool expected_bool( true );
	bool actual_bool = Solution().isValid(s);
	EXPECT_EQ(actual_bool, expected_bool);
}

TEST( ValidParentheses, Test_ro_rc ) {
	string s("()");
	bool expected_bool( true );
	bool actual_bool = Solution().isValid(s);
	EXPECT_EQ(actual_bool, expected_bool);
}

TEST( ValidParentheses, Test_ro_rc_so_sc_co_cc ) {
	string s("()[]{}");
	bool expected_bool( true );
	bool actual_bool = Solution().isValid(s);
	EXPECT_EQ(actual_bool, expected_bool);
}

TEST( ValidParentheses, Test_ro_sc ) {
	string s("(]");
	bool expected_bool( false );
	bool actual_bool = Solution().isValid(s);
	EXPECT_EQ(actual_bool, expected_bool);
}

TEST( ValidParentheses, Test_ro_so_rc_sc ) {
	string s("([)]");
	bool expected_bool( false );
	bool actual_bool = Solution().isValid(s);
	EXPECT_EQ(actual_bool, expected_bool);
}

TEST( ValidParentheses, Test_co_so_sc_cc ) {
	string s("{[]}");
	bool expected_bool( true );
	bool actual_bool = Solution().isValid(s);
	EXPECT_EQ(actual_bool, expected_bool);
}

TEST( ValidParentheses, Test_co ) {
	string s("(");
	bool expected_bool( false );
	bool actual_bool = Solution().isValid(s);
	EXPECT_EQ(actual_bool, expected_bool);
}
