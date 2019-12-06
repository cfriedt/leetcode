/*
 * MIT License
 *
 * Copyright (c) 2019 Christopher Friedt
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
#include <iostream>
#include <sstream>
#include <unordered_set>
#include <vector>

using namespace std;

// https://leetcode.com/problems/number-of-islands/

using Grid = vector<vector<char>>;
using coord = pair<ssize_t,ssize_t>;

namespace std {

template<>
struct hash<coord> {
    size_t operator()( const coord & key ) const {
        constexpr uint64_t seed = 0x1234abcd5678ef90;
        hash<ssize_t> hasher;
        return seed ^ hasher( key.first ) ^ hasher( key.second );
    }
};

constexpr coord UP = coord( -1, 0 );
constexpr coord DOWN = coord( 1, 0 );
constexpr coord LEFT = coord( 0, -1 );
constexpr coord RIGHT = coord( 0, 1 );

coord operator+( const coord & lhs, const coord & rhs ) {
    coord r( lhs );
    r.first += rhs.first;
    r.second += rhs.second;
    return r;
}

coord operator+=( coord & self, const coord & other ) {
    self.first += other.first;
    self.second += other.second;
    return self;
}

#if 0
string to_string( const Grid & g ) {
    ostringstream ss;
    ss << endl;
    for( auto & row: g ) {
        for( auto & col: row ) {
            ss << (( '1' == col ) ? '1' : ' ' );
            ss << ' ';
        }
        ss << endl;
    }
    string s = ss.str();
    s.pop_back();
    return s;
}
#endif

}

class Solution {
public:

    int numIslands(vector<vector<char>>& _grid) {

        const size_t _rows = _grid.size();
        if ( 0 == _rows ) {
            return 0;
        }
        const size_t _cols = _grid[ 0 ].size();
        if ( 0 == _cols ) {
            return 0;
        }

        const size_t rows = _rows + 2;
        const size_t cols = _cols + 2;

        vector<vector<char>> grid( rows, vector<char>( cols, 0 ) );

        for( size_t row = 1; row < rows - 1; row++ ) {
            copy( _grid[ row - 1 ].begin(), _grid[ row - 1 ].end(), grid[ row ].begin() + 1 );
        }

        // so my strategy here is more of an open-ended exploration algorithm
        // but it basically involves

        // 1) linear search through the grid - O(MN)
        // 2) tracing the perimeter around an island - probably bounded by O(MN)
        // 3) filling-in an island, so that it's internal pixels are > 0 as well
        //    possibly O(K), where K is the number of 1's
        // 4) eroding an island to "sink" it, i.e. turning it to all-zeros
        //    (so that the algorithm can continue without interfere with the
        //    remainder of the grid - correction - binary masking O(K)
        // 5) increment island-counter by 1
        //
        // So overall this algorithm is probably O(MNK) or O(N^3) if M, N, and K are similar
        //
        // There may be a better DP solution..
        //
        // I previously thought about implementing an edge & corner detection algorithm
        // which is nice because it's linear, but it seems more complicated, generally,
        // and we're not necessarily looking for

        //cerr << to_string( grid ) << endl;

        int n_islands = 0;
        for( size_t row = 0; row < rows; row++ ) {
            for( size_t col = 0; col < cols; col++ ) {
                if ( '1' == grid[ row ][ col ] ) {
                    coord c( row, col );
                    island isle( grid, c );
                    traceIsland(isle);
                    fillIsland(isle);
                    erodeIsland(isle);
                    //cerr << to_string( grid ) << endl;
                    n_islands++;
                }
            }
        }

        return n_islands;
    }

protected:

    struct island {

        explicit island( Grid & g, const coord & c )
        :
            grid( g ),
            perimeter( vector<coord>{{c.first - 1, c.second}} ),
            dirt( unordered_set<coord>{ c } )
        {
        }

        Grid & grid;
        vector<coord> perimeter;
        unordered_set<coord> dirt;

        char getGrid( const coord & c ) const {
            return grid[ c.first ][ c.second ];
        }
    };

    void traceIsland( island & isle ) {
        // we will always start out such that the first encountered '1' is
        // at ( perimeter[ 0 ].first + 1, perimeter[ 0 ].second )
        // the row at perimeter[ 0 ].first is guaranteed to be all zeros
        //
        // we can also begin in the RIGHT direction

        coord dir = RIGHT;
        coord origin = isle.perimeter[0];
        coord here = origin;

        for( ;; ) {
            if ( here == origin && 1 != isle.perimeter.size() ) {
                break;
            }

            // Catholicism, WOW!! (just a joke about the ordering I chose "naturally" chose for this... )
            if ( false ) {
            } else if ( UP == dir ) {
                if ( '1' == isle.getGrid( here + UP + RIGHT ) ) {
                   if ( '1' == isle.getGrid( here + UP ) ) {
                       // island turns left
                       dir = LEFT;
                   } else {
                       // island continues up
                       isle.perimeter.push_back( here + UP );
                       here += UP;
                   }
                } else {
                   // if the island does not continue up, keep it to the right of the
                   // new direction, so go right
                   dir = RIGHT;
                   isle.perimeter.push_back( here + UP + RIGHT );
                   here += UP + RIGHT;
                }
            } else if ( DOWN == dir ) {
                if ( '1' == isle.getGrid( here + DOWN + LEFT ) ) {
                   if ( '1' == isle.getGrid( here + DOWN ) ) {
                       // island turns right
                       dir = RIGHT;
                   } else {
                       // island continues down
                       isle.perimeter.push_back( here + DOWN );
                       here += DOWN;
                   }
                } else {
                   // if the island does not continue down, keep it to the right of the
                   // new direction, so go left
                   dir = LEFT;
                   isle.perimeter.push_back( here + DOWN + LEFT );
                   here += DOWN + LEFT;
                }
            } else if ( LEFT == dir ) {
                if ( '1' == isle.getGrid( here + UP + LEFT ) ) {
                   if ( '1' == isle.getGrid( here + LEFT ) ) {
                       // island turns down
                       dir = DOWN;
                   } else {
                       // island continues left
                       isle.perimeter.push_back( here + LEFT );
                       here += LEFT;
                   }
                } else {
                   // if the island does not continue left, keep it to the right of the
                   // new direction, so go up
                   dir = UP;
                   isle.perimeter.push_back( here + UP + LEFT );
                   here += UP + LEFT;
                }
            } else if ( RIGHT == dir ) {
                // a '1' is known to be at (row+1,col)

                if ( '1' == isle.getGrid( here + DOWN + RIGHT ) ) {
                    if ( '1' == isle.getGrid( here + RIGHT ) ) {
                        // island turns upward
                        dir = UP;
                    } else {
                        // island continues right
                        isle.perimeter.push_back( here + RIGHT );
                        here += RIGHT;
                    }
                } else {
                    // if the island does not continue to the right, keep it to the right of the
                    // new direction, so go down
                    dir = DOWN;
                    isle.perimeter.push_back( here + DOWN + RIGHT );
                    here += DOWN + RIGHT;
                }
            } else {
                throw logic_error( "Aaaiiiieeeeee!" );
            }
        }
    }

    void fillIsland( island & isle ) {
        // for now, ignore any potential "lakes" assume that islands are solid.

        // The typical strategy for this is to take a seed point and "grow" it
        // recursively. This function isn't designed to be recursive though, so
        // maybe just having a set of seed points to check should be fine

        unordered_set<coord> seeds;
        unordered_set<coord> perimeter;
        unordered_set<coord> dirt;

        for( auto & p: isle.perimeter ) {
            perimeter.insert( p );
        }

        seeds.insert( isle.perimeter[ 0 ] + DOWN );

        for( ; ! seeds.empty() ; ) {

            coord seed = *seeds.begin();
            seeds.erase( seed );
            dirt.insert( seed );

            for( auto & x: array<coord,4> { seed + UP, seed + DOWN, seed + LEFT, seed + RIGHT  } ) {
                if ( '1' == isle.getGrid( x ) && perimeter.end() == perimeter.find( x ) && dirt.end() == dirt.find( x ) ) {
                    seeds.insert( x );
                }
            }
        }

        isle.dirt = dirt;
    }

    void erodeIsland( island & isle ) {
        // actually, we don't even need to do an erode, because we just need to binary mask the original grid
        for( auto & d: isle.dirt ) {
            isle.grid[ d.first ][ d.second ] = '0';
        }
    }
};
