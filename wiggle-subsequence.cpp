/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <vector>

using namespace std;

class Solution {
public:
  // https://leetcode.com/problems/wiggle-subsequence/

  int wiggleMaxLength(vector<int> &nums) {

    // Assumptions:
    // - numbers might not actually differ, so there will be a couple of corner
    //   cases
    //
    // Observations:
    // - Brute Force:
    //   -> Generate all possible subsequences O( 2^N )
    //   -> Count the number of wiggles in each O( N ), saving the longest
    //   -> O( N 2^N ) time and O( 2^N ) space
    //   -> we *CAN* do better ;-)
    // - A vector of length < 1 will have 0 wiggle sequences
    // - A vector of length 1 will have 1 wiggle sequences
    // - The first wiggle sequence in a vector of length >= 2 will only
    //   count if the first two elements differ by something other than 0.
    // - A better DP solution is to use a vector to add up the
    //   wiggles up until a particular index, i.
    // - While there might not be a wiggle at index 0, if there is, the
    //   length still counts toward the longest length
    // - It would be wise to check two different vectors, sort of like
    //   even / odd, in which case, you expect i + 1 to be greater than i
    //   and another where you expect i + 1 to be less than i.
    // - E.g nums = [ 1,17, 5,10,13,15,10, 5,16, 8]
    // - If we take out all of the non-wiggle parts, then the longest wiggle is
    //   7 elements long    [1,17,5,10,         5,16,8]. There might be other
    //   wiggles that are 7 elements long  in the vector though. We don't need
    //   to know what any of them actually are, just the length!
    //
    // Analysis
    //
    // Say we have
    // nums = [ 1,17, 5,10,13,15,10, 5,16, 8]
    // d    =   [+, -, +, +, +, -, -, +, -]
    // even = [ 1, 2, 3, 4, 4, 4, 4, 5, 6, 7]
    // odd  = [ 1, 1, 1, 1, 2, 2, 3, 3, 3, 3]
    //
    // So clearly, in this case, the even one wins, because it has
    // the highest number of wiggles.
    //
    // It's probably safe to try both, because we can't assume that the
    // longest wiggle pattern will start at element 0.
    //
    // even[ 0 ] = odd[ 0 ] = nums[ 1 ] - nums[ 0 ] > 0;
    //
    // We'll also need to remember d_last_even and d_last_odd (e.g. sgn)
    // because the idea is to continue those wiggles after a pause.
    //
    // and then we'll need to know sgn( nums[ i ] - nums[ i - 1 ] )
    //
    // to add one to either score, the sgn must not be 0, and must be the
    // opposite in sign to d_even_last and d_odd_last, respectively.

    if (nums.empty()) {
      return 0;
    }

    vector<int> dp(nums.size());

    dp[0] = 1;
    int sign_last;

    for (size_t i = 1, j = 0; i < nums.size(); i++) {

      dp[i] = dp[j];

      int delta = nums[i] - nums[j];
      int sign = sgn(delta);

      if (0 == sign) {
        continue;
      }

      if (0 == j || sign == -sign_last) {
        dp[i]++;
        sign_last = sign;
      }

      j = i;
    }

    return dp[nums.size() - 1];
  }

protected:
  int sgn(int x) {
    if (x > 0)
      return +1;
    if (x < 0)
      return -1;
    return 0;
  }
};
