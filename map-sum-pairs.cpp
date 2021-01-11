/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

// https://leetcode.com/problems/map-sum-pairs/

#include <array>
#include <memory>
#include <unordered_map>

using namespace std;

class MapSum {
public:
  struct trie_node {
    int val;
    array<shared_ptr<trie_node>, 26> child;
    trie_node() : trie_node(int(0)) {}
    explicit trie_node(int val) : val(val) {}
  };
  shared_ptr<trie_node> root;

  /** Initialize your data structure here. */
  MapSum() { root = make_shared<trie_node>(); }

  void insert(string key, int val) {
    auto node = root;
    for (size_t i = 0; i < key.length(); i++) {
      size_t c = size_t(key[i]) - size_t('a');
      if (i == key.length() - 1) {
        if (!node->child[c]) {
          node->child[c] = make_shared<trie_node>(val);
        } else {
          node->child[c]->val = val;
        }
        break;
      }
      if (!node->child[c]) {
        node->child[c] = make_shared<trie_node>();
      }
      node = node->child[c];
    }
  }

  static int sum_helper(shared_ptr<trie_node> node) {
    int r = node->val;
    for (auto c : node->child) {
      if (c) {
        r += sum_helper(c);
      }
    }
    return r;
  }
  int sum(string prefix) {
    auto node = root;
    for (auto ch : prefix) {
      size_t c = size_t(ch) - size_t('a');
      auto next = node->child[c];
      if (!next) {
        return 0;
      }
      node = next;
    }
    return sum_helper(node);
  }
};
