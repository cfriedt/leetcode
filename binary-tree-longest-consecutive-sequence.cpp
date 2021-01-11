/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <cstddef>

using namespace std;

class Solution {
public:
  // https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/

  int longestConsecutive(TreeNode *root) {

    //
    // Analysis
    // --------
    // - first solution that comes to mind is DFS / preorder traversal
    // - running time is O(logN) in the best case scenario and O(N) in the
    // worst.
    //
    // Obsevations
    // -----------
    // - NOT A BINARY SEARCH TREE!!!
    // - Consecutive only means increasing by an integral value of 1.
    // - We need to know
    //   a) parent to know if there has been an increase, and
    //   b) grandparent to know if there has been a break
    // - Cannot pass the length of the run back as there will be breaks
    //   in consecutiveness throughout the tree, so pass the length and
    //   longest values forward.
    //
    // Corner cases
    // ------------
    // - root node, parent will be null, len is 1
    // - children of root, gparent will be null

    int longest = 0;
    helper(nullptr, nullptr, root, 0, longest);
    return longest;
  }

protected:
  static void helper(const TreeNode *gparent, const TreeNode *parent,
                     const TreeNode *node, int len, int &longest) {
    if (nullptr == node) {
      return;
    }
    if (nullptr == parent) {
      len = 1;
    } else {
      // check for increasing
      if (node->val == parent->val + 1) {
        if (nullptr == gparent) {
          len = 2;
        } else {
          if (parent->val == gparent->val + 1) {
            len++;
          } else {
            len = 2;
          }
        }
      } else {
        len = 1;
      }
    }
    if (len > longest) {
      longest = len;
    }
    helper(parent, node, node->left, len, longest);
    helper(parent, node, node->right, len, longest);
  }
};
