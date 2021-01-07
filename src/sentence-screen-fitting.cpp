/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
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
