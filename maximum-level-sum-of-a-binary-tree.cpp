/*
 * MIT License
 *
 * Copyright (c) 2019 Christopher Friedt
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
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
