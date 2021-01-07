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

	// https://leetcode.com/problems/median-of-two-sorted-arrays/

	double findMedianSortedArrays(vector<int> & nums1, vector<int> & nums2) {

		// The "brute force" approach would copy all of nums1 and nums2 into
		// a new vector, and then sort, and then find the median based on vector length.
		// The "brute force" approach is O( (N+M) log(N+M) + (N+M) ).
		//
		// A better alternative is to use a min heap and a max heap to split
		// the complete set of numbers into two sets that are about the same size.
		//
		// The max heap collects numbers that are <= the median, while the
		// min heap collects numbers that are >= the median.
		//
		// The key to this alternative is to iterate through nums1 and nums2
		// at the same time, always choosing the lower of the two lists.
		//
		// This approach is O( (N+M) log( (N+M)/2 ) ), so there is only a slight speed advantage.
		//
		// We can use the convention that the median will *always* be found at the top of the
		// max heap, which also implies that the size of the max heap will always be either equal to
		// the size of the min heap, or it will be greater by 1.
		//
		// Pictorially this would look kind of like an hourglass, with the max-heap at the bottom
		// like a triangle pointed up, and the min-heap at the top like a triangle pointed down.
		//
		// Assumptions:
		// - nums1 and nums2 may contain duplicates
		//
		// Arguably, the correct handling of duplicates is what makes this problem interesting :-)
		//
		// Let's take an example
		//
		// nums1 = [1,2,3], nums2 = [1,2,3]
		//
		// i1    i2    x    maxh    minh    comment
		// 0     0     1    []      []      - nums1[ i1 ] == num2[ i2 ], so just use x from nums1
		//                                  - maxh and minh are empty, so put x in maxh to maintain convention
		//                                  - increment i1
		// 1     0     1    [1]     []      - since nums2[ i2 ] < nums1[ i1 ], use x from nums2
		//                                  - maxh.size() is > minh.size(), so we need to put an item in minh
		//                                  - since x is equal to the median, no replacement is required
		//                                  - put x in minh
		//                                  - increment i2
		// 1     1     2    [1]     [1]     - nums1[ i1 ] == nums2[ i2 ], so use x from nums1
		//                                  - x is greater than the mean, and x is also greater than the
		//                                    bottom of minh
		//                                  - To maintain convention that maxh.size() >= minh.size()
		//                                    need pop the bottom of minh, swap x and the bottom
		//                                    heapify the minh, then add the swapped x to the maxh, and
		//                                    finally heapify the maxh
		//                                  - increment i1
		// 2    1      2    [1,1]   [2]     - since nums2[ i2 ] < nums1[ i1 ], use x from nums2
		//                                  - maxh.size() is > minh.size(), so we need to put an item in minh
		//                                  - since the bottom of minh is > the median, we can just add
		//                                    x to minh
		//                                  - heapify minh
		//                                  - increment i2
		// 2    2      3    [1,1]   [2,2]   - nums1[ i1 ] == nums2[ i2 ], so use x from nums1
		//                                  - x is greater than the mean, and x is also greater than the
		//                                    bottom of minh
		//                                  - To maintain convention that maxh.size() >= minh.size()
		//                                    need pop the bottom of minh, swap x and the bottom
		//                                    heapify the minh, then add the swapped x to the maxh, and
		//                                    finally heapify the maxh
		//                                  - increment i1
		// 3   2       3    [1,1,2]  [2,3]  - since i1 >= nums1.size(), we must use x from nums2
		//                                  - maxh.size() is > minh.size(), so we need to put an item in minh
		//                                  - since the bottom of minh is > the median, we can just add
		//                                    x to minh
		//                                  - heapify minh
		//                                  - increment i2
		// 3   3            [1,1,2] [2,2,3] - since both i1 >= nums1.size() and i2 >= nums2.size(), we are
		//                                    done
		//                                  - return the median from the top of the max heap
		//
		// Let's code it up!

		struct is_lt {
			bool operator()( int a, int b ) {
				return b < a;
			}
		};

		vector<int> minh, maxh;

		for( size_t i1 = 0, i2 = 0; i1 < nums1.size() || i2 < nums2.size(); ) {

			// select source for x from nums1 or nums2

			int x;

			if ( i1 < nums1.size() && i2 < nums2.size() ) {
				if ( nums1[ i1 ] <= nums2[ i2 ] ) {
					x = nums1[ i1 ];
					i1++;
				} else {
					x = nums2[ i2 ];
					i2++;
				}
			} else if ( i1 < nums1.size() ) {
				x = nums1[ i1 ];
				i1++;
			} else {
				x = nums2[ i2 ];
				i2++;
			}

			bool maxh_needs_heapify = false;
			bool minh_needs_heapify = false;

			if ( minh.size() == maxh.size() ) {

				// an item will need to be added to maxh

				if ( maxh.empty() ) {
					// minh is also empty, by definition, since maxh.size() >= minh.size()
					maxh.push_back( x );
				} else {
					// both minh and maxh have size >= 1
					if ( minh.front() < x ) {
						pop_heap( minh.begin(), minh.end(), is_lt() );
						swap( x, minh.back() );
						minh_needs_heapify = minh.size() > 1;
					}
					maxh.push_back( x );
					maxh_needs_heapify = maxh.size() > 1;
				}

			} else {

				// an item will need to be added to minh

				if ( x < maxh.front() ) {
					pop_heap( maxh.begin(), maxh.end() );
					swap( x, maxh.back() );
					maxh_needs_heapify = maxh.size() > 1;
				}
				minh.push_back( x );
				minh_needs_heapify = minh.size() > 1;

			}

			if ( minh_needs_heapify ) {
				push_heap( minh.begin(), minh.end(), is_lt() );
			}

			if ( maxh_needs_heapify ) {
				push_heap( maxh.begin(), maxh.end() );
			}
		}

		if ( maxh.empty() ) {
			return 0;
		}

		if ( maxh.size() == minh.size() ) {
			return ( maxh.front() + minh.front() ) / 2.0;
		} else {
			return maxh.front();
		}
	}
};
