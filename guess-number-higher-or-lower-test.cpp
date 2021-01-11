/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <climits>
#include <gtest/gtest.h>

#include "guess-number-higher-or-lower.cpp"

static int number;

int guess(int num) {
  if (false) {
  } else if (num == number) {
    return 0;
  } else if (num > number) {
    return -1;
  } else { // ( num < number )
    return +1;
  }
}

TEST(GuessNumberHigherOrLower, Test_sgn) {
  number = 0;
  EXPECT_EQ(-1, guess(1));
  EXPECT_EQ(+1, guess(-1));
  EXPECT_EQ(0, guess(0));
}

TEST(GuessNumberHigherOrLower, Test_1__0) {
  int n = 1;
  number = 0;
  int expected_int = -1;
  int actual_int = Solution().guessNumber(n);
  EXPECT_EQ(actual_int, expected_int);
}

TEST(GuessNumberHigherOrLower, Test_1__2) {
  int n = 1;
  number = 2;
  int expected_int = -1;
  int actual_int = Solution().guessNumber(n);
  EXPECT_EQ(actual_int, expected_int);
}

TEST(GuessNumberHigherOrLower, Test_10__6) {
  int n = 10;
  number = 6;
  int expected_int = number;
  int actual_int = Solution().guessNumber(n);
  EXPECT_EQ(actual_int, expected_int);
}

TEST(GuessNumberHigherOrLower, Test_Yuuuuge) {
  int n = INT_MAX;
  number = INT_MAX / 2;
  int expected_int = number;
  int actual_int = Solution().guessNumber(n);
  EXPECT_EQ(actual_int, expected_int);
}

TEST(GuessNumberHigherOrLower, Test_Yuuuuge2) {
  int n = INT_MAX;
  number = INT_MAX;
  int expected_int = number;
  int actual_int = Solution().guessNumber(n);
  EXPECT_EQ(actual_int, expected_int);
}
