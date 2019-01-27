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

#include <cmath>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

// https://leetcode.com/problems/insert-delete-getrandom-o1/

class RandomizedSet {
public:
    RandomizedSet() : nitems( 0 ) {}

    using bool_ptr = pair<bool,int *>; // present, and int *

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
    	bool r;
    	auto it = elements.find( val );
    	if ( elements.end() == it ) {
    		vec.push_back( val );
    		bool_ptr bp = bool_ptr( true, & vec.back() );
    		elements[ val ] = bp;
    		r = true;
    		nitems++;
    	} else {
    		bool & present = it->second.first;
    		if ( ! present ) {
    			nitems++;
    		}
    		r = ! present;
    		present = true;
    	}
    	return r;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
    	bool r;
    	auto it = elements.find( val );
    	if ( elements.end() == it ) {
    		r = false;
    	} else {
    		bool & present = it->second.first;
    		r = present;
    		present = false;
    		nitems--;
    	}
    	return r;
    }

    size_t getRandomIndex() {
    	if ( 0 == nitems ) {
    		throw logic_error( "cannot get a random element from a container of size 0" );
    	}

    	size_t n = vec.size();

    	long rand_u32 = random();
    	double rand_f64 = double( rand_u32 ) / RAND_MAX;
    	double xlated = 0 + rand_f64 * ( n - 1 );
    	size_t idx = ::round( xlated );
    	return idx;
    }

    /** Get a random element from the set. */
    int getRandom() {

    	int val;

    	for( ;; ) {
    		size_t idx = getRandomIndex();
    		val = vec[ idx ];
    		bool & present = elements[ val ].first;
    		if ( present ) {
    			break;
    		}
    	}

    	return val;
    }

protected:
    unordered_map<int,bool_ptr> elements;
    vector<int> vec;
    size_t nitems;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
