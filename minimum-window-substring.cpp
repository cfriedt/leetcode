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

#include <map>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:

	// https://leetcode.com/problems/minimum-window-substring/

	string minWindow(string s, string t) {

		// This is a slightly deceptive problem when first encountered.
		// Outwardly, it doesn't *seem* like it's a difficult problem until you try to solve it.
		//
		// However, it is *extremely* important in this day and age, particularly when
		// you consider that it is exactly like another problem, not necessarily on
		// leetcode.com, but encountered *billions* of times daily.
		// That problem is, namely, the following:
		//
		// Given a page of text (i.e. words separated by whitespace in string form), and another
		// string containing a number of search terms separated by whitespace, find the shortest
		// window of text containing all search terms. This is categorically Google.
		//
		// Input: S = "ADOBECODEBANC", T = "ABC"
		// Output: "BANC"
		//
		// The solution that I would consider "brute force" is the one that I thought of first,
		// which is the following:
		//                               shortest
		// i    A_i    B_i    C_i     window (pos, len)
		// --------------------------------------------
		// 0     0
		// ..
		// 3     0      3
		// ..
		// 5     0      3      5       (0,6)
		// ..
		// 9     0      9      5       (0,6) ** shortest window not updated, because (0,10) is longer
		// 10    10     9      5       (0,6) ** shortest window not updated, because (5,6) is longer
		//                                      N.B. We should probably set out some assumptions
		//                                           - only one shortest window exists (i.e. there is only 1 correct answer)
		//                                           - all items in T are unique.
		//                                      N.B. Some shortcuts
		//                                           - if window.length() == T.length(), short circuit return window
		//                                           - if S.length() < T.length() there is no way S can contain all terms in T, so return ""
		// ..
		// 12    10     9      12      (9,4)
		//
		// Reached the end, and have found the shortest term, in this case.
		// This algorithm is ok-ish, at first glance, it appears to be, it's O( N * M ), where N is the number of items in S
		// and M is the number of items in T. In the degenerate case where M is small, it's linear though, so not all hope is lost!
		// ======================================================================================
		// Correction!!! It's O( N log M ) approximately, although the details are revealed below
		// ======================================================================================
		//
		// Let's assume that other people are convinced that it should be coded-up, in any case.
		//
		// We obviously can't hard-code variables A_i, B_i, and C_i, but what I would do is use an unordered_map<char,size_t> to
		// keep track of them. If the size of the map is equal to the number of items in T, then we know we have found a solution.
		// ======================================================================================
		// Correction!!! Use an ordered map (std::map) to keep track of the indices by char, but
		// also use an ordered set (std::set) to keep the indices in order as well.
		// ======================================================================================
		//
		// For keeping track of the shortest window, we can use two variables: size_t window_pos, size_t window_len.
		// If we initialize window_len to S.length(), then we can be sure we will always be updating it with a smaller size.
		//
		// Finally, let's also not forget the short circuit solutions we mentioned above.
		//
		// Additional comments:
		//
		// The leetcode test cases allows duplicates in t, which is super freaking annoying.
		// It's an unnecessarily complex wrench to throw into the works, but realistically, so is
		// every other mutation of a common problem.

		if ( s.length() < t.length() ) {
			// short circuit return
			return "";
		}

		if ( s == t ) {
			// short circuit return
			return t;
		}

		unordered_set<char> terms( t.begin(), t.end() ); // uses a hash table

		map<char,size_t> indices; // uses a self-balancing tree (e.g. red-black) is used
		set<size_t> by_index; // uses a self-balancing tree (e.g. red-black) is used

		size_t window_pos = 0;
		size_t window_len = s.length();

		for( size_t i = 0; i < s.length(); i++ ) { // O( N )

			// if the char at position i is one of our search terms..
			if ( terms.end() != terms.find( s[ i ] ) ) { // O( 1 )

				auto it = indices.find( s[ i ] ); // O( log M )

				if ( it == indices.end() ) {

					by_index.insert( i ); // O( log M )

					// update the most recent occurrence of character s[i]
					indices[ s[ i ] ] = i; // O( log M )
				} else {

					by_index.erase( it->second ); // O( log M )
					by_index.insert( i ); // O( log M )

					// update the most recent occurrence of character s[i]
					it->second = i; // O( 1 ), since we saved the iterator
				}

				if ( indices.size() == terms.size() ) { // O( 1 )
					// update window position, length, if appropriate
					size_t new_window_begin = *(by_index.begin());
					size_t new_window_end = *(by_index.rbegin());
					size_t new_window_len = new_window_end - new_window_begin + 1;
					if ( new_window_len < window_len ) {
						window_pos = new_window_begin;
						window_len = new_window_len;
						if ( window_len == t.length() ) {
							// short circuit return
							break;
						}
					}
				}
			}
		}

		if ( indices.size() == terms.size() ) {
			return s.substr( window_pos, window_len );
		} else {
			return "";
		}
	}
};
