/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "sentence-screen-fitting.cpp"

TEST( SentenceScreenFitting, Test_2_8_hello_world ) {
	int rows = 2;
	int cols = 8;
	vector<string> sentence{ "hello", "world" };

	int expected_int = 1;
	int actual_int = Solution().wordsTyping(sentence, rows, cols);

	EXPECT_EQ( actual_int, expected_int );
}

TEST( SentenceScreenFitting, Test_3_6_a_bcd_e ) {
	int rows = 3;
	int cols = 6;
	vector<string> sentence{ "a", "bcd", "e" };

	int expected_int = 2;
	int actual_int = Solution().wordsTyping(sentence, rows, cols);

	EXPECT_EQ( actual_int, expected_int );
}

TEST( SentenceScreenFitting, Test_4_5_I_had_apple_pie ) {
	int rows = 4;
	int cols = 5;
	vector<string> sentence{ "I", "had", "apple", "pie" };

	int expected_int = 1;
	int actual_int = Solution().wordsTyping(sentence, rows, cols);

	EXPECT_EQ( actual_int, expected_int );
}

TEST( SentenceScreenFitting, Test_10000_9001_try_to_be_better ) {
	int rows = 10000;
	int cols = 9001;
	vector<string> sentence{ "try", "to", "be", "better" };

	int expected_int = 5293333;
	int actual_int = Solution().wordsTyping(sentence, rows, cols);

	EXPECT_EQ( actual_int, expected_int );
}
