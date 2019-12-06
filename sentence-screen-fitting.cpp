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

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:

	// https://leetcode.com/problems/sentence-screen-fitting/

    int wordsTyping(vector<string>& sentence, int rows, int cols) {

    	// the brute force solution is not fast enough
    	// if N = rows, and M = cols, then the brute force solution
    	// is approximately O(NM) or O(N^2)
    	//
    	// However, by precomputing the number of words that can be
    	// skipped for each possible word beginning a row, if
    	// K = sentence.size(), N = num rows, and M = num cols,
    	// then the complexity becomes about O( K + N ) or O( N ) if
    	// N is large and K is small.
    	//
    	// I think it might even be possible to just use some extrapolation
    	//
    	// So O( N / K )?

    	// precompute cache
    	const size_t K = sentence.size();
    	const size_t N = size_t( rows );
    	const size_t M = size_t( cols );

    	vector<size_t> cache( K, 0 );
    	for( size_t i = 0; i < K; i++ ) {
    		cols = M;
    		size_t nwords = 0;
    		for( size_t j = i; cols > 0; j++, j %= K, nwords++ ) {
    			if ( sentence[ j ].size() > size_t( cols ) ) {
    				break;
    			}
    			cols -= sentence[ j ].size();
    			cols -= 1;
    		}
    		cache[ i ] = nwords;
    	}

    	size_t total = 0;
    	for( size_t row = 0, j = 0; row < N; row++ ) {
    		size_t nwords = cache[ j ];
    		j += nwords;
    		j %= K;
    		total += nwords;
    	}

        return int( total / K );
    }
};
