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

#include "string-to-integer-atoi.cpp"

TEST( StringToIntegerAtoi, Test_empty ) {
	string str("");
	int expected_int = 0;
	int actual_int = Solution().myAtoi(str);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( StringToIntegerAtoi, Test_preceeding_zeros ) {
	// preceeding zeros should not add to the full amount in decimal, but should in hex. It isn't really common notation to
	// have preceeding zeros in any case.
	string str("010");
	int expected_int = 10;
	int actual_int = Solution().myAtoi(str);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( StringToIntegerAtoi, Test_42 ) {
	string str("42");
	int expected_int = 42;
	int actual_int = Solution().myAtoi(str);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( StringToIntegerAtoi, Test_____n42 ) {
	string str("    -42");
	int expected_int = -42;
	int actual_int = Solution().myAtoi(str);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( StringToIntegerAtoi, Test_41983_with_words ) {
	string str("41983 with words");
	int expected_int = 41983;
	int actual_int = Solution().myAtoi(str);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( StringToIntegerAtoi, Test_words_and_987 ) {
	string str("words_and_987");
	int expected_int = 0;
	int actual_int = Solution().myAtoi(str);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( StringToIntegerAtoi, Test_n91283472332 ) {
	string str("-91283472332");
	int expected_int = INT_MIN;
	int actual_int = Solution().myAtoi(str);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( StringToIntegerAtoi, Test_n946384712 ) {
	// ok reverse, but not forward
	string str("-9463847412");
	int expected_int = INT_MIN;
	int actual_int = Solution().myAtoi(str);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( StringToIntegerAtoi, Test_8463847412 ) {
	// ok reverse, but not forward
	string str("8463847412");
	int expected_int = INT_MAX;
	int actual_int = Solution().myAtoi(str);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( StringToIntegerAtoi, Test_n9128347233250 ) {
	// too many decimal digits
	string str("-9128347233250");
	int expected_int = INT_MIN;
	int actual_int = Solution().myAtoi(str);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( StringToIntegerAtoi, Test_9128347233250 ) {
	// too many decimal digits
	string str("9128347233250");
	int expected_int = INT_MAX;
	int actual_int = Solution().myAtoi(str);
	EXPECT_EQ(actual_int, expected_int);
}
