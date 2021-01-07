/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <climits>

using namespace std;

class Solution {
public:
  int SS(const TreeNode *v, int &max_sum) {
    if (v == nullptr) {
      return 0;
    }

    // max subtree sum
    int left = SS(v->left, max_sum);
    int right = SS(v->right, max_sum);

    max_sum = max(v->val + max(left, 0) + max(right, 0), max_sum);

    return max(max(left, right), 0) + v->val;
  }

  int maxPathSum(TreeNode *root) {
    int max_sum = INT_MIN;
    SS(root, max_sum);
    return max_sum;
  }
};
