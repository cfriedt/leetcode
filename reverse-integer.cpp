/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
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
