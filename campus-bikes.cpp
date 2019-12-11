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
#include <cmath>
#include <tuple>
#include <unordered_set>
#include <vector>

using namespace std;

// https://leetcode.com/problems/campus-bikes/

class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {

        const size_t N = workers.size();
        const size_t M = bikes.size();

        vector<int> ans( N, -1 );

        auto manhattan = [&]( size_t ww, size_t bb ) -> size_t {
            return size_t(
                0
                + abs( workers[ww][ 0 ] - bikes[bb][ 0 ] )
                + abs( workers[ww][ 1 ] - bikes[bb][ 1 ] )
            );
        };

        unordered_set<size_t> workers_done; // workers who have already been paired
        unordered_set<size_t> bikes_done; // workers who have already been paired
        using e = tuple<size_t,size_t,size_t>; // (dist,w,b)
        vector<e> minHeap;

        struct comparator {
            bool operator()( const e & a, const e & b ) {
                size_t dist_a = get<0>( a );
                size_t dist_b = get<0>( b );
                //cout << "comparing dist_a: " << dist_a << " and dist_b: " << dist_b;
                if ( dist_a > dist_b ) {
                    // compare distance first
                    //cout << " true" << endl;
                    return true;
                }
                if ( dist_a < dist_b ) {
                    // compare distance first
                    //cout << " false" << endl;
                    return false;
                }

                size_t w_a = get<1>( a );
                size_t w_b = get<1>( b );
                //cout << "comparing w_a: " << w_a << " and w_b: " << w_b;
                if ( w_a > w_b ) {
                    // next compare worker id
                    //cout << " true" << endl;
                    return true;
                }
                if ( w_a < w_b ) {
                    // next compare worker id
                    //cout << " false" << endl;
                    return false;
                }

                // lastly compare bike id
                size_t b_a = get<2>( a );
                size_t b_b = get<2>( b );

                //cout << "comparing b_a: " << b_a << " and b_b: " << b_b;
                bool r = b_a > b_b;
                //cout << " " << r << endl;
                return r;
            }
        };

        //cout << "input" << endl;
        for( size_t w = 0; w < N; ++w ) {
            for( size_t b = 0; b < M; ++b ) {
                size_t dist = manhattan( w, b );

                //cout << "w: " << w << " b: " << b << " dist: " << dist << endl;

                e e( dist, w, b );
                minHeap.push_back( e );
                push_heap( minHeap.begin(), minHeap.end(), comparator() );
            }
        }

        //cout << "output" << endl;
        for( ; workers_done.size() != N; ) {

            e e = minHeap.front();
            pop_heap( minHeap.begin(), minHeap.end(), comparator() );
            minHeap.pop_back();

            //size_t dist = get<0>( e );
            size_t w = get<1>( e );
            size_t b = get<2>( e );

            if ( workers_done.end() != workers_done.find( w ) ) {
                continue;
            }
            if ( bikes_done.end() != bikes_done.find( b ) ) {
                continue;
            }

            workers_done.insert( w );
            bikes_done.insert( b );

            //cout << "w: " << w << " b: " << b << " dist: " << dist << endl;

            ans[ w ] = b;
        }

        return ans;
    }
};
