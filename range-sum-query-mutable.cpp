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

#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

// https://leetcode.com/problems/range-sum-query-mutable/

namespace std {
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;
    }
};
}

class NumArray {
public:

    vector<int> nums;
    unordered_map<pair<int,int>,int, pair_hash> cache;

    NumArray( vector<int> nums ) : nums( nums ) {
    }

    void update(int i, int val) {
    	int prev = nums[ i ];
    	if ( prev == val ) {
    		return;
    	}
    	int delta = val - prev;
    	// worst-case O( N )
    	for( auto & kv: cache ) {
    		auto & p = kv.first;
    		if ( i >= p.first && i <= p.second ) {
    			kv.second += delta;
    		}
    	}
    	nums[ i ] = val;
    }

    int sumRange(int i, int j) {
    	pair<int,int> p( i, j );
    	auto it = cache.find( p );
    	if ( cache.end() != it ) {
    		return (*it).second;
    	}
    	int s = 0;
    	// worst-case O( N )
    	for( int k = i; k <= j; k++ ) {
    		s += nums[ k ];
    	}
    	return s;
    }
};

