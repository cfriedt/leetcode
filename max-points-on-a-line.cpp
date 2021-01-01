/*
 * MIT License
 *
 * Copyright (c) 2020 Christopher Friedt
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

#include <limits.h>

#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct Point {
  Point() : Point(0, 0) {}
  Point(int x, int y) : x(x), y(y) {}
  int x;
  int y;
  bool operator==(const Point &o) const { return x == o.x && y == o.y; }
};

namespace std {
template <> struct hash<Point> {
  size_t operator()(const Point &p) const {
    return ((hash<int>()(p.x) ^ (hash<int>()(p.y) << 1)) >> 1);
  }
};
} // namespace std

struct Intercept {
  Intercept() : Intercept(0, 0) {}
  Intercept(Point a, Point b) : Intercept(0, 0) {
    m = double(b.y - a.y) / double(b.x - a.x);
    y = a.y - m * a.x;
  }
  Intercept(double y, double m) : y(y), m(m) {}
  double y;
  double m;
  bool operator==(const Intercept &o) const { return y == o.y && m == o.m; }
  bool operator!=(const Intercept &o) const { return y != o.y || m != o.m; }
};

namespace std {
template <> struct hash<Intercept> {
  size_t operator()(const Intercept &i) const {
    return ((hash<double>()(i.y) ^ (hash<double>()(i.m) << 1)) >> 1);
  }
};
} // namespace std

class Solution {
public:
  int maxPoints(vector<vector<int>> &points) {
    // in one loop: O(N) - first order
    // - increment entries in an undered_map<Point,size_t> "count" to account
    // for duplicates
    // - add points to an unordered_map<int,size_t> with the X value of each
    // point acting as the key
    //   - that is sufficient to describe vertical lines
    //   - maintain a maxpoints variable that is updated with each new addition
    // - add points to an unordered_map<int,size_t> with the Y value of each
    // point acting as the key
    //   - that is sufficient to describe horizontal lines
    //   - maintain a maxpoints variable that is updated with each new addition
    //
    // shortcut: O(1)
    // - here, if mapoints == points.size(), we can exit early
    //
    // - create an unordered_map<Intercept, size_t> "icept"
    //
    // in the next loop: O(N^3) - higher-order
    // - for each unique pair (2-tuple) of points in count: O(N^2)
    //   - if points are equal, do not generate the pair, they can be skipped
    //   - if points share an X or Y coordinate (i.e. are vertical or
    //   horizontal) they can be skipped
    //   - from the pair of points, a point + unit vector can be extracted
    //   - but more importantly, a y-intercept plus slope can be extracted
    //   (let's just call this the intercept)
    //   - that is sufficient to describe diagonal lines
    //   - if a particular intercept exists in icept the map already, then
    //   continue
    //   - for each other unique point, check if an identical intercept with one
    //   of the earlier points can be made: O(N)
    //     - if so, increment icept for the current intercept
    //     - maintain a maxpoints variable that is updated with each new
    //     addition
    //
    //
    // Given that this O(N^3) solutions are rarely ever seen as a successful
    // (even though this one works) I would probably be inclined to wonder about
    // possible DP solutions.

    unordered_map<Point, size_t> count;
    unordered_map<int, size_t> vert;
    unordered_map<int, size_t> horiz;
    unordered_map<Intercept, size_t> icept;
    size_t maxpoints = 0;

    for (auto &p : points) {
      int x = p[0];
      int y = p[1];
      count[Point(x, y)]++;

      vert[x]++;
      maxpoints = max(maxpoints, vert[x]);

      horiz[y]++;
      maxpoints = max(maxpoints, horiz[y]);
    }

    if (maxpoints == points.size()) {
      return maxpoints;
    }

    for (auto aa : count) {
      for (auto bb : count) {
        auto a = aa.first;
        auto b = bb.first;

        if (a == b) {
          continue;
        }
        if (a.x == b.x || a.y == b.y) {
          continue;
        }
        auto x = Intercept(a, b);
        if (icept.end() != icept.find(x)) {
          continue;
        }

        icept[x] += count[a] + count[b];
        maxpoints = max(maxpoints, icept[x]);

        for (auto cc : count) {
          auto c = cc.first;
          if (a == c || b == c) {
            continue;
          }
          auto t = Intercept(a, c);
          if (t != x) {
            continue;
          }

          icept[x] += count[c];
          maxpoints = max(maxpoints, icept[x]);
        }
      }
    }
    return maxpoints;
  }
};
