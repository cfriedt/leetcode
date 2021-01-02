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

struct Slope {
  Slope() : Slope(0) {}
  Slope(Point a, Point b) : Slope(0) {
    int num = b.y - a.y;
    int den = b.x - a.x;
    if (den == 0) {
      m = numeric_limits<double>::infinity();
    } else {
      m = double(num) / double(den);
    }
  }
  Slope(double m) : m(m) {}
  double m;
  bool operator==(const Slope &o) const { return m == o.m; }
};

namespace std {
template <> struct hash<Slope> {
  size_t operator()(const Slope &m) const { return hash<double>()(m.m); }
};
} // namespace std

struct Intercept {
  Intercept() : Intercept(0, 0) {}
  Intercept(Point a, Point b) : Intercept(0, 0) {
    m = double(b.y - a.y) / double(b.x - a.x);
    y = a.y - m * a.x;
  }
  Intercept(Point a, Slope m) : Intercept(0, 0) {
    this->m = m.m;
    y = a.y - this->m * a.x;
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
    unordered_map<Point, size_t> count;
    size_t maxpoints = 0;

    for (auto &p : points) {
      int x = p[0];
      int y = p[1];
      count[Point(x, y)]++;
    }

    vector<Point> keys;
    for (auto kv : count) {
      keys.push_back(kv.first);
    }

    const size_t N = keys.size();

    if (keys.size() == 1) {
      return count[keys[0]];
    }

    unordered_map<Intercept, size_t> icept;

    for (size_t i = 0; i < N; ++i) {
      unordered_map<Slope, size_t> with_slope;
      for (size_t j = i + 1; j < N; ++j) {
        auto ic = Intercept(keys[i], keys[j]);
        if (icept.end() != icept.find(ic)) {
          continue;
        }
        auto m = Slope(keys[i], keys[j]);
        if (with_slope[m] == 0) {
          with_slope[m] += count[keys[i]];
        }
        with_slope[m] += count[keys[j]];
        // cout
        //     << "a: (" << keys[i].x << ", " << keys[i].y << ") "
        //     << "-> "
        //     << "b: (" << keys[j].x << ", " << keys[j].y << ") "
        //     << "m: " << float(m.m)
        //     << ": with_slope[m]: " << with_slope[m] << endl;
        maxpoints = max(maxpoints, with_slope[m]);
      }

      for (auto kv : with_slope) {
        auto m = kv.first;
        auto n = kv.second;
        icept[Intercept(keys[i], m)] = n;
      }
    }

    return maxpoints;
  }
};
