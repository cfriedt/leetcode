/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "min-stack.cpp"

TEST(TwoSum, Test_n2_0_n3) {
  MinStack ms;
  ms.push(-2);
  ms.push(0);
  ms.push(-3);

  EXPECT_EQ(-3, ms.getMin());
  ms.pop();
  EXPECT_EQ(0, ms.top());
  EXPECT_EQ(-2, ms.getMin());
}
