/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "unique-binary-search-trees.cpp"

using namespace std;

TEST(UniqueBinarySearchTrees, 1) {
  EXPECT_EQ(1, Solution().numTrees(1));
}

TEST(UniqueBinarySearchTrees, 2) {
  EXPECT_EQ(2, Solution().numTrees(2));
}

TEST(UniqueBinarySearchTrees, 3) {
  EXPECT_EQ(5, Solution().numTrees(3));
}

TEST(UniqueBinarySearchTrees, 4) {
  EXPECT_EQ(5, Solution().numTrees(3));
}
