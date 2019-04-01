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

	// https://leetcode.com/problems/fruit-into-baskets/

public:
	int totalFruit(vector<int>& tree) {

		if ( tree.size() <= 2 ) {
			return tree.size();
		}

		const size_t N = tree.size();

		// DP, FTW!
		// ================================
		// i        |   | 0 1 2 3 4 5 6 7 8
		// j        | 0 | 1 2 3 4 5 6 7 8 9
		// tree     |   | 1 0 0 0 1 0 4 0 4
		// type[0]  | - | 1 1 1 1 1 1 4 4 4
		// type[1]  | - | - 0 0 0 0 0 0 0 0
		// last[0]  | - | 0 0 0 0 4 4 6 6 8
		// last[1]  | - | - 1 2 3 3 5 5 7 7
		// count[0] | 0 | 1 1 1 1 2 2 1 1 2
		// count[1] | 0 | 0 1 2 3 3 4 1 2 2
		// most     | 0 | 1 2 3 4 5 6 6 6 6

		vector<int> type( 2, -1 );
		vector<size_t> first( 2, 0 );
		vector<size_t> last( 2, 0 );
		vector<vector<size_t>> count( 2, vector<size_t>( N + 1, 0 ) );
		size_t most = 0;

		for( size_t j = 1; j <= N; j++ ) {
			const size_t i = j - 1;
			size_t k;

			// N.B. only really works by using [ k ] / [ ! k ] because there are maximally 2 types of fruit
			for( k = 0; k < 2; k++ ) {

				if ( 0 == count[ k ][ i ] || type[ k ] == tree[ i ] ) {

					// Either:
					//
					// zero unique tree types have been sampled (i.e. no trees have been sampled),
					// or we have already sampled tree i and it matches type[ 0 ]
					//
					// Or:
					//
					// this is only the 2nd unique tree type we have sampled,
					// or we have already sampled tree i and it matches type[ 1 ]

					type[  k ] = tree[ i ];
					if ( 0 == count[ k ][ i ] ) {
						first[ k ] = i;
					}
					last[ k ] = i;
					count[  k ][ j ] = count[  k ][ i ] + 1;
					count[ !k ][ j ] = count[ !k ][ i ];

					break;
				}

			}

			if ( k >= 2 ) {

				// In this case, the next tree we sample does not match type[ i ][ 0 ] or
				// type[ i ][ 1 ]

				// this is where it gets "interesting".
				// Say we have the following 2 scenarios:
				//
				// Example A:
				// i       | 0 1 2 3 4
				// tree[i] | 0 0 1 1 2
				//
				// Example B:
				// i       | 0 1 2 3 4
				// tree[i] | 0 1 0 1 2
				//
				// Up until i == 4, we have had two types of fruit: type 0 and type 1.
				//
				// When we get to i == 4, we have must
				//
				// a) replace one of the types of fruit
				// b) update the count of the type of fruit we did not replace
				//
				// For a), deciding which fruit to replace,
				//    if tree[ i ] == type[ i ][ 0 ] then we discard type[ i ][ 1 ]
				//    if tree[ i ] == type[ i ][ 1 ] then we discard type[ i ][ 0 ]
				//
				//    We'll call the index of the replaced type k again.
				//
				//    We replace the k fruit type with tree[ i ], so
				//      => type[ j ][ k  ] = tree[ i ];
				//      => type[ j ][ !k ] = type[ i ][ !k ];
				//
				//    This satisfies the requirement that 2 fruit types need to be
				//    'contiguous'.
				//
				// For b), updating the count of the fruit we kept, it's a bit tricker
				//
				//     In both Example A, and Example B, by the time we get to i == 4,
				//     count[i][0] == 2 and count[i][1] == 2, but after updating,
				//     in Example A, count[ j ][ 1 ] == 2 and in Example B, count[ j ][ 1 ] == 1.
				//
				//     Why is that? Well, let's look at the last occurrence of fruit type
				//     0 in both cases.
				//
				//     In Example A, the last occurrence of fruit type 0 is at i == 1, and
				//     in Example B, the last occurrence of fruit type 1 is at i == 2.
				//
				//     If k is the fruit that is replaced, then we can say that
				//     count[ j ][ !k ] = count[ i ][ !k ] - count[ last[ i ][ k ] ][ !k ];
				//     OR
				//     count[ j ][ !k ] = count[ last[ i ][ !k ] ][ !k ] - count[ last[ i ][ k ] ][ !k ];
				//
				//     Note, that we have already established last[ !k ] > last[ k ].
				//
				//     In plain language, if we keep track of the last occurrence for each
				//     fruit type, AND the historical counts, then we can easily solve b).

				if ( tree[ i - 1 ] == type[ 0 ] ) {
					k = 1;
				} else {
					k = 0;
				}

				last[ !k ]++;
				type[  k ] = tree[ i ];

				if ( first[ !k ] >= last[ k ] ) {
					// there is no overlap in the intervals that fruit 0 and fruit 1 were collected
					count[ !k ][ j ] = count[ !k ][ i ];

					first[  k ] = i;
					last[  k ] = i;
				} else {
					// there is an overlap in the intervals that fruit 0 and fruit 1 were collected
					// we restart counting
					size_t restart = max( first[ !k ], last[ k ] );
					count[ !k ][ j ] = count[ !k ][ i ] - count[ !k ][ restart ];

					first[  k ] = i;
					last[  k ] = i;
				}
				count[ k ][ j ] = 1;

			}

			size_t current_sum = count[ 0 ][ j ] + count[ 1 ][ j ];
			if ( current_sum > most ) {
				most = current_sum;
		}

//			printf( "j: %d, type[0]: %2d, type[1]: %2d, first[0]: %2d, first[1]: %2d, last[0]: %2d, last[1]: %2d, count[0]: %d, count[1]: %d\n",
//				int(j), type[0][j], type[1][j], int(first[0][j]), int(first[1][j]), int(last[0][j]), int(last[1][j]), int(count[0][j]), int(count[1][j]) );
		}

		return int( most );
	}
};
