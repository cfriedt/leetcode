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
#include <array>

using namespace std;

class Solution {
public:

	int reverse( int x ) {

		// range: [ -(2^31), (2^31) )
		// range: -2147483648 : 2147483647

		if ( 0 == x ) {
			return 0;
		}

		// uint8_t is the smallest supported type that can hold a decimal digit
		// we will have maximally 10 decimal digits
		array<uint8_t,10> decimal_digits;

		int sign = ( x >= 0 ) ? +1 : -1;
		x *= sign;

		size_t highest_pos = 0;

		for( size_t i = 0; i < decimal_digits.size() && x != 0; i++, x /= 10 ) {
			decimal_digits[ i ] = uint8_t( x % 10 );
			highest_pos = i;
		}

		for( size_t i = 0; i <= highest_pos / 2; i++ ) {
			swap( decimal_digits[ i ], decimal_digits[ highest_pos - i ] );
		}

		int accumulator = 0;
		for( size_t i = 0, fac = 1; i <= highest_pos; i++, fac *= 10 ) {
			uint64_t diff = ( (uint64_t(1) << 31) - 1 ) - accumulator;
			uint64_t xx = decimal_digits[ i ] * fac;
			if ( xx > diff ) {
				return 0;
			}
			accumulator += xx;
		}

		return accumulator * sign;
	}
};
