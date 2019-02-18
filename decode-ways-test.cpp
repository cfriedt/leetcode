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

#include "decode-ways.cpp"

TEST( DecodeWays, Test_12 ) {
	string s = "12";
	int expected_int = 2;
	int actual_int = Solution().numDecodings(s);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( DecodeWays, Test_226 ) {
	string s = "226";
	int expected_int = 3;
	int actual_int = Solution().numDecodings(s);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( DecodeWays, Test_empty ) {
	string s;
	int expected_int = 0;
	int actual_int = Solution().numDecodings(s);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( DecodeWays, Test_122 ) {
	string s = "242";
	int expected_int = 2;
	int actual_int = Solution().numDecodings(s);
	EXPECT_EQ(actual_int, expected_int);
}
