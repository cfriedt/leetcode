/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <vector>

#include "util/TreeNode.hpp"

using namespace std;

class Solution {
public:
  void rake(vector<int> &l, TreeNode *node) {
    if (node == NULL) {
      return;
    }

    rake(l, node->left);

    if (node->left == NULL && node->right == NULL) {
      l.push_back(node->val);
    }

    rake(l, node->right);
  }

  bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    vector<int> l1;
    vector<int> l2;

    rake(l1, root1);
    rake(l2, root2);

    return (l1.size() == l2.size()) && l1 == l2;
  }
};
