/*
 * Copyright (c) 2020 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <algorithm>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {

    // adjacency list of prereqs, slightly more efficient representation
    // than edge list
    vector<vector<int>> adj(numCourses);
    vector<bool> queued(numCourses);
    vector<bool> visited(numCourses, false);

    for (auto &p : prerequisites) {
      auto course = p[0];
      auto req = p[1];
      adj[course].push_back(req);
    }

    // for (auto &p : adj) {
    // cout << "adj[" << p.first << "]: " << p.second << endl;
    //}

    // for each vertex
    for (int v = 0; v < numCourses; ++v) {

      // cout << "DFS starting with " << v << endl;

      if (visited[v]) {
        // cout << "skipping " << v << " as its already visited" << endl;
        continue;
      }

      deque<int> to_visit;
      fill(queued.begin(), queued.end(), false);

      to_visit.push_front(v);

      while (!to_visit.empty()) {

        // recycle 'v'
        v = to_visit.front();

        if (visited[v]) {
          queued[v] = false;
          to_visit.pop_front();
        } else {
          // cout << "visited " << v << endl;
          visited[v] = true;
          queued[v] = true;
        }

        for (const auto &u : adj[v]) {
          if (!visited[u]) {
            to_visit.push_front(u);
          } else if (queued[u]) {
            // if an item is already visited and it is re-queued to visit,
            // it clearly satisfies the criteria for introducing a cycle

            // cout << "cycle detected at " << u << endl;
            return false;
          }
        }
      }
    }

    return true;
  }
};
