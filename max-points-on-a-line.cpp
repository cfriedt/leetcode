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

int gcd(int a, int b) {
  if (b > a) {
    swap(a, b);
  }

  for (; b != 0;) {
    auto t = b;
    b = a % b;
    a = t;
  }

  return a;
}

void reduce(int &num, int &den) {
  if (den == 0) {
    num = INT_MAX;
  }

  if (num == 0 || den == 0) {
    return;
  }

  int sign = +1;
  if (num < 0 && den < 0) {
    num = -num;
    den = -den;
  }

  if (num < 0) {
    sign = -1;
    num = -num;
  }
  if (den < 0) {
    sign = -1;
    den = -den;
  }

  if ((num % den) == 0 && den != 1) {
    num /= den;
    den /= den;
  }

  do {
    int d = gcd(num, den);
    if (d == 1) {
      break;
    }
    num /= d;
    den /= d;
  } while (true);

  num = sign * num;
}

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
  Slope() : Slope(Point(), Point()) {}
  Slope(Point a, Point b) : Slope(b.y - a.y, b.x - a.x) {}
  Slope(int num, int den) : num(num), den(den) {
    reduce(this->num, this->den);
    if (this->num == 0) {
      this->den = 1;
    }
  }
  int num;
  int den;
  bool operator==(const Slope &o) const { return num == o.num && den == o.den; }
};

namespace std {
template <> struct hash<Slope> {
  size_t operator()(const Slope &m) const {
    return ((hash<int>()(m.num) ^ (hash<int>()(m.den) << 1)) >> 1);
  }
};
} // namespace std

struct Intercept {
  Intercept() : Intercept(Point(), Point()) {}
  Intercept(Point a, Point b) : Intercept(b, Slope(a, b)) {}
  Intercept(Point a, Slope m) : m(m) {
    if (m.num == INT_MAX) {
      // In this case, we are representing a vertical line
      // store the x-intercept in (num, den)
      num = a.x;
      den = 1;
    } else {
      // store the y-intercept in (num, den)
      num = int(m.den * int64_t(a.y) - m.num * int64_t(a.x));
      den = m.den;
    }
    reduce(num, den);

    if (m.num != INT_MAX && num == 0) {
      den = 1;
    }
  }
  Slope m;
  int num;
  int den;
  bool operator==(const Intercept &o) const {
    return num == o.num && den == o.den && m == o.m;
  }
};

namespace std {
template <> struct hash<Intercept> {
  size_t operator()(const Intercept &i) const {
    return ((hash<Slope>()(i.m) ^ (hash<Slope>()(Slope(i.num, i.den)) << 1)) >>
            1);
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
        //        clog << "a: (" << keys[i].x << ", " << keys[i].y << ") "
        //             << "-> "
        //             << "b: (" << keys[j].x << ", " << keys[j].y << ") "
        //             << "m: " << m.num << "/" << m.den
        //             << ": with_slope[m]: " << with_slope[m] << endl;
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
