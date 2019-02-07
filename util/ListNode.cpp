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
#include <sstream>
#include <vector>

#include "ListNode.hpp"
#include "split.hpp"

using namespace std;

ListNode *ListNode_from_string( const string & s ) {

	ListNode head(-1);
	ListNode *it;

	string _s( s );

	replace( _s.begin(), _s.end(), '-', ' ' );
	replace( _s.begin(), _s.end(), '>', ' ' );

	vector<string> elements = split( _s );

	it = & head;
	for( auto & e: elements ) {
		it->next = new ListNode( stoi( e ) );
		it = it->next;
	}

	return head.next;
}

string ListNode_to_string( ListNode *head ) {
	stringstream ss;
	ListNode *it;
	for( it =  head;; it = it->next ) {
		ss << it->val;
		if ( nullptr == it->next ) {
			break;
		}
		ss << "->";
	}
	return ss.str();
}

void ListNode_cleanup( ListNode **head ) {

	if ( nullptr == head || nullptr == *head ) {
		return;
	}

	ListNode *it = *head;

	ListNode_cleanup( & it->next );

	delete it;

	*head = nullptr;
}

size_t ListNode_size( ListNode *head ) {
	size_t r;
	for( r = 0; nullptr != head; r++, head = head->next );
	return r;
}
