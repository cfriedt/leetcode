/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
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
