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

#include <array>
#include <string>
#include <vector>

using namespace std;

static inline uint8_t toByte(vector<int> v) {
  uint8_t r = 0;
  for (auto &e : v) {
    r <<= 1;
    r |= e & 1;
  }
  return r;
}

static inline vector<int> fromByte(uint8_t x) {
  vector<int> v(8, 0);
  for (int8_t i = 7; i >= 0; --i, x >>= 1) {
    v[i] = x & 1;
  }
  return v;
}

constexpr size_t COLS = 256;  // 2^8 for all possible byte values
constexpr size_t ROWS = 4096; // "period"

class Solution {
public:
  uint8_t nextState(array<uint8_t, ROWS * COLS> &dp, uint8_t s) {
    if (dp[s] != 0xff) {
      return dp[s];
    }
    uint8_t r = 0;
    for (uint8_t k = 1; k < 7; ++k) {
      // s-section
      uint8_t ss = (s >> (k - 1)) & 0b101;
      if (0b101 == ss || 0b000 == ss) {
        r |= (1 << k);
      }
    }
    dp[s] = r;
    return r;
  }

  uint8_t panda(array<uint8_t, ROWS * COLS> &dp, uint8_t s, int N) {

    if (N == 0) {
      cout << hex << setw(2) << setfill('0') << int(s) << " => " << hex
           << setw(2) << setfill('0') << int(s) << endl;
      return s;
    }

    size_t row = N - 1;
    size_t col = s;
    size_t i = row * COLS + col;

    if (dp[i] == 0xff) {
      if (N == 1) {
        dp[i] = nextState(dp, s);
      } else {
        dp[i] = panda(dp, nextState(dp, s), N - 1);
      }
    }

    return dp[i];
  }

  vector<int> prisonAfterNDays(vector<int> &cells, int N) {
    // since the cells are length 8, we can represent it as a byte
    // create a LUT to reuse values

    // AHA!!
    // for small values of N, the above works fine. However, for
    // N >> 256 (e.g. 10^9) it becomes apparent that we want to
    // not look up simply the next state, but the state several
    // iterations from now.
    // Recursion + Overlapping Subproblems => DP
    // We don't want to consume too much memory though, and in fact,
    // it would probably be beneficial keep our LUT within the size
    // of the L1 cache (< 256kB). Additionally, we don't want our "period"
    // to be so long that it's never repeated in practice
    // Without more information, I would just use 256*256 = 65kB of
    // dp memory.

    array<uint8_t, ROWS * COLS> dp;
    dp.fill(0xff);
    uint8_t s = toByte(cells);

    for (int chunk = min(N, int(ROWS)); N > int(ROWS);
         N -= chunk, chunk = min(N, int(ROWS))) {
      s = panda(dp, s, chunk);
    }

    return fromByte(panda(dp, s, N));
  }
};
