/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <string>

#include <gtest/gtest.h>

#include "single-row-keyboard.cpp"

using namespace std;

TEST( SingleRowKeyboard, Test_abcdefghijklmnopqrstuvwxyz_cba ) {
    string keyboard = "abcdefghijklmnopqrstuvwxyz";
    string word = "cba";
    int expected_int = 4;
    int actual_int = Solution().calculateTime(keyboard, word);
    EXPECT_EQ( actual_int, expected_int );
}

TEST( SingleRowKeyboard, Test_pqrstuvwxyzabcdefghijklmno_leetcode ) {
    string keyboard = "pqrstuvwxyzabcdefghijklmno";
    string word = "leetcode";
    int expected_int = 73;
    int actual_int = Solution().calculateTime(keyboard, word);
    EXPECT_EQ( actual_int, expected_int );
}
