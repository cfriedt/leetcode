/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
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

