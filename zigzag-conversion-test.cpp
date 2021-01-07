/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <array>

using namespace std;

#include <gtest/gtest.h>

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
