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

using namespace std;

class Solution {
public:

	// https://leetcode.com/problems/masking-personal-information/

	string maskPII(string S) {
		//
		// Assumptions
		// - In short, we are looking for email addresses and phone numbers and transforming /
		//   masking them
		// - Just re-read that S is *either* a phone number of email address. I.e. there
		//   is no other noise per se.
		// - Let's assume that the phone number *must* begin with a number or, if it's
		//   an international number, it must begin with a country code.
		// - assume there is no leading or trailing whitespace.
		//
		// Observations
		//
		// This can be done linearly, with only a couple of extra variables that are
		// the same size as the output variables. So the algorithm is O(N) time and
		// O(1) space.

		switch( S[ 0 ] ) {
		case 'a'...'z':
		case 'A'...'Z':
			// an email
			return maskEmail( S );
		default:
			return maskNumber( S );
		}
	}

protected:
	string maskNumber( string S ) {
		string number("+***-***-***-xxxx");
		size_t i;
		size_t j;
		size_t k;
		for( i = S.size() - 1, j = number.size() - 1, k = 0; i != size_t(-1); i-- ) {
			if ( ::isdigit( S[ i ] ) ) {
				if ( j >= 13 )  {
					number[ j ] = S[ i ];
				}
				j--;
				if ( '-' == number[ j ] ) {
					j--;
				}
				k++;
			}
		}
		if ( 10 == k ) {
			number = number.substr( 5 );
		} else {
			if ( j > 0 ) {
				number[ j ] = '+';
				number = number.substr( j );
			}
		}
		return number;
	}
	string maskEmail( string S ) {
		string user( "x*****x" );
		user[ 0 ] = ::tolower( S[ 0 ] );
		size_t i;
		for( i = 1; i < S.size() && S[ i ] != '@'; i++ );
		user[ user.size() - 1 ] = ::tolower( S[ i - 1 ] );
		user += S.substr( i );
		for( i = 8 ; i < user.size(); user[i] = ::tolower( user[ i ] ), i++ );
		return user;
	}
};
