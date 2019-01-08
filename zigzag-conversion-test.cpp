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

#include "zigzag-conversion.cpp"

TEST( ZigZagConversion, Test__PAYPALISHIRING__3 ) {
	//string convert(string s, int numRows)
	int numRows = 3;
	string s("PAYPALISHIRING");

	string expected_string("PAHNAPLSIIGYIR");
	string actual_string = Solution().convert( s, numRows );

	EXPECT_EQ( actual_string, expected_string );
}

TEST( ZigZagConversion, Test__A__3 ) {
	//string convert(string s, int numRows)
	int numRows = 3;
	string s("A");

	string expected_string("A");
	string actual_string = Solution().convert( s, numRows );

	EXPECT_EQ( actual_string, expected_string );
}

TEST( ZigZagConversion, Test__AB__4 ) {
	//string convert(string s, int numRows)
	int numRows = 4;
	string s("AB");

	string expected_string("AB");
	string actual_string = Solution().convert( s, numRows );

	EXPECT_EQ( actual_string, expected_string );
}

TEST( ZigZagConversion, Test__ABAB__2 ) {
	//string convert(string s, int numRows)
	int numRows = 2;
	string s("ABAB");

	string expected_string("AABB");
	string actual_string = Solution().convert( s, numRows );

	EXPECT_EQ( actual_string, expected_string );
}
