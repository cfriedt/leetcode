/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  // https://leetcode.com/problems/arithmetic-slices

  int numberOfArithmeticSlices(vector<int> &A) {

    // Assumptions
    // - slices must be at least 3 elements long
    // - slices can and do overlap
    // - if A has < 3 elements, there are no slices
    //
    // Observations
    // - Brute force: O( N^2 ) time, O( 1 ) space
    // int n_slices = 0;
    // for( int i = 0; i < A.size() - 2; i++ ) {
    //     const int d = A[ i + 1 ] - A[ i ];
    //     for( int j = i + 2; j < A.size(); j++ ) {
    //         if ( d != A[ j ] - A[ j - 1 ] ) {
    //             break;
    //         }
    //         n_slices++;
    //     }
    // }
    // return n_slices;
    //
    // Can we do better in terms of time efficiency, and how?
    //
    // It's easy to get the longest slice of each difference in linear time
    // - by simply remembering when we start trying to form a slice, and
    //   testing linearly until the slice is done.
    //
    // And it's likely that there is some fairly straightforward mathematical
    // formula to determine how many "sub-slices there are" for a slice of a
    // given length. That would make the overall time O( N ) as well.

    // The key to the overall time being O( N ) is that the function
    // calculate_nslices() is O( N ) in the worst case scenario (the run is the
    // entire length N), which would make the scan for the slice N, and the
    // calculation of slices N - 3 or something. The two are additive so O( N ).
    //
    // Technically speaking, we don't need a cache, and it would just be O( 2N )
    // => O( N ). I just assumed a cache would speed up the recursion. I assume
    // that it would for many slices and a very large size of A.

    // unordered_map<int,int> cache;

    int nslices = 0;
    int begin;
    int end;
    for (begin = 0; size_t(begin) + 2 < A.size();) {

      int new_slices = 0;
      int delta = A[begin + 1] - A[begin];

      for (end = begin + 1; size_t(end + 1) < A.size(); end++) {
        if (delta != A[end + 1] - A[end]) {
          break;
        }
      }

      int len = end - begin + 1;

      new_slices = calculate_nslices(len);
      if (0 == new_slices) {
        begin++;
      } else {
        begin = end;
        nslices += new_slices;
      }
    }
    return nslices;
  }

protected:
  static inline int calculate_nslices(int len) {
    // reduces to sum(0,n){ i } = sum(1,n){ i } = n(n+1)/2
    int r;
    for (r = 0; len >= 3; r += len - 3 + 1, len--)
      ;
    return r;
  }
};
