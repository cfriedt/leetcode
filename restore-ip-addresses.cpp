/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <array>
#include <numeric>
#include <regex>
#include <vector>

using namespace std;

class Solution {
public:
  // https://leetcode.com/problems/restore-ip-addresses/

  vector<string> restoreIpAddresses(string s) {

    // Assumptions
    // - all zeros ip address is OK
    // - all ones ip address is ok
    // - no rules like netmask, etc
    //
    // Observations
    // - octet pattern is "^(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])$"
    // - each octet in an IP address (in string format) is 1-3 characters
    // - I can brute-force the entire range of octet lengths in 81 tries :-)
    //   1.1.1.1
    //   1.1.1.2
    //   ...
    //   3.3.3.3
    // - really, those numbers are base 3, so the counting will be 0,1,2
    // - 3^4 = 81 possibilities
    // - Only some of the 81 possibilities will match up exactly to the length
    //   of the given string.
    // - only some so the algorithm is really O( 1 ) in the worst
    //   case scenario :-)
    // - only some of the some of the 81 possibilities will actually make it
    //   through the regex comparison.
    // - need to write toBase3PlusOne()
    //
    // Can we do better? Probably, but it's late, and this took me all of 5
    // minutes to come up with.
    //
    // I suppose it would be possible to play the game of "pick where the
    // dot goes". Could probably be done recursively. I'm just not sure
    // if it's faster.
    //
    // Also, cannot simply use sscanf to parse the integer value, because
    // it will (for some reason), accept leading zeros.
    //
    // Analysis:
    // O(1) in time, or possibly O( M ) where M is the length of the
    // internal automata used to parse the IP address string.
    // O(1) in space. Very little extra storage is used, but it's constant,
    // in any case.

    vector<string> r;

    if (s.length() < 4 || s.length() > 12) {
      return r;
    }

    for (uint8_t i = 0; i < 81; i++) {
      array<uint8_t, 4> substring_lengths = toBase3PlusOne(i);
      if (accumulate(substring_lengths.begin(), substring_lengths.end(),
                     size_t(0)) != s.size()) {
        continue;
      }

      string ipstr;
      for (size_t offs = 0, i = 0; i < 4; offs += substring_lengths[i], i++) {
        string sub = s.substr(offs, substring_lengths[i]);
        if (!regex_search(sub, octet_regex)) {
          break;
        }
        ipstr += sub;
        if (i + 1 < 4) {
          ipstr += ".";
        }
        if (3 == i) {
          r.push_back(ipstr);
        }
      }
    }

    return r;
  }

protected:
  static const string octet_pattern;
  static const regex octet_regex;

  array<uint8_t, 4> toBase3PlusOne(uint8_t x) {
    array<uint8_t, 4> r;
    for (size_t i = 0; i < r.size(); i++) {
      r[i] = x % 3 + 1;
      x /= 3;
    }
    return r;
  }
};

const string
    Solution::octet_pattern("^(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])$");
const regex Solution::octet_regex(Solution::octet_pattern,
                                  std::regex_constants::ECMAScript);
