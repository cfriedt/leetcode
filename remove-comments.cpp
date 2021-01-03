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

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> removeComments(vector<string> &source) {
    vector<string> out;
    string orphan;
    bool in_block = false;

    for (auto &s : source) {
      size_t i = 0;

      if (in_block) {
        size_t pos2 = s.find("*/");
        if (string::npos == pos2) {
          continue;
        }

        s.erase(0, pos2 + 2);
        s = orphan + s;
        in_block = false;
        i = orphan.size();
      }

      for (; i < s.size();) {
        size_t pos = s.find("/", i);
        if (pos == string::npos) {
          break;
        }

        if (s[pos + 1] != '/' && s[pos + 1] != '*') {
          i = pos + 2;
          continue;
        }

        if (s[pos + 1] == '/') {
          s.erase(pos);
          break;
        }

        if (s[pos + 1] != '*') {
          i = pos + 2;
          continue;
        }

        size_t pos2 = s.find("*/", pos + 2);
        if (string::npos == pos2) {
          s.erase(pos);
          orphan = s;
          in_block = true;
          break;
        }

        s.erase(pos, pos2 - pos + 2);
        i = pos;
      }

      if (!s.empty() && !in_block) {
        out.push_back(s);
      }
    }

    return out;
  }
};
