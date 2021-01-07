/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <algorithm>
#include <vector>

using namespace std;

// https://leetcode.com/problems/maximize-distance-to-closest-person/

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        // Ex. [1,0,0,0,1,0,1] => 2
        // The brute force approach would be to examine each place, if it's a zero, then
        // first, count how many zeros are to the left, and count how many zeros are to the right, and keep track of the max.
        // That algorithm is O(N^2)
        // Can we do better? Yes!
        // Can it be done in 1 pass (i.e. O(N)). Probably!
        // I think a really simple way to do this would be to count the largest distance between ones and divide that by 2.
        // Ex 1. 1000101 => 10x0101, so 4 - 0 = 4 (even), 4/2 = 2
        // Ex 2. 100101  => 10x101, so 3 - 0 = 3 (odd), 3/2 = 1
        // Ex 3. 000101  => x00101, so 3 - 0 = 3
        //                          this is a special case, because we are at the left boundary and so do not have to divide
        //                          the distance by 2, so it's simply the distance
        // Ex 4. 101000  => 10100x, so 5 - 2 = 3
        //                          this is a special case, because we are at the right boundary and so do not have to divide
        //                          the distance by 2, so it's simply the distance
        //
        // So counting the max distance between two ones can be done in O(N) time - it's a two-pointer problem.

        const int N = seats.size();
        int maxDist = 0;
        bool moveR = true;

        for( int L = 0, R = 0;; ) {

            if ( N - 1 == L && N - 1 == R ) {
                break;
            }

            if ( moveR ) {
                if ( seats[ R ] == 1 || R == N - 1 ) {
                    //cout << "move L" << endl;
                    moveR = false;
                }
            } else {
                if ( L == R ) {
                    //cout << "move R" << endl;
                    moveR = true;
                }
            }

            if ( moveR ) {
                R++;
            } else {
                L++;
            }

            if ( 1 == seats[ L ] and 1 == seats[ R ] ) {
                maxDist = max( maxDist, (R-L)/2 );
                //cout << "L: " << L << " R: " << R << " maxDist: " << maxDist << endl;
            } else if ( 0 == L && 1 == seats[ R ] ) {
                maxDist = R;
                //cout << "L: " << L << " R: " << R << " maxDist: " << maxDist << endl;
            } else if ( 1 == seats[ L ] && N - 1 == R ) {
                maxDist = max( maxDist, R - L );
                //cout << "L: " << L << " R: " << R << " maxDist: " << maxDist << endl;
            }
        }

        return maxDist;
    }
};
