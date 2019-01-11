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
#include <vector>

using namespace std;

class MinStack {

protected:
	struct is_le {
	bool operator()( const int & a, const int & b ) {
		return b <= a;
	}
	};
	// https://leetcode.com/problems/min-stack/

public:

	//	Assumptions:
	//	Let’s assume x is an int
	//	Assume elements.back() is O(1)
	//	Assume elements.push_back() elements.pop_back() is O(1)
	//	Assume getMin() does not actually remove the element from the stack.
	//	Assume top() does not actually remove the element from the stack.
	//	Assume an int is an int - ordering of equal ints does not matter
	//
	//	Not a lot to this. Assuming it’s ok to use vector for storage and vector methods for adding an item to the end. <facepalm>The way to do getMin() would be to just have a separate field for the min value and the min position.</facepalm>
	//
	//	Corner cases:
	//	If you were to use the simple method of just remembering the min position and value, when popping the min off the stack, you would not be able to provide a subsequent min. Therefore, use a minheap for keeping track of the min value.
	//	Whenever the min is popped off of the stack, clear and rebuild the minheap.
	//	If the stack is empty when getMin(), pop() or top() is called,
	//		Should probably throw an exception.


    /** initialize your data structure here. */
    MinStack() {

    }

	void push( int x ) {
		// O( 1 );
		elements.push_back( x );
		minHeap.push_back( x );
		// O( log N )
		push_heap( minHeap.begin(), minHeap.end(), is_le() );
	}

	void pop() {
		// O( 1 )
		elements.pop_back();
		minHeap = vector<int>( elements.size(), 0 );
		// O( N )
		copy( elements.begin(), elements.end(), minHeap.begin() );
		// O( N log N )
		make_heap(minHeap.begin(), minHeap.end(), is_le() );
	}

	int top() {
		// O( 1 )
		return elements.back();
	}
	int getMin() {
		// O( 1 )
		return minHeap.front();
	}

protected:
	vector<int> elements;
	vector<int> minHeap;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
