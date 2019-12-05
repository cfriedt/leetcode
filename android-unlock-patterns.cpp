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

#include <array>
#include <bitset>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;

class Solution {

public:

	// https://leetcode.com/problems/android-unlock-patterns

	int numberOfPatterns( int m, int n ) {

        // 1 <= m <= n <= 9

	    // key codes
	    // 0 1 2
	    // 3 4 5
	    // 6 7 8

	    int r = 0;

	    // Notes on Problem Statement
	    //
	    // It's very important to note that e.g. '0' -> '7' is a valid move.
	    // It's very important to note that e.g. '0' -> '6' is only a valid
	    // move if '3' has already been visited.

	    // Analysis
	    //
	    // Symmetry!
	    //
	    // One way to cut down on time when solving this problem is to take
	    // advantage of the symmetry of the problem. E.g. if we consider the
	    // number of solutions that begin at '0' (the top left corner), then we
	    // can simply multiply that number by 4 to determine the number of
	    // solutions contributed by all 4 corners.
	    //
	    // Similarly, if we consider the number of solutions that begin at '1'
	    // (the top side), then we can simply multiply that number by 4 to
	    // determine the number of solutions contributed by all 4 sides.
	    //
	    // Lastly, we must consider the number of solutions that begin at '4'
	    // (the center).
	    //
	    // Asymptotic
	    //
	    // naive solution:
	    // recursively iterate
	    // - pass along bitset of visited nodes
	    // - pass along reference to number of patterns
	    // - pass along min length and max length
	    // - stop when all nodes are visited
	    // - stop when unable to visit more nodes (according to rules)

	    int ncorner = 0;
	    int nside = 0;
	    int nmiddle = 0;

	    bitset<10> visited;

	    visited.reset();
	    helper( m, n, 0, ncorner, "", visited );

	    visited.reset();
	    helper( m, n, 1, nside, "", visited );

	    visited.reset();
	    helper( m, n, 4, nmiddle, "", visited );

	    r = 4 * ncorner + 4 * nside + nmiddle;

	    return r;
	}

protected:

	static void helper( const int & min_length, const int & max_length, const int & pos,
	                    int & accumulator, string path, bitset<10> visited ) {

	    path += char( '0' + pos );

	    if ( path.size() > size_t( max_length ) ) {
            return;
	    }

        visited.set( pos );

	    if ( path.size() >= size_t( min_length ) ) {
            accumulator++;
            //cout << "found path " << path << endl;
	    }

	    // first iterate over direct neighbours
        switch( pos ) {
        case 0:
        case 2:
        case 6:
        case 8:
            for( const int & n: array<int,5>{{ 1, 3, 4, 5, 7 }} ) {
                if( ! visited[ n ] ) {
                    helper( min_length, max_length, n, accumulator, path, visited );
                }
            }
            break;
        case 1:
        case 7:
            for( const int & n: array<int,7>{{ 0, 2, 3, 4, 5, 6, 8 }} ) {
                if( ! visited[ n ] ) {
                    helper( min_length, max_length, n, accumulator, path, visited );
                }
            }
            break;
        case 3:
        case 5:
            for( const int & n: array<int,7>{{ 0, 1, 2, 4, 6, 7, 8 }} ) {
                if( ! visited[ n ] ) {
                    helper( min_length, max_length, n, accumulator, path, visited );
                }
            }
            break;
        case 4:
            for( const int & n: array<int,8>{{ 0, 1, 2, 3, 5, 6, 7, 8 }} ) {
                if( ! visited[ n ] ) {
                    helper( min_length, max_length, n, accumulator, path, visited );
                }
            }
            break;
        }

        // then iterate over maybe neighbours
        switch( pos ) {
        case 0:
            for( const pair<int,int> & n_if: array<pair<int,int>,3>{{ {2,1}, {6,3}, {8,4} }} ) {
                if ( ! visited[ n_if.first ] && visited[ n_if.second ] ) {
                    helper( min_length, max_length, n_if.first, accumulator, path, visited );
                }
            }
            break;
        case 1:
            if ( !visited[ 7 ] && visited[ 4 ] ) {
                helper( min_length, max_length, 7, accumulator, path, visited );
            }
            break;
        case 2:
            for( const pair<int,int> & n_if: array<pair<int,int>,3>{{ {0,1}, {6,4}, {8,5} }} ) {
                if ( ! visited[ n_if.first ] && visited[ n_if.second ] ) {
                    helper( min_length, max_length, n_if.first, accumulator, path, visited );
                }
            }
            break;
        case 3:
            if ( !visited[ 5 ] && visited[ 4 ] ) {
                helper( min_length, max_length, 5, accumulator, path, visited );
            }
            break;
        case 5:
            if ( !visited[ 3 ] && visited[ 4 ] ) {
                helper( min_length, max_length, 3, accumulator, path, visited );
            }
            break;
        case 6:
            for( const pair<int,int> & n_if: array<pair<int,int>,3>{{ {0,3}, {2,4}, {8,7} }} ) {
                if ( ! visited[ n_if.first ] && visited[ n_if.second ] ) {
                    helper( min_length, max_length, n_if.first, accumulator, path, visited );
                }
            }
            break;
        case 7:
            if ( !visited[ 1 ] && visited[ 4 ] ) {
                helper( min_length, max_length, 1, accumulator, path, visited );
            }
            break;
        case 8:
            for( const pair<int,int> & n_if: array<pair<int,int>,3>{{ {0,4}, {2,5}, {6,7} }} ) {
                if ( ! visited[ n_if.first ] && visited[ n_if.second ] ) {
                    helper( min_length, max_length, n_if.first, accumulator, path, visited );
                }
            }
            break;
        }
	}
};
