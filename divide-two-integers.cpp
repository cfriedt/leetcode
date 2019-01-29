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
#include <climits>

using namespace std;

class Solution {
public:

	// https://leetcode.com/problems/divide-two-integers

    int divide(int dividend, int divisor) {

        if ( 0 == dividend ) {
            return 0;
        }

        if ( 1 == divisor ) {
            return dividend;
        }

        if ( -1 == divisor && INT_MIN == dividend ) {
            return INT_MAX;
        }

        if ( -1 == divisor ) {
            return - dividend;
        }

        int quotient = 0;

        if ( INT_MIN == dividend && INT_MIN == divisor ) {
        	return 1;
        }

        if ( INT_MIN == dividend ) {
            quotient++;
            dividend += abs( divisor );
        }

        if ( INT_MIN == divisor ) {
        	return 0;
        }

        bool neg = ( dividend > 0 && divisor < 0 ) || ( dividend < 0 && divisor > 0 );

        dividend = abs( dividend );
        divisor = abs( divisor );

        for( ;; ) {

            // return integer version of dividend / divisor
            if ( 0 == dividend ) {
                break;
            }

            if ( divisor > dividend ) {
                break;
            }

            quotient++;
            dividend -= divisor;
        }

        if ( neg ) {
            quotient = - quotient;
        }

        return quotient;
    }
};
