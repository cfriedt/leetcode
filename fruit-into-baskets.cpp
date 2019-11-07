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

#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {

	// https://leetcode.com/problems/fruit-into-baskets/

public:

	int totalFruit(vector<int>& tree) {
	    const size_t N = tree.size();
	    if ( N < 3 ) {
            return int( N );
	    }
        size_t largest = 0;
        bool grow = true;
        unordered_map<int,size_t> basket;
        size_t M;
        for( size_t L = 0, R = 0; L < N - 2 && R < N; ) {
            if ( grow ) {
                M = basket.size();
                for( ;R < N && M < 2; R++ ) {
                    auto it = basket.find( tree[ R ] );
                    if ( basket.end() == it ) {
                        basket[ tree[ R ] ] = 1;
                        M++;
                    } else {
                        it->second++;
                    }
                }
                for( ;R < N; R++ ) {
                    auto it = basket.find( tree[ R ] );
                    if ( basket.end() == it ) {
                        break;
                    }
                    basket[ tree[ R ] ]++;
                }
                largest = max( largest, R - L );
                grow = false;
            } else {
                M = basket.size();
                for( ;L < R && M >= 2; L++ ) {
                    basket[ tree[ L ] ]--;
                    if ( 0 == basket[ tree[ L ] ] ) {
                        basket.erase( tree[ L ] );
                        M--;
                    }
                }
                grow = true;
            }
        }
	    return int( largest );
	}
};
