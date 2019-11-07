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

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const int M = matrix.size();
        const int N = ( 0 == M ) ? 0 : matrix[0].size();

        enum { RIGHT, DOWN, LEFT, UP };

        vector<int> r( M*N, 0 );

        for( int dir = RIGHT, row = 0, col = 0, i = 0; i < M * N; i++ ) {
            r[ i ] = matrix[ row ][ col ];
            matrix[ row ][ col ] = 0xdeadbeef;
            switch( dir ) {
                case RIGHT:
                    if ( N - 1 == col || int( 0xdeadbeef ) == matrix[ row ][ col + 1 ] ) {
                        dir = DOWN;
                        row++;
                    } else {
                        col++;
                    }
                    break;
                case DOWN:
                    if( M - 1 == row || int( 0xdeadbeef ) == matrix[ row + 1 ][ col ] ) {
                        dir = LEFT;
                        col--;
                    } else {
                        row++;
                    }
                    break;
                case LEFT:
                    if ( 0 == col || int( 0xdeadbeef ) == matrix[ row ][ col - 1 ] ) {
                        dir = UP;
                        row--;
                    } else {
                        col--;
                    }
                    break;
                case UP:
                    if ( 0 == row || int( 0xdeadbeef ) == matrix[ row - 1 ][ col ] ) {
                        dir = RIGHT;
                        col++;
                    } else {
                        row--;
                    }
                    break;
            }
        }

        return r;
    }
};
