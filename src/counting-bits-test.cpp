/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "counting-bits.cpp"

TEST( CountingBits, Test_2 ) {
    int num = 2;
    vector<int> expected_vi({ 0, 1, 1 });
    vector<int> actual_vi = Solution().countBits(num);
    EXPECT_EQ( actual_vi, expected_vi );
}

TEST( CountingBits, Test_5 ) {
    int num = 5;
    vector<int> expected_vi({ 0, 1, 1, 2, 1, 2 });
    vector<int> actual_vi = Solution().countBits(num);
    EXPECT_EQ( actual_vi, expected_vi );
}

