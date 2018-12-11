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
#include <array>
#include <vector>

using namespace std;

class Solution {
public:

	// https://leetcode.com/problems/minimum-window-substring/

	string minWindow(string s, string t) {

		//
		// This is attempt 2 using the sliding window approach. It's basically the same
		// approach that I took before except it handles duplicates in t.
		//
		// The algorithmic complexity in minimum-window-substring.README.txt is wrong
		// but I jotted down a number of interesting notes there.
		//
		// If we look at the algorithmic complexity of this approach, it's
		// at least O( N ), where N is the number of characters in s. In the worst-case
		// scenario (where all of the search terms are at the end of s), it is ~O( 2N )
		// because we would grow the window to the size of s and then shrink it to
		// N - M.
		//

		if ( s.empty() || t.empty() || s.length() < t.length() ) {
			return "";
		}

		// t_count is a LUT so that we can use to see if a given char in s is a term in t.
		// Really it's like an unordered_map<char,size_t>.
		// We likely waste a fair amount of space by using a LUT. In this case, it's 1kB
		// which can be significant on small platforms. It's fast though.
		// If we were to expand this algorithm to s and t as string vectors, or any arbitrary
		// key_type, an unordered_map<key_type,size_t> would be preferred.
		// N.B. the reason we don't simply use e.g. an unordered_set<char> here is to account
		// for duplicates in t.
		array<size_t,256> t_count;
		fill( t_count.begin(), t_count.end(), 0 );

		// we keep track of the number of unique terms in t. once we have matched the
		// t_count in s_count for all unique items in t, then we have found a valid window.
		size_t n_t_unique = 0;

		// populate the t_count LUT with items in t, and also count the unique items in t
		for( auto c: t ) {
			if ( 0 == t_count[ c ] ) {
				n_t_unique++;
			}
			t_count[ c ]++;
		}

		// here we maintain a running count (also via LUT) of the characters in s contained
		// within our window.
		array<size_t,256> s_count;
		fill( s_count.begin(), s_count.end(), 0 );

		// keep track of the smallest window position and length
		size_t win_pos = 0;
		size_t win_len = SIZE_MAX;

		size_t L, R, t_matched;
		for( L = 0, R = 0, t_matched = 0; R < s.size(); ) {

			// since we initialize L and R at zero, we have to pre-fill s_count if s[ 0 ] is a term in t
			if ( 0 == L && 0 == R ) {
				if ( t_count[ s[ 0 ] ] ) {
					s_count[ s[ 0 ] ] = 1;
					if ( s_count[ s[ 0 ] ] == t_count[ s[ 0 ] ] ) {
						// we have exactly the number of s[ 0 ] in our window that exist in t
						t_matched++;
					}
				}
			}

			if ( t_matched < n_t_unique ) {
				// increase R to widen the search window
				R++;
				if ( R >= s.size() ) {
					// do not segfault
					break;
				}
				if ( t_count[ s[ R ] ] > 0 ) {
					// s[ R ] is a term in t, so increase the count within our widened search window
					s_count[ s[ R ] ]++;
					if ( s_count[ s[ R ] ] == t_count[ s[ R ] ] ) {
						// we have exactly the number of s[ R ] in our window that exist in t
						t_matched++;
					}
				}
			} else if ( t_matched >= n_t_unique ) {
				if ( t_matched == n_t_unique ) {
					// we have found an "interesting" window
					size_t new_win_pos = L;
					size_t new_win_len = (R-L)+1;
					if ( new_win_len < win_len ) {
						win_pos = new_win_pos;
						win_len = new_win_len;

						if ( t.length() == win_len ) {
							// the answer cannot get any smaller than this so, assuming
							// "there can be only one" (answer), return the newly found window.
							break;
						}
					}
				}

				// increase L to narrow the search window
				if ( t_count[ s[ L ] ] > 0 ) {
					// s[ L ] was a term in t, so decrease the count within our narrowing search window
					if ( s_count[ s[ L ] ] == t_count[ s[ L ] ] ) {
						// we no longer will have exactly the number of s[ L ] in our window that exist in t
						t_matched--;
					}
					s_count[ s[ L ] ]--;
				}
				L++;
			}
		}

		return ( SIZE_MAX == win_len ) ? "" : s.substr( win_pos, win_len );
	}
};
