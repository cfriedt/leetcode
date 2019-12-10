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
#include <unordered_set>
#include <vector>

using namespace std;

// https://leetcode.com/problems/sentence-similarity/

class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        
        if ( words1.size() != words2.size() ) {
            return false;
        }
        
        using ums = unordered_map<string,unordered_set<string>>;
        
        ums to;
        ums fro;
        
        for( auto & p: pairs ) {
            to[ p[ 0 ] ].insert( p[ 1 ] );               
            fro[ p[ 1 ] ].insert( p[ 0 ] );   
        }
        
        for( size_t i = 0, N = words1.size(); i < N; ++i ) {
            if ( words1[ i ] == words2[ i ] ) {
                continue;
            }
            
            auto it1 = to.find( words1[ i ] );
            if ( to.end() != it1 ) {
                if ( it1->second.end() != it1->second.find( words2[ i ] ) ) {
                    continue;
                }
            }
            
            auto it2 = fro.find( words1[ i ] );
            if ( fro.end() != it2 ) {
                if ( it2->second.end() != it2->second.find( words2[ i ] ) ) {
                    continue;
                }
            }

            return false;
        }
        
        return true;
    }
};

