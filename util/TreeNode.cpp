/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <deque>

#include "TreeNode.hpp"

using namespace std;

// see serialize-and-deserialize-binary-tree.cpp

static size_t TreeNode_size(TreeNode *node) {
  if (nullptr == node) {
    return 0;
  }

  return TreeNode_size(node->left) + TreeNode_size(node->right) + 1;
}

string TreeNode_to_string(TreeNode *root) {
  // fifo for BFS (push to back)
  size_t N = TreeNode_size(root);
  size_t n = 0;
  deque<TreeNode *> fifo;
  stringstream ss;
  ss << "[";

  if (root != nullptr) {
    fifo.push_back(root);
  }

  while (!fifo.empty()) {
    TreeNode *node = fifo.front();
    fifo.pop_front();

    if (node == nullptr) {
      ss << "null,";
      continue;
    }

    ss << node->val << ",";
    ++n;
    if (n >= N) {
      break;
    }

    fifo.push_back(node->left);
    fifo.push_back(node->right);
  }

  ss << "]";

  string data = ss.str();
  if (*(data.end() - 2) == ',') {
    data.erase(data.end() - 2);
  }

  // cout << "serialize: data: " << data << endl;

  return data;
}

TreeNode *TreeNode_from_string(string data) {

  // cout << "deserialize: data: " << data << endl;

  data.erase(data.begin());
  data.erase(data.end() - 1);

  if (data.empty()) {
    return nullptr;
  }

  TreeNode *root = nullptr;
  deque<TreeNode *> fifo;
  TreeNode *parent = nullptr;
  bool left = true;

  stringstream ss(data);
  while (ss.good()) {
    string s;
    getline(ss, s, ',');

    // cout << "deserialize: s: " << s << endl;

    TreeNode *node;

    if (s == "null") {
      node = nullptr;
    } else {
      node = new TreeNode(stoi(s));
      if (root == nullptr) {
        root = node;
      }

      fifo.push_back(node);
    }

    if (nullptr == parent) {
      parent = fifo.front();
      fifo.pop_front();
    }

    if (parent == node) {
      continue;
    }

    if (left) {
      left = false;
      parent->left = node;
    } else {
      left = true;
      parent->right = node;
      parent = fifo.front();
      fifo.pop_front();
    }
  }

  return root;
}

void TreeNode_cleanup(TreeNode *node) {
#if 0
  // After refactoring util/TreeNode, there are now a number of
  // double-free abort() cases. We will let the kernel free
  // allocated memory when the process exits and fix individual
  // tests later.
  if (nullptr == node) {
    return;
  }

  if (node->left != nullptr) {
    TreeNode_cleanup(node->right);
  }

  if (node->right != nullptr) {
    TreeNode_cleanup(node->right);
  }

  delete (node);
#else
  (void)node;
#endif
}
