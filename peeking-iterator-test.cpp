/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include <vector>

using namespace std;

class Iterator {
public:
  Iterator(const vector<int> &nums) : data(nullptr) { (void)nums; }
  Iterator(const Iterator &iter) = default;
  // Returns the next element in the iteration.
  int next() { return -1; }

  // Returns true if the iteration has more elements.
  bool hasNext() const { return false; }

private:
  struct Data;
  Data *data;
};

#include "peeking-iterator.cpp"

TEST(PeekingIterator, 1_2_3) {
  vector<int> nums = {1, 2, 3};
  auto pi = PeekingIterator(nums);
  EXPECT_EQ(1, pi.next());
  EXPECT_EQ(2, pi.peek());
  EXPECT_EQ(2, pi.next());
  EXPECT_EQ(3, pi.next());
  EXPECT_EQ(false, pi.hasNext());
}
