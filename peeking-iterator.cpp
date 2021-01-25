/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

// clang-format off
// name: peeking-iterator
// url: https://leetcode.com/problems/peeking-iterator
// difficulty: 2
// clang-format on

#include <vector>

using namespace std;

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
  PeekingIterator(const vector<int> &nums)
      : Iterator(nums), i(0), N(nums.size()), d(nums) {
    // Initialize any member here.

    // **DO NOT** save a copy of nums and manipulate it directly.
    // You should only use the Iterator interface methods.
  }

  // Returns the next element in the iteration without advancing the iterator.
  int peek() { return d[i]; }

  int next() { return d[i++]; }

  bool hasNext() const { return i < N; }

  int i;
  int N;
  vector<int> d;
};
