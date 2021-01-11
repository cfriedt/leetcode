/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <bitset>
#include <string>

using namespace std;

class Solution {
public:
  // https://leetcode.com/problems/longest-substring-without-repeating-characters/

  int lengthOfLongestSubstring(string s) {

    //
    // example: abcabcbb => 3
    //
    // Assumptions:
    // - The longest substring without repeating characters could occur anywhere
    // in the string.
    //
    // Shortcuts:
    // - if s is empty, return 0
    // - if s is of length 1, return 1
    //
    // Looking at the example, my first instinct would be to see if I could do
    // this linearly just maintaining a couple of indices.
    //
    // Let's say we have two indices, L and R, and both are initialized to zero.
    // A substring will be defined as [L,R) noninclusively.
    //
    // Also, let's maintain a "longest" variable that we will compare each
    // substring to.
    //
    // Additionally, to keep track of letters we have seen, we could employ
    // either a LUT (e.g. array<bool,256>) or an unorderd_set<char>, because we
    // only need to know a true or false
    // - have wee seen char x yet? - rather than keep a count.
    // CORRECTION: use a bitset :-)
    //
    // L    R   s[ R ]    LUT        longest   comment
    // 0    0   a         []         0         we haven't seen a, so add it to
    // the LUT and our longest is 1 0    1   b         [a]        1         we
    // haven't seen b, so add it to the LUT and our longest is 2 0    2   c [ab]
    // 2         we haven't seen c, so add it to the LUT and our longest is 3 0
    // 3   a         [abc]      3         we HAVE seen a, so set L to R and
    // clear the LUT 4    4   b         [abc]      3         we HAVE seen b, SO
    // SET L to R and clear the LUT 5    5   c         [abc]      3
    // ..
    // end of array s reached, return 3
    //
    //
    // Algorithm Analysis:
    //
    // Well, we only go through the list once, and since the LUT / unordered_map
    // approach is O( 1 ), the overall algorithm is O( N ) in time complexity
    // and O( N ) in space complexity.
    //
    // Structurally, I don't see how it would be possible to reduce that
    // further. The "brute force" approach is O( N^2 ) ish.
    //
    // So let's code it!
    //
    // Uh-oh... "pwwkew" => "wke" required a small workaround
    //
    // Uh-oh... "dvdf" => "vdf" is a bit perplexing..
    // Should I be setting L to R when a previously seen character is
    // encountered??
    //
    // I wonder if I should try advancing L forward incrementally, rather than
    // jumping ahead to R.
    //
    // let's try this again with "dvdf" => "vdf"
    //
    // L    R     LUT     longest   comment
    // 0    0     []      0         haven't seen s[R] (d), eval longest, lut +
    // s[R], advance R. 0    1     [d]     1         haven't seen s[R] (v), eval
    // longest, lut + s[R], advance R. 0    2     [dv]    2         *have* seen
    // s[R] (d),
    //                              now if I increment only L and not R too,
    //                              then we'll see the same s[R] in lut, but by
    //                              definition, I can remove the lut[s[R]]
    //                              because it is duplicated by s[R]. Then I
    //                              should be able to continue with the same
    //                              algorithm.
    //                              => unset lut[s[R]], advance L
    // 1    2     [v]     2         haven't seen s[R] (d), eval longest, lut +
    // s[R], advance R 1    3     [dv]    2         haven't seen s[R] (f), eval
    // longest, lut + s[R], advance R 1    4     [dvf]   3         reached end
    // of s

    bitset<256> lut;

    size_t longest = 0;
    for (size_t L = 0, R = 0; L < s.size() && R < s.size();) {
      if (lut[s[R]]) {
        lut[s[L]] = 0;
        L++;
        continue;
      }

      if (R - L + 1 > longest) {
        longest = R - L + 1;
      }
      lut[s[R]] = 1;
      R++;
    }

    return int(longest);
  }
};
