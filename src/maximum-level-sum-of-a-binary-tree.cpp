/*
 * Copyright (c) 2019 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <algorithm>
#include <climits>
#include <unordered_map>
#include <vector>

using namespace std;

// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        unordered_map<size_t,int> level_sums;

        if ( nullptr == root ) {
            return 0;
        }

        calculateSums( level_sums, 1, root );

        vector<size_t> levels( level_sums.size(), -1 );
        size_t i = 0;
        for( auto & kv: level_sums ) {
            levels[ i++ ] = kv.first;
        }

        auto comparator = [&]( const size_t & a, const size_t & b ) -> bool {
            if ( level_sums[ b ] > level_sums[ a ] ) {
                return false;
            }
            if ( level_sums[ b ] < level_sums[ a ] ) {
                return true;
            }
            return b > a;
        };

        sort( levels.begin(), levels.end(), comparator );

        return levels[ 0 ];
    }

    static void calculateSums( unordered_map<size_t,int> & level_sums, const size_t level, const TreeNode *node ) {
        if ( nullptr == node ) {
            return;
        }

        calculateSums( level_sums, level + 1, node->left );
        calculateSums( level_sums, level + 1, node->right );
        level_sums[ level ] += node->val;
    }
};
