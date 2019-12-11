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

#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#if 0
ostream & operator<<( ostream & os, const unordered_set<int> & u ) {
    os << "[";
    for( auto & x: u ) {
        os << x << ",";
    }
    os << "]";
    return os;
}
#endif

// https://leetcode.com/problems/all-paths-from-source-lead-to-destination/

class Solution {
public:

    using us = unordered_set<int>;
    using um = unordered_map<int,us>;

    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {

#if 0
        if ( 0 == n ) {
            return false;
        }
#endif

        if ( 1 == n ) {
            if ( 0 == edges.size() ) {
                return true;
            } else {
                return false;
            }
        }

        // what about if source == destination??

        bool allOk = true;

        um ds;

        for( auto & e: edges ) {
            ds[ e[ 0 ] ].insert( e[ 1 ] );
        }

        helper( us(), allOk, source, destination, ds );

        return allOk;
    }

    void helper( us visited, bool & allOk, int z, const int & d, const um & ds ) {

        //cout << "visited: " << visited << " allOk: " << allOk << " z: " << z << " d: " << d << endl;

        if ( !allOk ) {
            //cout << "!allOk" << endl;
            return;
        }

        if ( z == d ) {
            //cout << "z == d" << endl;
            if ( ds.end() != ds.find( z ) ) {
                allOk = false;
            }
            return;
        }

        if ( visited.end() != visited.find( z ) ) {
            //cout << "already visited" << endl;
            allOk = false;
            return;
        }

        visited.insert( z );

        us to_visit;

        auto it = ds.find( z );
        if ( ds.end() == it ) {
            allOk = false;
            //cout << "nowhere else to go!" << endl;
            return;
        }

        for( auto & x: ds.at( z ) ) {
            to_visit.insert( x );
        }

        for( auto & x: to_visit ) {
            helper( visited, allOk, x, d, ds );
            if ( ! allOk ) {
                //cout << "not all ok after helper" << endl;
                return;
            }
        }
    }
};
