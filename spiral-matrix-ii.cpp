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

// https://leetcode.com/problems/spiral-matrix-ii

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        enum dir {
            RIGHT = 0,
            DOWN = 1,
            LEFT = 2,
            UP = 3,
        };

        const size_t N = n;
        vector<vector<int>> r(N, vector<int>(N, -1));
        r[0][0] = 1;

        int dir = RIGHT;
        size_t i = 0;
        size_t j = 0;
        for(size_t k = 2, x = 1; k <= N*N;) {
            switch(dir) {
            case RIGHT:
                if (j < N - 1 && r[i][j + 1] == -1) {
                    r[i][j + 1] = k++;
                    ++j;
                } else {
                    dir = DOWN;
                }
                break;
            case DOWN:
                if (i < N - 1 && r[i + 1][j] == -1) {
                    r[i + 1][j] = k++;
                    ++i;
                } else {
                    dir = LEFT;
                }
                break;
            case LEFT:
                if (j > 0 && r[i][j - 1] == -1) {
                    r[i][j - 1] = k++;
                    --j;
                } else {
                    dir = UP;
                }
                break;
            case UP:
                if (i > 0 && r[i - 1][j] == -1) {
                    r[i - 1][j] = k++;
                    --i;
                } else {
                    dir = RIGHT;
                }
                break;
            }
        }

        return r;
    }
};
