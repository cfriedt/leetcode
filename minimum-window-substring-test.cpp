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

#include "minimum-window-substring.cpp"

TEST( MinimumWindowSubstring, Test_ADOBECODEBANC_ABC ) {
	string s( "ADOBECODEBANC" );
	string t( "ABC" );
	string expected_string( "BANC" );
	string actual_string = Solution().minWindow(s, t);
	EXPECT_EQ( actual_string, expected_string );
}

TEST( MinimumWindowSubstring, Test_aa_aa ) {
	string s( "aa" );
	string t( "aa" );
	string expected_string( "aa" );
	string actual_string = Solution().minWindow(s, t);
	EXPECT_EQ( actual_string, expected_string );
}

TEST( MinimumWindowSubstring, Test_bbaa_aba ) {
	string s( "bbaa" );
	string t( "aba" );
	string expected_string( "baa" );
	string actual_string = Solution().minWindow(s, t);
	EXPECT_EQ( actual_string, expected_string );
}