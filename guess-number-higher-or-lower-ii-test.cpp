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

#include <climits>
#include <gtest/gtest.h>

#include "guess-number-higher-or-lower-ii.cpp"

TEST( GuessNumberHigherOrLowerIi, Test_1 ) {
	int n = 1;
	int expected_int = 0;
	int actual_int = Solution().getMoneyAmount( n );
	EXPECT_EQ(actual_int, expected_int);
}

TEST( GuessNumberHigherOrLowerIi, Test_10 ) {
	int n = 10;
	int expected_int = 16;
	int actual_int = Solution().getMoneyAmount( n );
	EXPECT_EQ(actual_int, expected_int);
}

#if 0
TEST( GuessNumberHigherOrLowerIi, Test_Yuuuuge ) {
	int n = INT_MAX;
	int expected_int = 1073741823;
	int actual_int = Solution().getMoneyAmount( n );
	EXPECT_EQ(actual_int, expected_int);
}

TEST( GuessNumberHigherOrLowerIi, Test_Yuuuuge2 ) {
	int n = INT_MAX;
	int expected_int = INT_MAX;
	int actual_int = Solution().getMoneyAmount( n );
	EXPECT_EQ(actual_int, expected_int);
}
#endif

TEST( GuessNumberHigherOrLowerIi, Test_4 ) {
	int n = 4;
	int expected_int = 4;
	int actual_int = Solution().getMoneyAmount( n );
	EXPECT_EQ(actual_int, expected_int);
}
