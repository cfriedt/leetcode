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

	// https://leetcode.com/problems/spiral-matrix-ii

	vector<vector<int>> generateMatrix(int n) {
		// Analysis
		// O( N^2 ) (or O(N) ? )
		vector<vector<int>> r = vector<vector<int>>(n, vector<int>(n, 0));

		enum {
			RIGHT, DOWN, LEFT, UP, N_DIR,
		};

		int m;
		int dir;
		int row;
		int col;

		for (m = 1; m <= n * n; m++) {
			if (1 == m) {
				row = 0;
				col = 0;
				dir = RIGHT;
			}

			r[row][col] = m;

			if (n * n == m) {
				break;
			}

			switch (dir) {
			case RIGHT:
				if (col + 1 >= n || r[row][col + 1] != 0) {
					dir = DOWN;
					row++;
				} else {
					col++;
				}
				break;
			case DOWN:
				if (row + 1 >= n || r[row + 1][col] != 0) {
					dir = LEFT;
					col--;
				} else {
					row++;
				}
				break;
			case LEFT:
				if (0 == col || r[row][col - 1] != 0) {
					dir = UP;
					row--;
				} else {
					col--;
				}
				break;
			case UP:
				if (0 == row || r[row - 1][col] != 0) {
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
