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

#include <string>
#include <vector>

using namespace std;

class Solution {

public:

    // https://leetcode.com/problems/optimal-division

    string optimalDivision(vector<int>& nums) {
        size_t N = nums.size();
        if ( N > 2 ) {
            string s( to_string( nums[ 0 ] ) + "/(" + to_string( nums[ 1 ] ) );
            for( size_t i = 2; i < N; i++ ) {
                s += "/" + to_string( nums[ i ] );
            }
            s += ")";
            return s;
        } else if ( 2 == N ) {
            return to_string( nums[ 0 ] ) + "/" + to_string( nums[ 1 ] );
        } else if ( 1 == N ) {
            return to_string( nums[ 0 ] );
        } else {
            return "";
        }
    }
};
