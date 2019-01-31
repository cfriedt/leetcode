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
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:

	// https://leetcode.com/problems/top-k-frequent-elements/

	vector<int> topKFrequent(vector<int>& nums, int k) {
		vector<int> r;

		unordered_map<int,size_t> count;

		// Insertion in a hash table is O( 1 ), so multiply by N
		for( auto & n: nums ) {
			if ( count.end() == count.find( n ) ) {
				count[ n ] = 1;
			} else {
				count[ n ]++;
			}
		}

        struct gt {
        	// return true if b > a
            bool operator()( const pair<size_t,int> & a, const pair<size_t,int> & b ) {
                return b.second > a.second;
            }
        };

        // max heap / priority queue for the histogram
        vector<pair<int,size_t>> heap;

		// average case O( 1 ), worst O( n ) but only when all items are equal
        // which they are not
		for( auto & kv: count ) {
            heap.push_back( kv );
            push_heap( heap.begin(), heap.end(), gt() );
		}

		for( size_t i = 0; (int)i < k; i++ ) {

			if ( heap.empty() ) {
				break;
			}

			pop_heap( heap.begin(), heap.end(), gt() );
			pair<int,size_t> highest_pair = heap.back();
			int highest_int = highest_pair.first;
			heap.pop_back();

			r.push_back( highest_int );
		}

		return r;
	}
};

