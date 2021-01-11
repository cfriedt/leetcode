/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

// https://leetcode.com/problems/range-sum-query-mutable/

namespace std {
struct pair_hash {
  template <class T1, class T2>
  std::size_t operator()(const std::pair<T1, T2> &p) const {
    auto h1 = std::hash<T1>{}(p.first);
    auto h2 = std::hash<T2>{}(p.second);

    // Mainly for demonstration purposes, i.e. works but is overly simple
    // In the real world, use sth. like boost.hash_combine
    return h1 ^ h2;
  }
};
} // namespace std

class NumArray {
public:
  vector<int> nums;
  unordered_map<pair<int, int>, int, pair_hash> cache;

  NumArray() : NumArray(vector<int>()) {}
  explicit NumArray(const vector<int> &nums) : nums(nums) {}

  void update(int i, int val) {
    int prev = nums[i];
    if (prev == val) {
      return;
    }
    int delta = val - prev;
    // worst-case O( N )
    for (auto &kv : cache) {
      auto &p = kv.first;
      if (i >= p.first && i <= p.second) {
        kv.second += delta;
      }
    }
    nums[i] = val;
  }

  int sumRange(int i, int j) {
    pair<int, int> p(i, j);
    auto it = cache.find(p);
    if (cache.end() != it) {
      return (*it).second;
    }
    int s = 0;
    // worst-case O( N )
    for (int k = i; k <= j; k++) {
      s += nums[k];
    }
    return s;
  }
};
