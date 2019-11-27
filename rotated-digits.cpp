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

#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int rotatedDigits(int N) {

        int total = 0;

        for( int x = 1; x <= N; x++ ) {
            int xx;
            int digit;
            int y;
            int k;

            for( k = 1, xx = x, digit = xx % 10, y = 0; xx; xx /= 10, digit = xx % 10, k *= 10 ) {
                if ( 3 == digit || 4 == digit || 7 == digit ) {
                    goto just_continue;
                }
                if ( !( 0 == digit || 1 == digit || 8 == digit ) ) {
                    switch( digit ) {
                    case 2: digit = 5; break;
                    case 5: digit = 2; break;
                    case 6: digit = 9; break;
                    case 9: digit = 6; break;
                    }
                }
                y += k * digit;
            }

            // the number must be changed
            if ( x == y ) {
                continue;
            }

            total++;

just_continue:
             continue;
        }

        return total;
    }
};

