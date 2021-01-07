/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <string>
#include <vector>

using namespace std;

class Solution {

public:

    // https://leetcode.com/problems/optimal-division

    string optimalDivision(vector<int>& nums) {
        size_t N = nums.size();
        if ( N > 2 ) {
            string s( to_string( nums[ 0 ] ) + "/(" + to_string( nums[ 1 ] ) );
            for( size_t i = 2; i < N; i++ ) {
                s += "/" + to_string( nums[ i ] );
            }
            s += ")";
            return s;
        } else if ( 2 == N ) {
            return to_string( nums[ 0 ] ) + "/" + to_string( nums[ 1 ] );
        } else if ( 1 == N ) {
            return to_string( nums[ 0 ] );
        } else {
            return "";
        }
    }
};
