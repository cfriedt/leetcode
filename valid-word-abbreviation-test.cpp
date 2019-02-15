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

#include "valid-word-abbreviation.cpp"

TEST( ValidWordAbbreviation, Test_internationalization_i5a11o1 ) {
	string word = "internationalization";
	string abbr = "i5a11o1";
	bool expected_bool = true;
	bool actual_bool = Solution().validWordAbbreviation(word, abbr);
	EXPECT_EQ(actual_bool, expected_bool);
}

TEST( ValidWordAbbreviation, Test_a_01 ) {
	string word = "a";
	string abbr = "01";
	bool expected_bool = false;
	bool actual_bool = Solution().validWordAbbreviation(word, abbr);
	EXPECT_EQ(actual_bool, expected_bool);
}

TEST( ValidWordAbbreviation, Test_internationalization_i12iz4n ) {
	string word = "internationalization";
	string abbr = "i12iz4n";
	bool expected_bool = true;
	bool actual_bool = Solution().validWordAbbreviation(word, abbr);
	EXPECT_EQ(actual_bool, expected_bool);
}

// tests that the number does not go beyond the length of the string
TEST( ValidWordAbbreviation, Test_apple_a5 ) {
	string word = "apple";
	string abbr = "a5";
	bool expected_bool = false;
	bool actual_bool = Solution().validWordAbbreviation(word, abbr);
	EXPECT_EQ(actual_bool, expected_bool);
}

// tests that the word and abbr do not have trailing data
TEST( ValidWordAbbreviation, Test_apple_a4g ) {
	string word = "apple";
	string abbr = "a4g";
	bool expected_bool = false;
	bool actual_bool = Solution().validWordAbbreviation(word, abbr);
	EXPECT_EQ(actual_bool, expected_bool);
}
