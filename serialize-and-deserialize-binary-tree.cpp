/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <deque>

using namespace std;

// name: serialize-and-deserialize-binary-tree
// url: https://leetcode.com/problems/serialize-and-deserialize-binary-tree
// difficulty: 3

class Codec {
public:
  size_t tree_size(TreeNode *node) {
    if (nullptr == node) {
      return 0;
    }

    return tree_size(node->left) + tree_size(node->right) + 1;
  }

  string serialize(TreeNode *root) {
    // fifo for BFS (push to back)
    size_t N = tree_size(root);
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

  TreeNode *deserialize(string data) {

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
};
