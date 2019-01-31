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

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:

	// https://leetcode.com/problems/repeated-dna-sequences/

	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> r;

		unordered_map<string,size_t> count;
		const size_t N = s.size();
		const size_t M = 10; // repeated sequence length is fixed size of 10

		if ( N <= M ) {
			return r;
		}

		for( size_t i = 0; i <= N - M; i++ ) {
			string z = s.substr( i, M );
			if ( count.end() == count.find( z ) ) {
				count[ z ] = 1;
			} else {
				count[ z ]++;
			}
		}

		for( auto & kv: count ) {
			if ( kv.second > 1 ) {
				r.push_back( kv.first );
			}
		}

		return r;
    }
};
