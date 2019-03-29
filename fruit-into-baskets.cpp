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

		vector<vector<int>> type( 2, vector<int>( N + 1, -1 ) );
		vector<vector<size_t>> last( 2, vector<size_t>( N + 1, size_t(-1) ) );
		vector<vector<size_t>> count( 2, vector<size_t>( N + 1, 0 ) );
		vector<size_t> most( N + 1, 0 );

		for( size_t j = 1; j <= N; j++ ) {
			const size_t i = j - 1;
			size_t k;

			// N.B. only really works by using [ k ] / [ ! k ] because there are maximally 2 types of fruit
			for( k = 0; k < 2; k++ ) {

				if ( size_t(-1) == last[ k ][ i ] || type[ k ][ i ] == tree[ i ] ) {

					// Either:
					//
					// zero unique tree types have been sampled (i.e. no trees have been sampled)
					// , or we have already sampled tree i and it matches type[ i ][ 0 ]
					//
					// Or:
					//
					// this is only the 2nd unique tree type we have sampled,
					// or we have already sampled tree i and it matches type[ i ][ 1 ]

					type[  k ][ j ] = tree[ i ];
					type[ !k ][ j ] = type[ !k ][ i ];
					last[  k ][ j ] = i;
					last[ !k ][ j ] = last[ !k ][ i ];
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

				if ( tree[ i ] == type[ 0 ][ i ] ) {
					k = 1;
				} else {
					k = 0;
				}

				type[ k ][ j ] = tree[ i ];
				type[ !k ][ j ] = type[ !k ][ i ];
				last[ k ][ j ] = i;
				last[ !k ][ j ] = last[ !k ][ i ];
				size_t last_replaced = last[ k ][ i ];
				size_t count_last_replaced = count[ !k ][ last_replaced ];
				size_t count_last = count[ !k ][ i ];
				//count[ !k ][ j ] = count[ !k ][ last[ !k ][ i ] ] - count[ !k ][ last[ k ][ i - 1 ] ];
				count[ !k ][ j ] = count_last - count_last_replaced;
				count[ k ][ j ] = 1;

			}

			size_t current_sum = count[ 0 ][ j ] + count[ 1 ][ j ];
			if ( current_sum > most[ i ] ) {
				most[ j ] = current_sum;
			} else {
				most[ j ] = most[ i ];
			}
		}

		return int( most.back() );
	}
};
