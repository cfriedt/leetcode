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
#include <string>

using namespace std;

// https://leetcode.com/problems/license-key-formatting/

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
	string R;

        // filter dashes and convert S to uppercase, also reverse it
        for( int i = S.size() -1; i >= 0; --i ) {
            if ( '-' == S[i] ) continue;
            R += ::toupper(S[i]);
        }
        S = R;
        R.clear();

        // format R so that it is in sets of K separated by a dash
        for( size_t i = 0, I = S.size(), k = 0; i < I; ++i, ++k, k %= K ) {
            R += S[ i ];
            if ( int(k) == K - 1 && i < I - 1 ) {
                R += '-';
            }
        }

        reverse( R.begin(), R.end() );

        return R;
    }
};

