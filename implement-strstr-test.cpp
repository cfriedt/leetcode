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

#include "implement-strstr.cpp"

TEST( ImplementStrStr, Test_empty_empty ) {
	string haystack = "";
	string needle = "";
	int expected_int = 0;
	int actual_int = Solution().strStr(haystack, needle);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( ImplementStrStr, Test_empty_tiny__yuuuuuge ) {
	// needle too big
	string haystack = "tiny";
	string needle = "yuuuuuge";
	int expected_int = -1;
	int actual_int = Solution().strStr(haystack, needle);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( ImplementStrStr, Test_hello_ll ) {
	string haystack = "hello";
	string needle = "ll";
	int expected_int = 2;
	int actual_int = Solution().strStr(haystack, needle);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( ImplementStrStr, Test_aaaaa_bba ) {
	string haystack = "aaaaa";
	string needle = "ba";
	int expected_int = -1;
	int actual_int = Solution().strStr(haystack, needle);
	EXPECT_EQ(actual_int, expected_int);
}
