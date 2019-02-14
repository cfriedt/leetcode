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


#include <cstddef>

using namespace std;

class Solution {
public:

	// https://leetcode.com/problems/odd-even-linked-list/

	ListNode* oddEvenList(ListNode* head) {
		// Assumptions:
		// - 1-indexed, so the head pointer is '1'
		//
		// Observations:
		// - maintain e.g. a bool to indicate whether we are serving even or odd
		// - maintain a pointer to first / last element in odd / even
		// - makes appending O(1) and lets us keep a reference for
		//   concatenating at the end
		// - visit each node exactly once, O( N ) in time and O( 1 ) in space

		if ( nullptr == head ) {
			return nullptr;
		}

		enum {
			ODD,
			EVEN,
		};

		ListNode *m_head[2]{};
		ListNode *m_tail[2]{};

		ListNode *it = head;
		bool odd = ODD;
		for( ; it ; it = it->next, odd ^= 1 ) {
			if ( nullptr == m_head[ odd ] ) {
				m_head[ odd ] = m_tail[ odd ] = it;
			} else {
				m_tail[ odd ]->next = it;
				m_tail[ odd ] = m_tail[ odd ]->next;
			}
		}
		m_tail[ ODD ]->next = m_head[ EVEN ];
        if ( nullptr != m_tail[ EVEN ] ) {
		    m_tail[ EVEN ]->next = nullptr;
        }

		return m_head[ ODD ];
	}
};
