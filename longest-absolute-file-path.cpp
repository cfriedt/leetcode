/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <string>
#include <vector>

using namespace std;

// https://leetcode.com/problems/longest-absolute-file-path/

class Solution {
public:
    int lengthLongestPath(string input) {

    	int lngst = 0;
    	bool file = false;
    	vector<int> plen({0});
    	vector<string> ppath({""});
    	int len = 0;
    	vector<int> depth({0});
    	string path;

        for( size_t i = 0; i < input.size(); ++i ) {
            char ch = input[ i ];
            switch( ch ) {
                case '.':
                    file = true;
                    len++;
                    //path += ch;
                    break;
                case '\n': {
                	int new_depth = 0;
                    for( size_t j = i+1; j < input.size() && '\t' == input[ j ]; j++, new_depth++ );
                    for( ; depth.back() > new_depth; ) {
                        depth.pop_back();
                        plen.pop_back();
                        //ppath.pop_back();
                    }
					if ( new_depth > depth.back() ) {
						depth.push_back( new_depth );
						plen.push_back( 1 + len );
						//ppath.push_back( ppath.back() + "/" + path );
	                    len = plen.back();
                    } else {
                    	len = plen.back();
                    }
                    i += new_depth;
                    //path = "";
                	file = false;
                    break;
                }
                default:
                    len++;
                    //path += ch;
                    break;
            }
            if ( file ) {
                lngst = max( len, lngst );
            }
        }
        return lngst;
    }
};
