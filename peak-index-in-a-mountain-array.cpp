/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        // probably can be done faster using a binary search
        // simplest solution is linear
        int peak_index = 1;
        for( size_t i = 1; i < A.size() - 1; i++ ) {
            if ( A[ i - 1 ] < A[ i ] && A[ i ] > A[ i + 1 ] ) {
                peak_index = i;
                break;
            }
        }
        return peak_index;
    }
};
