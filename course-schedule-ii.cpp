/*
 * Copyright (c) 2021 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {

    unordered_map<int, unordered_set<int>> dep;
    unordered_map<int, unordered_set<int>> rdep;
    // First create an depacency list
    for (auto &p : prerequisites) {
      auto &course = p[0];
      auto &req = p[1];
      dep[course].insert(req);
      rdep[req].insert(course);
    }

    // L ← Empty list that will contain the sorted elements
    vector<int> L;
    // S ← Set of all nodes with no incoming edge
    unordered_set<int> S;

    // populate S
    for (int i = 0; i < numCourses; ++i) {
      if (dep.end() == dep.find(i)) {
        S.insert(i);
      }
    }

    // while S is not empty do
    while (!S.empty()) {
      // remove a node n from S
      int n = *(S.begin());
      S.erase(S.begin());
      // add n to L
      L.push_back(n);
      // for each node m with an edge e from n to m do
      for (auto &m : rdep[n]) {
        // remove edge e from the graph
        dep[m].erase(n);
        // if m has no other incoming edges then
        if (dep[m].empty()) {
          // insert m into S
          S.insert(m);
          dep.erase(m);
        }
      }
    }

    // if graph has edges then
    if (!dep.empty()) {
      return vector<int>{};
    }

    // else
    return L; // (a topologically sorted order)
  }
};
