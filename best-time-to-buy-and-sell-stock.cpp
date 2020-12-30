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

#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    // the naive solution is O(N^2)
    // max_profit = 0;
    // for (int i = 0; i < prices.size(); ++i) {
    //    int buy_price = prices[i];
    //    for(int j = i + 1; j < prices.size(); ++j) {
    //       int sell_price = prices[j];
    //       int profit = sell_price - buy_price;
    //       if (profit > max_profit) {
    //          max_profit = profit;
    //       }
    //    }
    // }
    // return max_profit;

    // We need to do better than O(N^2).
    // - O(logN) impossible because we must consider all prices (so >= O(N))
    // - O(N) can we do this using DP?
    //
    // 1. Can the ideal solution be expressed using a recursion?
    //    for each day, i
    //    MP(i) = 0: if i == -1
    //          = MP(i-1): if profit(i) <= MP(i-1)
    //          = profit(i), otherwise
    //    profit(i) = sell_price(i) - buy_price(i)
    //              = P[i]          - min(P[0]..P[i])
    // 2. Is there an optimal substructure?
    //    - yes! the MP for each day is a maximization of solutions to
    //    subproblems
    // 3. Are there overlapping subproblems?
    //    - technically no. the "min" problem only requires 1 value to be
    //    remembered
    //    - based on the above, the "MP" problem also only requires a history of
    //    1
    //
    // - just because the problem can be expressed recursively does not imply
    //   it requires a DP solution.
    //
    // - because previous calculations are used at most once, there are not
    // overlapping
    //   subproblems, and therefore it is not a DP solution.
    //
    // Still, can we do it in linear time?
    // - Yes!
    //
    // 4. Initial conditions?
    //  * MP(i) is poorly defined for i = 0, so lets define MP(-1) to be 0
    //  * P[-1] can be considered to be infinity
    // 5. Change of indices.
    //  - let j = i + 1
    //  - we will iterate with j in [0, N], where N is included in the range
    //
    // Example
    // j      | 0   | 1 | 2 | 3 | 4 | 5 | 6
    // -------------------------------------
    // P      | inf | 7 | 1 | 5 | 3 | 6 | 4
    // minp   | -   | 7 | 1 | 1 | 1 | 1 | 1
    // profit | -   | 0 | 0 | 4 | 2 | 5 | 3
    // MP     | 0   | 0 | 0 | 4 | 4 | 5 | 5
    //
    // Now we have done solved the problem in O(N) time!!
    //
    // However, our solution above uses O(N) space as well.
    //
    // Can this be done in O(1) space?? Of course!

    int max_profit = 0;
    int minp = INT_MAX;
    vector<int> &P = prices;

    for (int i = 0, N = P.size(); i < N; ++i) {
      minp = min(minp, P[i]);
      // hypothetical profit if we were to sell today
      int profit = P[i] - minp;
      max_profit = max(max_profit, profit);
    }

    return max_profit;
  }
};
