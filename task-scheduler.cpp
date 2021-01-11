/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

// name: task-scheduler
// url: https://leetcode.com/problems/task-scheduler
// difficulty: 2

class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {
    if (0 == n) {
      return tasks.size();
    }

    unordered_map<char, int> hist;
    int peak = 0;
    // create a histogram of task frequencies, also keep track of peak frequency
    for (const auto &task : tasks) {
      hist[task]++;
      peak = max(peak, hist[task]);
    }

    if (hist.size() == tasks.size()) {
      return tasks.size();
    }

    // find the number of tasks that share the peak frequency
    int npeak = 0;
    for (auto &kv : hist) {
      if (kv.second == peak) {
        ++npeak;
      }
    }

    return max(int(tasks.size()), (peak - 1) * (n + 1) + npeak);
  }
};
