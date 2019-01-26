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
#include <random>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

// https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/

class RandomizedCollection {
public:
    RandomizedCollection() : nunique_items( 0 ), gen(rd()) {}

    using size_ptr = pair<size_t,int *>; // count, and int *

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
    	bool r;
    	auto it = elements.find( val );
    	if ( elements.end() == it ) {
    		vec.push_back( val );
    		size_ptr sp = size_ptr( 1, & vec.back() );
    		elements[ val ] = sp;
    		r = true;
    		nunique_items++;
    	} else {
    		size_t & count = it->second.first;
    		bool present = count > 0;
    		if ( ! present ) {
    			nunique_items++;
    		}
    		r = ! present;
    		count++;
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
    		size_t & count = it->second.first;
    		bool present = count > 0;
    		r = present;
    		if ( present ) {
    			count--;
        		if ( 0 == count ) {
        			nunique_items--;
        		}
    		}
    	}
    	return r;
    }

    size_t getRandomIndex() {
    	if ( 0 == nunique_items ) {
    		throw logic_error( "cannot get a random element from a container of size 0" );
    	}

    	size_t n = vec.size();
    	uniform_int_distribution<size_t> dis(0,n-1);

    	return dis( gen );
    }

    /** Get a random element from the set. */
    int getRandom() {

    	int val;

    	for( ;; ) {
    		size_t idx = getRandomIndex();
    		val = vec[ idx ];
    		size_t & count = elements[ val ].first;
    		bool present = count > 0;
    		if ( present ) {
    			break;
    		}
    	}

    	return val;
    }

    size_t getNumUniqueItems() {
    	return nunique_items;
    }

protected:
    unordered_map<int,size_ptr> elements;
    vector<int> vec;
    size_t nunique_items;

	// Very c++11-ish way of generating random values.
	// In a pinch, I would probably just use random().

	random_device rd;
	mt19937 gen;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
