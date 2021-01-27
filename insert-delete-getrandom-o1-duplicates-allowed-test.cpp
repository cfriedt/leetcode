/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "insert-delete-getrandom-o1-duplicates-allowed.cpp"

using namespace std;

TEST(InsertDeleteGetrandomO1DuplicatesAllowed, example1) {
  RandomizedCollection c;

  EXPECT_EQ(true, c.insert(1));
  EXPECT_EQ(false, c.insert(1));
  EXPECT_EQ(true, c.insert(2));

  int n1s = 0;
  int n2s = 0;
  for (int i = 0; i < 1000; ++i) {
    if (1 == c.getRandom()) {
      ++n1s;
      continue;
    }
    if (2 == c.getRandom()) {
      ++n2s;
      continue;
    }
  }

  // around 66%
  EXPECT_GE(n1s, 600);

  EXPECT_EQ(true, c.remove(1));

  n1s = 0;
  n2s = 0;
  for (int i = 0; i < 1000; ++i) {
    if (1 == c.getRandom()) {
      ++n1s;
      continue;
    }
    if (2 == c.getRandom()) {
      ++n2s;
      continue;
    }
  }

  // around 50%
  EXPECT_GE(n1s, 475);
}

TEST(InsertDeleteGetrandomO1DuplicatesAllowed, example2) {
  RandomizedCollection c;
  EXPECT_EQ(true, c.insert(0));
  EXPECT_EQ(true, c.remove(0));
  EXPECT_EQ(true, c.insert(-1));
  EXPECT_EQ(false, c.remove(0));

  for (int i = 0; i < 10; ++i) {
    EXPECT_EQ(-1, c.getRandom());
  }
}
