/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int rotatedDigits(int N) {

        int total = 0;

        for( int x = 1; x <= N; x++ ) {
            int xx;
            int digit;
            int y;
            int k;

            for( k = 1, xx = x, digit = xx % 10, y = 0; xx; xx /= 10, digit = xx % 10, k *= 10 ) {
                if ( 3 == digit || 4 == digit || 7 == digit ) {
                    goto just_continue;
                }
                if ( !( 0 == digit || 1 == digit || 8 == digit ) ) {
                    switch( digit ) {
                    case 2: digit = 5; break;
                    case 5: digit = 2; break;
                    case 6: digit = 9; break;
                    case 9: digit = 6; break;
                    }
                }
                y += k * digit;
            }

            // the number must be changed
            if ( x == y ) {
                continue;
            }

            total++;

just_continue:
             continue;
        }

        return total;
    }
};

