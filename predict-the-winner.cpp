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

#include <climits>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:

	// https://leetcode.com/problems/predict-the-winner/

	bool PredictTheWinner(vector<int>& nums) {
        // This is a DP problem because
        // 1) there are overlapping subproblems
        // 2) an optimal substructure

        // To illustrate, let's look at the [1,5,2] example
        //
        //                            (0,[1,5,2])
        //                               max (bc it's player 1's turn)
        //            (1,[5,2])                         (-2,[1,5])
        //              min (bc it's player 2's turn)
        //      (6,[2])      (-1,[5])
        //        max           max
        //  (8,[]) (4,[])  (4,[])  (-6,[])

        const size_t N = nums.size();
        vector<vector<int>> cache( N, vector<int>( N, INT_MIN  ) );

        return helper( nums, 0, N - 1, cache ) >= 0;
	}

protected:
	static int helper( const vector<int> & nums, size_t l, size_t r, vector<vector<int>> & cache ) {
        if ( l == r ) {
            return 0;
        }
        if ( INT_MIN != cache[ l ][ r ] ) {
            return cache[ l ][ r ];
        }
        int a = nums[ l ] - helper( nums, l + 1, r, cache );
        int b = nums[ r ] - helper( nums, l, r - 1, cache );
        cache[ l ][ r ] = max( a, b );
        return cache[ l ][ r ];
	}
};
