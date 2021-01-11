/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <vector>

using namespace std;

// https://leetcode.com/problems/rectangle-overlap

class Solution {
public:
  bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2) {

    // analysis:
    // exactly 8 comparisons made
    // O( 1 ) time, O( 1 ) space
    //
    // I do use a struct, but that just helps to clarify the code..
    // small space price to pay, but worth it ;-)

    struct rect {
      int x1, y1, x2, y2;
      explicit rect(const vector<int> &v)
          : x1(v[0]), y1(v[1]), x2(v[2]), y2(v[3]) {}
    };

    rect r1(rec1);
    rect r2(rec2);

    if (r1.x2 <= r2.x1 || r1.y1 >= r2.y2 || r1.x1 >= r2.x2 || r1.y2 <= r2.y1)
      return false;

    if (r1.x1 == r1.x2 || r1.y1 == r1.y2 || r2.x1 == r2.x2 || r2.y1 == r2.y2)
      return false;

    return true;
  }
};
