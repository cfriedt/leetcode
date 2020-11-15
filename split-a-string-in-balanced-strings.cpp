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

using namespace std;

class Solution {
public:
  // https://leetcode.com/problems/split-a-string-in-balanced-strings/

  int balancedStringSplit(string s) {

    /*
     * ex
     * RLRRLLRLRL
     *
     * p1 p2 c1 c2 balance npairs
     * 0  1  R  L  0       1
     * 2  3  R  R  -2      1
     * 2  4  R  L  -1      1
     * 2  5  R  L  0       2
     * 6  7  R  L  0       3
     * 8  9  R  L  0       4
     */

    int r = 0;
    int balance = 0;
    for (size_t p1 = 0, p2 = 1, N = s.size(); p1 + 1 < N && p2 < N;) {
      if ((0 == p1 && 1 == p2) || 0 == balance) {
        balance += (s[p1] == 'R') ? -1 : 1;
      }

      balance += (s[p2] == 'R') ? -1 : 1;

      if (0 == balance) {
        ++r;
        p1 = p2 + 1;
        p2 += 2;
      } else {
        ++p2;
      }
    }

    return r;
  }
};
