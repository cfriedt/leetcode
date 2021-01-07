/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <algorithm>
#include <unordered_map>
#include <vector>

#include "util/TreeNode.hpp"

using namespace std;

class Solution {
public:
  void helper(unordered_map<size_t, vector<int>> &repr, TreeNode *node,
              size_t depth, size_t &max_depth) {
    if (node == NULL) {
      return;
    }

    max_depth = max(depth + 1, max_depth);
    helper(repr, node->left, depth + 1, max_depth);
    repr[depth].push_back(node->val);
    helper(repr, node->right, depth + 1, max_depth);
  }

  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {

    unordered_map<size_t, vector<int>> repr;

    size_t max_depth = 0;

    helper(repr, root, 0, max_depth);

    vector<vector<int>> r(max_depth);

    for (size_t i = 0; i < max_depth; ++i) {
      auto &v = repr[i];
      if ((i % 2) == 1) {
        reverse(v.begin(), v.end());
      }
      r[i] = v;
    }

    return r;
  }
};

