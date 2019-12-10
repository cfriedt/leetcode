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
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// https://leetcode.com/problems/design-search-autocomplete-system/

class AutocompleteSystem {
public:
    
    unordered_set<string> sen;
    unordered_map<string,int> tim;
    
    string q;
    
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        for( size_t i = 0; i < sentences.size(); i++ ) {
            sen.insert( sentences[ i ] );
            tim[ sentences[ i ] ] = times[ i ];
        }
    }
    
    vector<string> input(char c) {
        vector<string> res;
        
        if ( '#' == c ) {
            sen.insert( q );
            tim[ q ]++;
            q = "";
            return res;
        }

        q.push_back( c );
        

        for( auto & s: sen ) {
            if ( s.substr( 0, q.size() ) == q ) {
                res.push_back( s );
            }
        }
        
        auto cmp = [&]( const string & s1, const string & s2 ) -> bool {
            if ( tim[ s2 ] < tim[ s1 ] ) {
                return true;
            }
            if ( tim[ s2 ] == tim[ s1 ] && s2 > s1 ) {
                return true;
            }
            return false;            
        };
        sort( res.begin(), res.end(), cmp );
        
        if ( res.size() > 3 ) {
            res.erase( res.begin() + 3, res.end() );
        }
        
        return res;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
