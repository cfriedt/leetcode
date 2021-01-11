/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

namespace std {
template <> struct hash<vector<int>> {
  size_t operator()(const vector<int> &v) const {
    hash<int> hasher;
    size_t seed = 0;
    for (auto i : v) {
      seed ^= hasher(i);
    }
    return seed;
  }
};
} // namespace std

static unordered_set<vector<int>> to_unordered_set(vector<vector<int>> &foo) {
  unordered_set<vector<int>> bar;
  for (auto &v : foo) {
    bar.insert(v);
  }
  return bar;
}

// static vector<vector<int>> to_vector( unordered_set<vector<int>> & foo ) {
//	vector<vector<int>> bar;
//	for( auto & e: foo ) {
//		bar.push_back( e );
//	}
//	return bar;
//}

class Solution {
public:
  // https://leetcode.com/problems/3sum/

  // recursive binsearch (a bit easier to conceptualize)
  /*
  int binsearch( vector<int> & nums, int L, int R, int target ) {

          if ( L < 0 || L >= (int) nums.size() || R < 0 || R >= (int)nums.size()
  || R < L ) { return -1;
          }

          int m = ( L + R ) / 2;
          if ( target == nums[ m ] ) {
                  return m;
          }
          if ( L == R ) {
                  return -1;
          }
          if ( nums[ m ] < target ) {
                  return binsearch( nums, m + 1, R, target );
          }
          return binsearch( nums, L, m - 1, target );
  }
  */
  // nonrecursive binsearch
  int binsearch(const vector<int> &nums, int L, int R, int target) {

    int r = -1;

    for (; !(L < 0 || L >= (int)nums.size() || R < 0 || R >= (int)nums.size() ||
             R < L);) {

      int m = (L + R) / 2;
      if (target == nums[m]) {
        r = m;
        break;
      }
      if (L == R) {
        break;
      }
      if (nums[m] < target) {
        L = m + 1;
      } else {
        R = m - 1;
      }
    }

    return r;
  }

  int nextL(vector<int> &nums, int L) {
    L = (L >= 0) ? L : 0;
    L = (L < (int)nums.size()) ? L : nums.size() - 1;
    for (int t = nums[L]; t == nums[L] && L < int(nums.size()); L++)
      ;
    return L;
  }

  int nextR(vector<int> &nums, int R) {
    R = (R >= 0) ? R : 0;
    R = (R < (int)nums.size()) ? R : nums.size() - 1;
    for (int t = nums[R]; t == nums[R] && R >= 0; R--)
      ;
    return R;
  }

  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> result;

    // e.g. [-1,0,1,2,-1,-4]
    // The brute force approach is to check all unique combinations of 3
    // elements. This is an nCr problem, with n = nums.size() and r = 3
    //
    // In the above case, there are
    //
    // nCr :=     n!     := 6C3 = 20
    //        ----------
    //        r!(n - r)!
    //
    // Different items to choose.
    //
    // We would generate the items with 3 nested for loops (avoiding duplicates)
    // E.g. for( i = 0; i < N; i++ ) { for( j = i+1; j < N; j++ ) { for( k = j +
    // 1; k < N; k++ ) { ... }}}
    //
    // This makes the brute force approach O( N^M ), or O( N^3 ) in this case.
    //
    // Obviously quite bad.
    //
    // Let's see if it helps to sort the items first. That incurs an O( N log N
    // ) penalty right at the onset, but as long as the rest of the algorithm is
    // <= that, we should be ok.
    //
    sort(nums.begin(), nums.end());

    // Now we have:
    //
    // [-4,-1,-1,0,1,2]
    //
    // One approach would be to fix indices L and R and then iterate an index M
    // through, moving L and R towards 0 based on the sum of nums[ L ] + nums[ M
    // ] + nums[ R ]
    //
    // L  M  R  sum  <>
    // 0  1  5   -3  < => move m right
    // 0  3  5   -2  < => move m right
    // 0  4  5   -1  < but M == R-1 => move L right
    // 1  2  5    0  = => add to result
    //
    // Q: Does it make sense to keep moving M? Do we move L? Do we move R?
    // A: We've obviously reached an inflection point of some kind. Moving M any
    // further, with L & R fixed,
    //    would, however, implicitly bring the sum above zero. Also, moving L
    //    any further would also bring the sum above zero. Moving R means that
    //    we're free to move M again though, so let's try that.
    //
    // 1  2  4    -1 < => move m right
    // 1  3  4     0 = => add to result
    //
    //
    // The problem with this is that it still is O( N^2 )
    //
    // Q: Given that our list is sorted, can it be done with a binary search??
    // A: Yes! We will do at most 2N binary searches, each of which are O( log N
    // ), for an overall
    //    O( 2N log N ) after sorting, thus, keeping the performance at or below
    //    O( N log N )!
    //
    // Another example:
    // [-4,-3,-2,-1,0,2,3]
    //
    // L  R  M   triplet   comment
    // 0  6  -1            => increase L
    // 1  6  5   -3,0,3    => decrease R
    // 1  5  -1            => reset R, increase L
    // 2  6  3   -2,-1,3   => decrease R
    // 2  5  4   -2,0,2    => decrease R
    // 2  4  -1            => reset R, increase L
    // 3  6  5   -1,3,2    => decrease R
    // 3  5  -1            => increase L
    // 4  6  -1            => increase L
    //
    // In the cases above, M is obtained via binary search for target 0 - nums[
    // L ] - nums[ R ], where M == -1 represents failure to find the target.

    for (int L = 0; L <= int(nums.size() - 2); L++) {
      int l = nums[L];
      if (l > 0) {
        break;
      }
      if (L > 0 && l == nums[L - 1]) {
        continue;
      }
      for (int R = nums.size() - 1;; R--) {
        if (R < L + 2) {
          break;
        }
        int r = nums[R];
        if (r < 0) {
          break;
        }
        if (R < int(nums.size()) - 1 && r == nums[R + 1]) {
          continue;
        }
        int target = 0 - l - r;
        int M = binsearch(nums, L + 1, R - 1, target);
        if (-1 != M) {
          int m = nums[M];
          vector<int> candidate({l, m, r});
          result.push_back(candidate);
        }
      }
    }

    return result;
  }
};
