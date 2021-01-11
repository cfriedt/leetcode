/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {

  // https://leetcode.com/problems/fruit-into-baskets/

public:
  int totalFruit(vector<int> &tree) {
    const size_t N = tree.size();
    if (N < 3) {
      return int(N);
    }
    size_t largest = 0;
    bool grow = true;
    unordered_map<int, size_t> basket;
    size_t M;
    for (size_t L = 0, R = 0; L < N - 2 && R < N;) {
      if (grow) {
        M = basket.size();
        for (; R < N && M < 2; R++) {
          auto it = basket.find(tree[R]);
          if (basket.end() == it) {
            basket[tree[R]] = 1;
            M++;
          } else {
            it->second++;
          }
        }
        for (; R < N; R++) {
          auto it = basket.find(tree[R]);
          if (basket.end() == it) {
            break;
          }
          basket[tree[R]]++;
        }
        largest = max(largest, R - L);
        grow = false;
      } else {
        M = basket.size();
        for (; L < R && M >= 2; L++) {
          basket[tree[L]]--;
          if (0 == basket[tree[L]]) {
            basket.erase(tree[L]);
            M--;
          }
        }
        grow = true;
      }
    }
    return int(largest);
  }
};
