/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

// clang-format off
#include "util/TreeNode.hpp"
// clang-format on

#include "serialize-and-deserialize-binary-tree.cpp"

#ifndef NNULL
#define NNULL 4242
#endif

using namespace std;

bool TreeNode_equal(TreeNode *a, TreeNode *b) {
  if (a == b) {
    // cout << a << " == " << b << endl;
    return true;
  }

  if ((a == nullptr) ^ (b == nullptr)) {
    cout << a << " ^ " << b << endl;
    return false;
  }

  // cout << "a->val: " << a->val << " b->val: " << b->val << endl;

  if (a->val != b->val) {
    cout << "a->val: " << a->val << " != b->val: " << b->val << endl;
    return false;
  }

  return TreeNode_equal(a->left, b->left) && TreeNode_equal(a->right, b->right);
}

TEST(SerializeAndDeserializeBinaryTree, empty) {
  Codec ser, deser;
  TreeNode *root = nullptr;
  TreeNode *expected = nullptr;
  EXPECT_EQ(expected, deser.deserialize(ser.serialize(root)));
}

TEST(SerializeAndDeserializeBinaryTree, 1_2_3_null_null_4_5) {
  Codec ser, deser;
  vector<TreeNode> nodes = {
      TreeNode(1),     TreeNode(2), TreeNode(3), TreeNode(NNULL),
      TreeNode(NNULL), TreeNode(4), TreeNode(5),
  };
  TreeNode *root = &nodes[0];
  nodes[0].left = &nodes[1];
  nodes[0].right = &nodes[2];
  nodes[2].left = &nodes[5];
  nodes[2].right = &nodes[6];
  TreeNode *expected = root;
  EXPECT_TRUE(TreeNode_equal(expected, deser.deserialize(ser.serialize(root))));
}

TEST(SerializeAndDeserializeBinaryTree, 1000_nodes_right_children) {
  Codec ser, deser;
  TreeNode *root = new TreeNode(1);
  auto expected = root;
  auto parent = root;
  for (int i = 2; i <= 1000; ++i) {
    TreeNode *node = new TreeNode(i);
    parent->right = node;
  }
  EXPECT_TRUE(TreeNode_equal(expected, deser.deserialize(ser.serialize(root))));
}
