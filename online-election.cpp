/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// https://leetcode.com/problems/online-election/

class TopVotedCandidate {

protected:
  struct ent {
    int time;
    int candidate; // candidate who received vote at 'time' (i.e. most recent)
    int leader;
    int leader_count;
    ent() : time(0), candidate(0), leader(0), leader_count(0) {}
    ent(int time, int candidate, int leader,
        int leader_count /* , unordered_map<int,int> tally  */)
        : time(time), candidate(candidate), leader(leader),
          leader_count(leader_count) /* , tally( tally ) */
    {}
  };

public:
  TopVotedCandidate(vector<int> &persons, vector<int> &times) : times(times) {
    size_t N = times.size();

    ea = vector<ent>(N, ent());
    unordered_map<int, int> tally;

    for (size_t i = 0; i < N; i++) {
      int leader_count;
      int leader;

      if (0 == i) {
        leader_count = -1;
        leader = -1;
      } else {
        leader_count = ea[i - 1].leader_count;
        leader = ea[i - 1].leader;
      }
      int candidate = persons[i];
      auto it = tally.find(candidate);
      if (tally.end() == it) {
        tally[candidate] = 1;
      } else {
        it->second++;
      }
      if (tally[candidate] >= leader_count) {
        leader_count = tally[candidate];
        leader = candidate;
        // cerr << "candidate " << candidate << " took the lead at time " <<
        // times[ i ] << " with a score of " << leader_count << endl;
      }
      ea[i] = ent(times[i], candidate, leader, leader_count);
    }
  }

  static int compare(int t, int t1, int t2) {
    if (t >= t1 && (-1 == t2 || t < t2)) {
      return 0;
    }
    if (t < t1) {
      return -1;
    }
    // -1 != t2 && t >= t2
    return +1;
  }

  int q(int t) {

    int i = 0;
    for (int L = 0, U = times.size() - 1; L <= U;) {
      int M = (L + U) / 2;
      int direction =
          compare(t, times[M], (M < (int)times.size() - 1) ? times[M + 1] : -1);
      if (0 == direction) {
        i = M;
        break;
      }
      if (direction < 0) {
        U = M;
      }
      if (direction > 0) {
        if (U - L == 1 && M == L) {
          L = U;
        } else {
          L = M;
        }
      }
    }

    return ea[i].leader;
  }

protected:
  vector<int> times;
  vector<ent> ea;

  static unordered_map<int, int> add(const unordered_map<int, int> &a,
                                     const unordered_map<int, int> &b) {
    unordered_map<int, int> c = a;
    for (auto &kv : b) {
      c[kv.first] += kv.second;
    }
    return c;
  }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
