/*
 * Copyright (c) 2019 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
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
