/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef UTIL_TREENODE_HPP_
#define UTIL_TREENODE_HPP_

#if 0
#if !defined(GTEST_INCLUDE_GTEST_GTEST_H_)
#error TreeNode.hpp should only be included in test cpp files
#endif /* ! defined( GTEST_INCLUDE_GTEST_GTEST_H_ ) */
#endif

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
