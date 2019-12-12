/*
 * MIT License
 *
 * Copyright (c) 2019 Christopher Friedt
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

#include <array>
#include <cmath>
#include <string>

using namespace std;

// https://leetcode.com/problems/single-row-keyboard/

class Solution {
public:
    int calculateTime(string keyboard, string word) {

        array<uint8_t,26> kbm;

        for( size_t i = 0, M = keyboard.size(); i < M; ++i ) {
            kbm[ keyboard[ i ] - 'a' ] = uint8_t( i );
        }

        int time = 0;
        int8_t prev_pos = 0;
        for( auto & c: word ) {
            c -= 'a';
            int8_t pos = kbm[ c ];
            time += abs( pos - prev_pos );
            prev_pos = pos;
        }

        return time;
    }
};
