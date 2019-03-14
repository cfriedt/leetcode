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

#include <vector>
#include <numeric>

using namespace std;

class Solution {

	// https://leetcode.com/problems/fruit-into-baskets/

public:
    int totalFruit(vector<int>& tree) {
        // the problem here is to find the two largest contiguous blocks that consecutive. It can be done in linear time.

        int total;
        int most = 0;

        array<int,2> basket({-1,-1});
        array<int,2> count({0,0});

        for( int i = 0; i < int( tree.size() ); i++ ) {

            if ( false ) {
            } else if ( basket[0] == tree[ i ] ) {
                count[ 0 ]++;
            } else if ( basket[ 1 ] == tree[ i ] ) {
                count[ 1 ]++;
            } else if ( -1 == basket[ 0 ] ) {
                basket[ 0 ] = tree[ i ];
                count[ 0 ] = 1;
            } else if ( -1 == basket[ 1 ] ) {
                basket[ 1 ] = tree[ i ];
                count[ 1 ] = 1;
            } else {
                total = accumulate( count.begin(), count.end(), 0 );
                cout << "total: " << total << endl;
                if ( total > most ) {
                    most = total;
                    cout << "most: " << most << endl;
                }

		basket[ 0 ] = basket[ 1 ];
		count[ 0 ] = count[ 1 ];
		basket[ 1 ] = tree[ i ];
		count[ 1 ] = 1;
            }
            cout << basket[ 0 ] << ":" << count[ 0 ] << ", " << basket[ 1 ] << ":" << count[ 1 ] << endl;
        }

        total = accumulate( count.begin(), count.end(), 0 );
        cout << "total: " << total << endl;
        if ( total > most ) {
            most = total;
            cout << "most: " << most << endl;
        }

        return most;
    }
};
