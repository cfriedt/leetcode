/*
 * Copyright (c) 2019 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <map>
#include <vector>

using namespace std;

// https://leetcode.com/problems/odd-even-jump/

class Solution {
public:
    int oddEvenJumps(vector<int>& A) {

    	enum {
    		EVEN,
			ODD,
    	};

        const size_t N = A.size();

        // Pre-construct a 2xN table of next hops (or SIZE_MAX when there is
        // no possible hop). This should be done in O( N log( N ) ) time or
        // better.

        //
        // For a given odd or even state, each step i has (at most) one next
        // element j, i < j.
        //
        // The question is, how do you efficiently compute the next steps?

    	// XXX: @CJF: I got stuck on this part. Originally, I was using
    	// a sorted vector and an unordered_map. The combined complexity was
    	// N log N, so I should have realized it was easier to just use an
    	// ordered map.
        map<int,size_t> next;

        // Since step i depends only on step j (j > i), to reach the goal, then
        // cache the results in reverse order. Step N - 1 is true (for both odd
        // and even) since starting at the goal means it is reachable.
        vector<vector<bool>> cache( 2, vector<bool>( N ) );
        cache[ EVEN ][ N - 1 ] = true;
        cache[ ODD ][ N - 1 ] = true;
        int ngood = 1;

        next[ A[ N - 1 ] ] = N - 1;

        // O( N )
        for( size_t N = A.size(), k = N - 1; k > 0; --k ) {
            const size_t i = k - 1;
            size_t j;

            auto it = next.find( A[ i ] );
            if ( next.end() == it ) {

            	// https://leetcode.com/problems/odd-even-jump/discuss/378369/c-equivalent-of-treemap
            	auto lower = next.lower_bound( A[ i ] );
            	if ( lower == next.begin() ) {
            		lower = next.end();
            	} else {
            		lower--;
            	}
            	if ( next.end() != lower ) {
                	j = lower->second;
            		cache[ EVEN ][ i ] = cache[ ODD ][ j ];
            	}

				auto higher = next.upper_bound( A[ i ] );
            	if ( next.end() != higher ) {
            		j = higher->second;
            		cache[ ODD ][ i ] = cache[ EVEN ][ j ];
            	}

            } else {

                j = it->second;
                cache[ EVEN ][ i ] = cache[ ODD ][ j ];
                cache[ ODD ][ i ] = cache[ EVEN][ j ];
            }

            // always use the lower index (true since we are decreasing i monotonically)
            next[ A[ i ] ] = i;

    		if ( cache[ ODD ][ i ] ) {
    			ngood++;
    		}
        }

        return ngood;
    }
};
