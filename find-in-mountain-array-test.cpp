/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <vector>

#include <gtest/gtest.h>

using namespace std;

class MountainArray {
public:
  explicit MountainArray(const vector<int> &A) : nQueries(0), A(A) {}

  int get(int index) {
    if (nQueries == 100) {
      throw runtime_error("no more guesses left :(");
    }
    nQueries++;
    return A[index];
  }
  int length() { return int(A.size()); }

protected:
  size_t nQueries;
  const vector<int> A;
};

#include "find-in-mountain-array.cpp"

TEST(FindInMountainArray, Test_1_2_3_4_5_3_1__3) {
  MountainArray mountainArr(vector<int>{{1, 2, 3, 4, 5, 3, 1}});
  int target = 3;
  int expected_int = 2;
  int actual_int = Solution().findInMountainArray(target, mountainArr);
  EXPECT_EQ(actual_int, expected_int);
}

TEST(FindInMountainArray, Test_0_1_2_4_2_1__3) {
  MountainArray mountainArr(vector<int>{{0, 1, 2, 4, 2, 1}});
  int target = 3;
  int expected_int = -1;
  int actual_int = Solution().findInMountainArray(target, mountainArr);
  EXPECT_EQ(actual_int, expected_int);
}

TEST(FindInMountainArray, Test_0_5_3_1__1) {
  MountainArray mountainArr(vector<int>{{0, 5, 3, 1}});
  int target = 1;
  int expected_int = 3;
  int actual_int = Solution().findInMountainArray(target, mountainArr);
  EXPECT_EQ(actual_int, expected_int);
}

TEST(FindInMountainArray, Test_0_1_0__1) {
  MountainArray mountainArr(vector<int>{{0, 1, 0}});
  int target = 1;
  int expected_int = 1;
  int actual_int = Solution().findInMountainArray(target, mountainArr);
  EXPECT_EQ(actual_int, expected_int);
}
