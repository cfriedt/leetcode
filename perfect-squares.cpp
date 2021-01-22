/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

// clang-format off
// name: perfect-squares
// url: https://leetcode.com/problems/perfect-squares
// difficulty: 2
// clang-format on

#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        // n  | r(n) | comment
        // --------------
        //  1 | 1    | 1 is itself a perfect square
        //  2 | 2    | 1 + 1
        //  3 | 3    | 1 + 1 + 1
        //  4 | 1    | 4 is itself a perfect square
        //  5 | 2    | 4 + 1
        //  6 | 3    | 4 + 1 + 1
        //  7 | 4    | 4 + 1 + 1 + 1
        //  8 | 2    | 4 + 4
        //  9 | 1    | 9 is itself a perfect square
        // 10 | 2    | 9 + 1
        // 11 | 3    | 9 + 1 + 1
        // 12 | 3    | 4 + 4 + 4
        // 13 | 2    | 9 + 4
        // 
        // r(n) = min(1 + r(n-k), r(n))
        //
        // how to determine k?
        //
        // k is a perfect square that is <= n
        //
        // maintaining a map even of perfect squares for numbers up to
        // n could be O(N^2) space, at least, and the time to generate
        // them would be O(N) at least. If we had a list of them, there
        // would be O(N^2) ways per number, which would eaqual O(N^3) time.
        //
        // This dp approach is O(N^2) time and O(N) space
        
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        
        for(int j = 1; j <= n; ++j) {
            for(int i = 1, k = i*i; k <= j; ++i, k = i*i) {
                dp[j] = min(dp[j], 1 + dp[j - k]);
            }            
        }
        
        return dp[n];
    }
};
