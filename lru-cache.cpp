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

using namespace std;

// https://leetcode.com/problems/lru-cache/

// Assumptions:
// - keys can be any value in [INT_MIN,INT_MAX]
// - capacity can be set to any int value too
//   -> just if capacity <= 0, then get always returns -1
// - does a put update the access time? Sure! Why not?
// - assume keys are not modulo capacity
//
// Observations:
// - goal is to do get and put in O(1)
//   -> means at some point, we will need either a LUT or a map
//   -> map is easier for the purposes of this question
// - can't use a counter-based method of seeing who is the oldest, because
//  that would require sort, O( N log N )
// - can't use a max-heap for keeping track of who is the oldest, because
//  heapification would require O( log N ) whenever an item is removed
// - can't use a single variable for keeping track of oldest, because
//   that model breaks down as soon as there are gets and puts out of order.
// - can't use a fifo because we can't remove things from the middle of a fifo
// - ..
// - but we can use a linked list!!
//   -> if we remember a (key,pointer) tuple in an unordered_map, then lookup,
//      insertion and removal in the um is O( 1 )
//   -> by keeping a pointer to the linked list element in the um, then we
//      can manipulate the map in O( 1 ) too!!
//   -> but we *still* want to have fifo properties of the linked list so that
//      we can keep the ordering of the oldest element. If we insert new items
//      at the end and remove old items from the beginning (on eviction) or the
//      middle (when we re-access them with a get or put), then we have achieved
//      our goals!
//
// Work through example on board, work out kinks..
//
// time-complexity is O(1)
// space-complexity is O( N )

class LRUCache {
protected:
	struct dll {
		int key;
		int val;
		dll *prev;
		dll *next;
		dll() : key( -1 ), val( -1 ), prev( this ), next( this ) {}
	};
	unordered_map<int,dll*> lut;
	dll head;
	int capacity;

	void addTail( dll *node ) {
		if ( node == & head ) {
			throw logic_error( "attempt to add head to doubly-linked-list" );
		}
		dll *tail = head.prev;
		tail->next = node;
		node->next = & head;
		node->prev = tail;
		head.prev = node;
	}
	dll *removeNode( dll *node ) {
		if ( node == & head ) {
			throw logic_error( "attempt to to remove head from doubly-linked-list" );
		}
		dll *prev = node->prev;
		dll *next = node->next;
		prev->next = node->next;
		next->prev = node->prev;
		node->next = nullptr;
		node->prev = nullptr;
		return node;
	}

public:
    LRUCache(int capacity) : capacity( capacity ) {}

    int get(int key) {
    	if ( capacity <= 0 ) {
    		return -1;
    	}
    	if ( lut.count( key ) ) {
    		dll *node = lut[ key ];
    		removeNode( node );
    		addTail( node );
    		return node->val;
    	}
    	return -1;
    }

    void put(int key, int value) {
    	dll *node;
    	if ( capacity <= 0 ) {
    		return;
    	}
    	if ( lut.count( key ) ) {
    		node = removeNode( lut[ key ] );
    	} else if ( lut.size() == size_t( capacity ) ) {
    		node = removeNode( head.next );
    		lut.erase( node->key );
    		lut[ key ] = node;
    	} else {
    		node = new dll;
    		lut[ key ] = node;
    	}
    	node->key = key;
		node->val = value;
    	addTail( node );
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
