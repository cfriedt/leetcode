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
#include <bitset>
#include <iostream>
#include <iomanip>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:

	// https://leetcode.com/problems/minimum-unique-word-abbreviation
	// Borrowed heavily from the concepts here:
	// https://leetcode.com/problems/minimum-unique-word-abbreviation/discuss/89887/3ms-C%2B%2B-bit-manipulation-solution-beat-100

	string minAbbreviation(string target, vector<string>& dictionary) {

		const size_t M = target.size();

		string result;

		unordered_set<uint32_t> dict;

		for( auto & word: dictionary ) {
			if ( word.size() != M ) {
				continue;
			}
			uint32_t key = getKey( target, word );
			dict.insert( key );
			cerr << setw( 32 ) << word << endl;
			cerr << bitset<32>( key ) << endl;
		}

		if ( dict.empty() ) {
			cerr << "dict is empty!" << endl;
			result = to_string( M );
			cerr << "result is " << result << endl;
			return result;
		}

		uint32_t optional = conjoin_if_2_or_more_bits_set( dict );
		cerr << "optional mask is " << bitset<32>( optional ) << endl;

		uint32_t required = disjoin_if_1_bit_set( dict );
		cerr << "required mask is " << bitset<32>( required ) << endl;

		uint32_t mask;
		if ( 0 == required ) {
			cerr << "no required bits" << endl;

			if ( countBits32( optional ) == M ) {

				cerr << "all bits optional" << endl;

				mask = 1 << ( M - 1 );

			} else if ( countBits32( optional ) == M - 1 ) {

				cerr << "one-hot-bit" << endl;

				if ( 0 == ( optional & 1 ) ) {
					cerr << "at the bottom" << endl;
					mask = 1 << ( M - 1 );
				} else {
					cerr << "at the top" << endl;
					mask = 1;
				}

			} else {
				cerr << "mask is the optional bits, inverted" << endl;
				mask = ~optional;
			}
		} else {
			cerr << "mask is optional | requried" << endl;
			mask = optional | required;
		}

		cerr << "mask is " << bitset<32>( mask ) << endl;

		string nulled = applyMask( mask, target );

		cerr << "nulled is " << nulled << endl;

		string numbered = countBlanks( nulled );

		result = numbered;

		cerr << "result is " << result << endl;

		return result;
	}

protected:

	static constexpr char NULL_MARKER = '_';

	static uint32_t getKey( const string & target, const string & word ) {

		const size_t M = min( target.size(), word.size() );

		uint32_t key;
		size_t i;

		for( i = 0, key = 0; i < M; i++ ) {
			key <<= 1;
			key += ( target[ i ] == word[ i ] ) ? 0 : 1;
		}

		return key;
	}

	static uint32_t conjoin_if_2_or_more_bits_set( const unordered_set<uint32_t> & dict ) {
		uint32_t x = 0;
		for( auto & w: dict ) {
			size_t bits_set = countBits32( w );
			if ( bits_set >= 2 ) {
				if ( 0 == x ) {
					x = w;
				} else {
					x &= w;
				}
			}
		}
		return x;
	}

	static uint32_t disjoin_if_1_bit_set( const unordered_set<uint32_t> & dict ) {
		uint32_t x = 0;
		for( auto & w: dict ) {
			size_t bits_set = countBits32( w );
			if ( 1 == bits_set ) {
				x |= w;
			}
		}
		return x;
	}

	static size_t countBits32( uint32_t word ) {
		return
			0
			+ countBits8( word >>  0 )
			+ countBits8( word >>  8 )
			+ countBits8( word >> 16 )
			+ countBits8( word >> 24 )
			;
	}

	static size_t countBits8( uint8_t byte ) {
		static const array<uint8_t,256> lut({
			0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4,
			1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,
			1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,
			2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
			1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,
			2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
			2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
			3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,
			1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,
			2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
			2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
			3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,
			2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
			3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,
			3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,
			4,5,5,6,5,6,6,7,5,6,6,7,6,7,7,8,
		});
		return lut[ byte ];
	}

	static string applyMask( uint32_t mask, const string & target ) {
		const size_t M = target.size();
		string r = target;
		for( size_t i = 0; i < M; i++ ) {
			if ( 0 == ( ( mask >> ( M - i - 1 ) ) & 1 ) ) {
				r[ i ] = NULL_MARKER;
			}
		}
		return r;
	}

	static string countBlanks( const string & nulled ) {
		const size_t M = nulled.size();
		string r;
		for( size_t i = 0; i < M; ) {
			size_t null_count;
			size_t j;
			for( null_count = 0, j = i; j < M && nulled[ j ] == NULL_MARKER; j++, null_count++ );
			if ( null_count ) {
				r += to_string( null_count );
				i += null_count;
			} else {
				r += nulled[ i ];
				i++;
			}
		}
		return r;
	}
};
