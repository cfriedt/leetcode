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
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> commonChars(vector<string> &A) {
    vector<string> r;
    set<char> unique; // sorted
    const size_t K = A.size();
    // Will need to go through easy string at least once
    // so the problem will at least be O(KN) ~ O(N^2)
    vector<unordered_map<char, size_t>> counts(K);

    // iterate over elements of A: O(K)
    for (size_t k = 0; k < K; ++k) {
      // iterator over elements of A[k]: O(N)
      for (auto c : A[k]) {
        counts[k][c]++;
        // O(log(26)) => O(1)
        unique.insert(c);
      }
    }

    // maximally O(26) => O(1)
    for (auto c : unique) {
      size_t mmin = size_t(-1);
      // O(K)
      for (size_t k = 0; k < K; ++k) {
        auto it = counts[k].find(c);
        if (counts[k].end() == it) {
          mmin = 0;
          break;
        }
        mmin = min(counts[k][c], mmin);
      }
      // O(1)
      for (size_t i = 0; i < mmin; ++i) {
        r.push_back(string(1, c));
      }
    }

    return r;
  }
};
