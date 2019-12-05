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
#include <climits>
#include <vector>

using namespace std;

// https://leetcode.com/problems/find-in-mountain-array

class Solution {
public:
    // find the minimum index such that mountainArr.get(index) == target
    int findInMountainArray(int target, MountainArray &mountainArr) {

        // Given that we only have 100 get's and that A can be up to 10000 elements long
        // we're going to need to employ an algorithm that can do this faster than N, so log(N).
        //
        // Since the elements are in increasing order (up to the peak),
        // and decreasing order the peak, the logical choice would be to use a
        // binary search.
        //
        // I think the first goal should be to find the peak, and then the
        // second goal should be to locate the target (if it exists), because then it's simply
        // O(2*log(N)) => O(log(N)).
        //
        // This is an interesting problem because the target could potentially exist before
        // AND / OR after the peak, or neither.
        //
        // Actually, as long as we know the first element, the last element, and the
        // index & value of the peak element, then it's possible to determine the maximum
        // number of get's used as well, even if the target does not exist
        // in the array.
        //
        // The kind of hilarious / obvious thing about this question, is that we're
        // basically just doing a faster kind of numerical differentiation; by quickly
        // finding inflection points, it could speed up rendering. Would be fun to implement that
        // in silicon :-)
        //
        // In any case, there are two problems:
        // 1) finding the peak, and
        // 2) locating the target
        //
        // Locating the target is just a straightforward application of binary search - there is
        // nothing crazy about it.
        //
        // Finding the peak, as I mentioned, is more involved. It's a binary search, but the
        // comparison algorithm has to examine 2nd order characteristics by employing a central
        // difference around the midpoint.
        //
        // As a bit of a shortcut, so we do not waste get's, it's also possible to use an unordered_map to
        // cache the results of the get. For very large datasets that could be necessary, but here it is
        // not necessary as log2( 10000 ) < 100.

        int minimumIndex = INT_MAX;

        size_t N;
        int first;
        int peak;
        size_t peakIdx;
        int last;

        initialize( mountainArr, N, first, last );

        findPeak( mountainArr, 0, N - 1, peak, peakIdx );

        //cout << "found peak " << peak << " at " << peakIdx << endl;

        if ( target == peak ) {
            return peakIdx;
        }

        //cout << "checking left side" << endl;
        findTarget( mountainArr, 0, first, peakIdx, peak, target, minimumIndex );

        //cout << "minimumIndex: " << minimumIndex << endl;

        if ( INT_MAX == minimumIndex ) {
            //cout << "checking right side" << endl;
            findTarget( mountainArr, peakIdx, peak, N-1, last, target, minimumIndex );
        }

        //cout << "minimumIndex: " << minimumIndex << endl;

        if ( INT_MAX == minimumIndex ) {
            minimumIndex = -1;
        }

        return minimumIndex;
    }

protected:

    static void initialize( MountainArray & A, size_t & N, int & first, int & last ) {
        N = A.length();
        first = A.get( 0 );
        last = A.get( N - 1 );
    }

    static void findPeak( MountainArray & A, size_t L, size_t R, int & peak, size_t & peakIdx ) {

        for(;;) {

            size_t M;
            int m;
            int mAtMMinusOne;
            int mAtMPlusOne;

            M = ( L + R ) / 2;
            m = A.get( M );

            mAtMMinusOne = A.get( M - 1 );
            mAtMPlusOne = A.get( M + 1 );

            bool increasing = true;

            if ( false ) {
            } else if ( mAtMMinusOne < m && m < mAtMPlusOne ) {
                increasing = true;
            } else if ( mAtMMinusOne > m && m > mAtMPlusOne ) {
                increasing = false;
            } else {
                // YOU HAVE REACHED THE SUMMIT \o/
                peak = m;
                peakIdx = M;
                return;
            }

            if ( increasing ) {
                // move to the right
                L = M;
            } else {
                // move to the left
                R = M;
            }
        }
    }

    static void findTarget( MountainArray & A, size_t L, int l, size_t R, int r, const int & target, int & minimumIndex ) {

        for(;;) {

            size_t M;
            int m;

            bool increasing = r > l;

            M = ( L + R ) / 2;
            m = A.get( M );

            //cout << "target: " << target << " L: " << L << " l: " << l << " M: " << M << " m: " << m << " R: " << R << " r: " << r << endl;

            if ( R - L <= 1 ) {
                if ( false ) {
                } else if ( target == l ) {
                    minimumIndex = min( minimumIndex, int(L) );
                } else if ( target == r ) {
                    minimumIndex = min( minimumIndex, int(R) );
                }
                return;
            }

            if ( target == m ) {
                minimumIndex = min( minimumIndex, int(M) );
                return;
            }

            if ( ( increasing && target < m ) || ( !increasing && target > m ) ) {
                // move left
                //cout << "move left" << endl;
                R = M;
                r = m;
            } else {
                // move left
                //cout << "move left" << endl;
                L = M;
                l = m;
            }
        }
    }
};
