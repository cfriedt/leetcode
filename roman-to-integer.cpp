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

using namespace std;

// https://leetcode.com/problems/roman-to-integer/

static inline int table1(char c) {
  switch (c) {
  case 'I':
    return 1;
  case 'V':
    return 5;
  case 'X':
    return 10;
  case 'L':
    return 50;
  case 'C':
    return 100;
  case 'D':
    return 500;
  case 'M':
    return 1000;
  default:
    return 0;
  }
}

class Solution {
public:
  int romanToInt(string s) {
    int sum = 0;
    for (int N = s.size(), i = N - 1; i >= 0;) {
      if (N == 0) {
        break;
      }

      char c2 = s[i];
      if (N == 1) {
        sum += table1(c2);
        break;
      }

      char c1 = s[i - 1];
      if (false) {
      } else if (c1 == 'I' && c2 == 'V') {
        sum += 4;
        N -= 2;
        i -= 2;
        continue;
      } else if (c1 == 'I' && c2 == 'X') {
        sum += 9;
        N -= 2;
        i -= 2;
        continue;
      } else if (c1 == 'X' && c2 == 'L') {
        sum += 40;
        N -= 2;
        i -= 2;
        continue;
      } else if (c1 == 'X' && c2 == 'C') {
        sum += 90;
        N -= 2;
        i -= 2;
        continue;
      } else if (c1 == 'C' && c2 == 'D') {
        sum += 400;
        N -= 2;
        i -= 2;
        continue;
      } else if (c1 == 'C' && c2 == 'M') {
        sum += 900;
        N -= 2;
        i -= 2;
        continue;
      }

      sum += table1(c2);
      --i;
      --N;
    }

    return sum;
  }
};
