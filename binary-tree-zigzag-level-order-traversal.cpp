/*
 * MIT License
 *
 * Copyright (c) 2018 Christopher Friedt
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
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

