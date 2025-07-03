/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef UTIL_TREENODE_HPP_
#define UTIL_TREENODE_HPP_

#include <string>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : TreeNode(0) {}
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

std::string TreeNode_to_string(TreeNode *root);
TreeNode *TreeNode_from_string(std::string s);
void TreeNode_cleanup(TreeNode *root);

#endif /* UTIL_TREENODE_HPP_ */
