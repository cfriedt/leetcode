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
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/

using namespace std;

struct node {
  node() : node("", false) {}
  node(string label) : node(label, false) {}
  node(string label, bool leaf) : label(label), leaf(leaf) {
    // cout << "label: " << label << " leaf: " << leaf << endl;
  }

  string label;
  bool leaf;
  unordered_map<string, node *> ch;

  bool insert(string &s) {
    if (leaf) {
      return false;
    }

    // cout << "s: " << s << endl;

    size_t first = s.find_first_of('/');
    if (first == string::npos) {
      // cout << label << "/" << s << "[L]" << endl;
      ch[s] = new node(s, true);
      return true;
    }

    string head = s.substr(0, first);
    string tail = s.substr(first + 1);
    auto it = ch.find(head);
    if (ch.end() == it) {
      ch[head] = new node(head);
    }
    return ch[head]->insert(tail);
  }
};

class Solution {
public:
  vector<string> removeSubfolders(vector<string> &folder) {
    // assume input ordered?
    // O(NlogN)
    sort(folder.begin(), folder.end());

    // Looks like we can process input as it comes in now

    // make a trie, but if inserting under an existing leaf node, give up

    node root;
    unordered_set<string> unique;

    for (auto &s : folder) {
      string sub = s.substr(1);
      if (root.insert(sub)) {
        unique.insert(s);
      }
    }

    vector<string> r;
    for (auto &s : unique) {
      r.push_back(s);
    }

    return r;
  }
};
