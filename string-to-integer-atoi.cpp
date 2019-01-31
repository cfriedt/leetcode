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

#include <array>
#include <climits>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:

	// https://leetcode.com/problems/string-to-integer-atoi

	int myAtoi( string str ) {
		for( ; str.length() > 0 && ' ' == str[ 0 ]; str = str.substr( 1 ) );
		if ( 0 == str.length() ) {
			return 0;
		}
		int sign = '-' == str[ 0 ] ? -1 : +1;
		if ( '-' == str[ 0 ] || '+' == str[ 0 ] ) {
			str = str.substr( 1 );
		}

		if ( str[ 0 ] < '0' || str[ 0 ] > '9' ) {
			return 0;
		}

		array<uint8_t,10> decimal_digits;
		fill( decimal_digits.begin(), decimal_digits.end(), 0 );
		size_t highest_pos = 0;
		for( size_t i = 0; str[ 0 ] >= '0' && str[ 0 ] <= '9'; str = str.substr( 1 ), i++ ) {
            if ( '0' == str[ 0 ] && 0 == i ) {
				i--;
				continue;
			}

            if ( i >= decimal_digits.size() ) {
                if ( sign > 0 ) {
					return INT_MAX;
				} else {
					return INT_MIN;
				}
            }

			decimal_digits[ i ] = str[ 0 ] - '0';
			highest_pos = i;
		}
		reverse( decimal_digits.begin(), decimal_digits.begin() + highest_pos + 1 );

		int accumulator = 0;
		for( size_t i = 0, fac = 1; i <= highest_pos; i++, fac *= 10 ) {
			uint64_t diff = ( (uint64_t(1) << 31) - 1 ) - accumulator;
			uint64_t xx = decimal_digits[ i ] * fac;
			if ( xx > diff ) {
				if ( sign > 0 ) {
					return INT_MAX;
				} else {
					return INT_MIN;
				}
			}
			accumulator += xx;
		}

		return accumulator * sign;
	}
};
