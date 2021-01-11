/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <algorithm>
#include <vector>

using namespace std;

// name: minimum-deletion-cost-to-avoid-repeating-letters
// url: https://leetcode.com/problems/minimum-deletion-cost-to-avoid-repeating-letters
// difficulty: 2

class Solution {
public:
   
    
    int minCost(string s, vector<int>& cost) {
/*
i  p s[i] c[i] mn  mx   
=====================
0  -  a   1    1   1
1  a  a   2    3   2
2  a  b   3    1   1
3  b  a   4    5   4
4  a  a   1    6   4
*/
        int max_cost;
        int min_cost = 0;
        char prev = '\0';
        for(size_t i = 0, N = s.size(); i < N; prev = s[i], ++i) {
            if (s[i] == prev) {
                max_cost = max(max_cost, cost[i]);
                min_cost += cost[i];
                if (i == N - 1 || s[i + 1] != prev) {
                    min_cost -= max_cost;
                }
            } else {
                max_cost = cost[i];
                if (i < N - 1 && s[i+1] == s[i]) {
                    min_cost += cost[i];
                }
            }
        }

        return min_cost;
    }
};
