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
#include <vector>

using namespace std;

class Solution {
public:

	// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

	int kthSmallest(vector<vector<int>>& matrix, int k) {
		const size_t rows = matrix.size();
		const size_t cols = matrix[ 0 ].size();
		vector<int> flattened( rows * cols  );
		// O( N )
		for( size_t i = 0; i < rows * cols; i++ ) {
			flattened[ i ] = matrix[ i / cols ][ i % cols ];
		}
		// O( N log N )
		sort( flattened.begin(), flattened.end() );

		return flattened[ k - 1 ];
	}
};
