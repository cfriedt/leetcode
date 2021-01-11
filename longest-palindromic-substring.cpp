/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
  // https://leetcode.com/problems/longest-palindromic-substring/

  string rev(string s) {
    string r(s);
    reverse(s.begin(), s.end());
    return r;
  }

  bool ispal(string &s) {
    if (s.size() <= 1) {
      return true;
    }
    return rev(s) == s;
  }

  void helper(const std::string &s, size_t l, size_t r,
              std::string &longest_pal) {

    if (l == r) {

      if (l > 0 && l + 1 < s.length()) {
        helper(s, l - 1, l + 1, longest_pal);
      }
      if (l + 1 < s.length()) {
        helper(s, l, l + 1, longest_pal);
      }
    }

    if (s[l] != s[r]) {
      return;
    }

    size_t len = r - l + 1;

    if (len > longest_pal.length()) {
      longest_pal = s.substr(l, len);
    }

    // check boundaries before incrementing / decrementing
    if (0 == l || r == s.length() - 1) {
      return;
    }

    helper(s, l - 1, r + 1, longest_pal);
  }

  string longestPalindrome(string s) {

    // Let's see how this would be done brute force
    //
    // size_t longest = 0;
    // for( i = 0; i < s.size(); i++ ) {               // N
    //   for( len = 1; len < s.size() - i; len++ ) {   // ~N/2
    //     string sub = s.substr( i, len );            // ~O(1)
    //     string sub_rev = rev( sub );                // ~N/2
    //     if ( sub_rev == sub ) {                     // ~N/2
    //       if ( sub.length() > longest ) {
    //         longest = sub.length();
    //       }
    //     }
    //   }
    // }
    //
    // brute force approach looks to be about O( N^3 ) => pretty bad
    //
    // Let's see if an example can shed some light on a better solution
    //
    // "babad"
    //
    // "babad"          N
    // "baba","abad"    N
    // "bab"    Y => "bab", no need to check the other strings of size 3, done
    // as it is of no interest to find *smaller* palendromes
    //
    // This algorithm uses recursion, and proceeds by starting with a list of
    // strings of size 1. For each entry in the list, we check to see if any of
    // the strings in the list is a palindrome. if so, then we're done.
    //
    // Otherwise, for each entry in the list, we create two more entries by
    // using a substrings - removing the first character and then the last
    // character - and then we check that list of strings.
    //
    // This solution is probably only N^2 - still bad, but probably my best for
    // the next while.
    //
    // It will require a helper function.

    std::string longest_pal;

    for (size_t pos = 0; true && pos < s.length(); pos++) {
      helper(s, pos, pos, longest_pal);
    }

    return longest_pal;
  }
};
