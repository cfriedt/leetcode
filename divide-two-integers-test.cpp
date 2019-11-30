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

#include "divide-two-integers.cpp"

TEST( DivideTwoIntegers, Test_10_3 ) {
	int dividend = 10;
	int divisor = 3;
	int expected_int = 3;
	int actual_int = Solution().divide(dividend, divisor);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( DivideTwoIntegers, Test_7_n3 ) {
	int dividend = 7;
	int divisor = -3;
	int expected_int = -2;
	int actual_int = Solution().divide(dividend, divisor);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( DivideTwoIntegers, Test_1_0 ) {
	// positive saturation
	int dividend = 1;
	int divisor = 0;
	int expected_int = INT_MAX;
	int actual_int = Solution().divide(dividend, divisor);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( DivideTwoIntegers, Test_n1_0 ) {
	// negative saturation
	int dividend = -1;
	int divisor = 0;
	int expected_int = INT_MIN;
	int actual_int = Solution().divide(dividend, divisor);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( DivideTwoIntegers, Test_500_1 ) {
	int dividend = 500;
	int divisor = 1;
	int expected_int = 500;
	int actual_int = Solution().divide(dividend, divisor);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( DivideTwoIntegers, Test_INTMIN_n1 ) {
	int dividend = INT_MIN;
	int divisor = -1;
	int expected_int = INT_MAX;
	int actual_int = Solution().divide(dividend, divisor);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( DivideTwoIntegers, Test_500_n1 ) {
	int dividend = 500;
	int divisor = -1;
	int expected_int = -500;
	int actual_int = Solution().divide(dividend, divisor);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( DivideTwoIntegers, Test_INTMIN_INTMIN ) {
	int dividend = INT_MIN;
	int divisor = INT_MIN;
	int expected_int = 1;
	int actual_int = Solution().divide(dividend, divisor);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( DivideTwoIntegers, Test_INTMIN_5 ) {
	int dividend = INT_MIN;
	int divisor = INT_MAX/2;
	int expected_int = -2;
	int actual_int = Solution().divide(dividend, divisor);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( DivideTwoIntegers, Test_5_INTMIN ) {
	int dividend = 5;
	int divisor = INT_MIN;
	int expected_int = 0;
	int actual_int = Solution().divide(dividend, divisor);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( DivideTwoIntegers, Test_10_5 ) {
	int dividend = 10;
	int divisor = 5;
	int expected_int = 2;
	int actual_int = Solution().divide(dividend, divisor);
	EXPECT_EQ(actual_int, expected_int);
}

