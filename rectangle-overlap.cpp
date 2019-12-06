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

using namespace std;

// https://leetcode.com/problems/rectangle-overlap

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {

    	// analysis:
    	// exactly 8 comparisons made
    	// O( 1 ) time, O( 1 ) space
    	//
    	// I do use a struct, but that just helps to clarify the code..
    	// small space price to pay, but worth it ;-)

    	struct rect {
    	    int x1, y1, x2, y2;
    	    explicit rect( const vector<int> & v ) : x1( v[ 0 ] ), y1( v[ 1 ] ), x2( v[ 2 ] ), y2( v[ 3 ] ) {}
    	};

        rect r1( rec1 );
        rect r2( rec2 );

        if ( r1.x2 <= r2.x1 || r1.y1 >= r2.y2 || r1.x1 >= r2.x2 || r1.y2 <= r2.y1 ) return false;

        if ( r1.x1 == r1.x2 || r1.y1 == r1.y2 || r2.x1 == r2.x2 || r2.y1 == r2.y2 ) return false;

        return true;
    }
};
