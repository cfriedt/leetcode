/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

// clang-format off
// name: unique-binary-search-trees
// url: https://leetcode.com/problems/unique-binary-search-trees
// difficulty: 2
// clang-format on

#include <vector>

using namespace std;

class Solution {
public:
    int helper(vector<int>& dp, int n) {
        if (dp[n] != 0) {
            return dp[n];
        }

        int m = 0;
        for(int root = 1; root <= n; ++root) {
            int before = root - 1;
            int after = n - root;

            m += helper(dp, before) * helper(dp, after);
        }
        
        dp[n] = m;
        return m;
    }

    int numTrees(int n) {
        // the solution is structurally recursive
        // n | root | numTrees(n)
        // ---------------
        // 0 |      | 1
        // 1 |      | 1
        // 2 |   1  |  1
        //   |   2  | +1 = 2
        // 3 |   1  |   numTress(0) * numTrees(2)
        //   |   2  | + numTrees(1) * numTrees(1)
        //   |   3  | + numTrees(2) * numTrees(0) = 5
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        return helper(dp, n);
    }
};
