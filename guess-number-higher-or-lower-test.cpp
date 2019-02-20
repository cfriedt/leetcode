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

#include "guess-number-higher-or-lower.cpp"

static int number;

int guess( int num ) {
	if ( false ) {
	} else if( num == number ) {
		return 0;
	} else if ( num > number ) {
		return -1;
	} else { // ( num < number )
		return +1;
	}
}

TEST( GuessNumberHigherOrLower, Test_sgn ) {
	number = 0;
	EXPECT_EQ( -1, guess(  1 ) );
	EXPECT_EQ( +1, guess( -1 ) );
	EXPECT_EQ(  0, guess(  0 ) );
}

TEST( GuessNumberHigherOrLower, Test_1__0 ) {
	int n = 1;
	number = 0;
	int expected_int = -1;
	int actual_int = Solution().guessNumber( n );
	EXPECT_EQ(actual_int, expected_int);
}

TEST( GuessNumberHigherOrLower, Test_1__2 ) {
	int n = 1;
	number = 2;
	int expected_int = -1;
	int actual_int = Solution().guessNumber( n );
	EXPECT_EQ(actual_int, expected_int);
}

TEST( GuessNumberHigherOrLower, Test_10__6 ) {
	int n = 10;
	number = 6;
	int expected_int = number;
	int actual_int = Solution().guessNumber( n );
	EXPECT_EQ(actual_int, expected_int);
}

TEST( GuessNumberHigherOrLower, Test_Yuuuuge ) {
	int n = INT_MAX;
	number = INT_MAX/2;
	int expected_int = number;
	int actual_int = Solution().guessNumber( n );
	EXPECT_EQ(actual_int, expected_int);
}

TEST( GuessNumberHigherOrLower, Test_Yuuuuge2 ) {
	int n = INT_MAX;
	number = INT_MAX;
	int expected_int = number;
	int actual_int = Solution().guessNumber( n );
	EXPECT_EQ(actual_int, expected_int);
}
