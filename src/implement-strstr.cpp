/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <climits>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:

	// https://leetcode.com/problems/implement-strstr

	int strStr(string haystack, string needle) {
        if ( "" == haystack && "" == needle ) {
			return 0;
		}
        if ( needle.length() > haystack.length() ) {
			return -1;
		}
		for( size_t i = 0; i < haystack.length() - needle.length() + 1; i++ ) {
			if ( needle == haystack.substr( i, needle.length() ) ) {
				return i;
			}
		}
		return -1;
    }
};
