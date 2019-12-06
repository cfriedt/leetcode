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
