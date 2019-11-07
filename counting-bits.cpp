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
#include <vector>

using namespace std;

class Solution {
public:

	// https://leetcode.com/problems/counting-bits/

	vector<int> countBits( int num ) {
	    vector<int> r( num + 1, 0 );
	    for( int i = 0; i <= num; i++ ) {
            r[ i ] = ones( i );
	    }
	    return r;
	}

protected:

	static const array<int,16> lut;

	static int ones( uint8_t x ) {

	    return lut[ x & 0xf ] + lut[ (x >> 4) & 0xf ];
	}

    static int ones( int x ) {
        uint8_t *px = (uint8_t *) & x;
        return ones( px[ 0 ] ) + ones( px[ 1 ] ) + ones( px[ 2 ] ) + ones( px[ 3 ] );
    }
};

const array<int, 16> Solution::lut = array<int, 16> (
    { 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, });
