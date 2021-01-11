/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  // https://leetcode.com/problems/repeated-dna-sequences/

  vector<string> findRepeatedDnaSequences(string s) {
    vector<string> r;

    unordered_map<string, size_t> count;
    const size_t N = s.size();
    const size_t M = 10; // repeated sequence length is fixed size of 10

    if (N <= M) {
      return r;
    }

    for (size_t i = 0; i <= N - M; i++) {
      string z = s.substr(i, M);
      if (count.end() == count.find(z)) {
        count[z] = 1;
      } else {
        count[z]++;
      }
    }

    for (auto &kv : count) {
      if (kv.second > 1) {
        r.push_back(kv.first);
      }
    }

    return r;
  }
};
