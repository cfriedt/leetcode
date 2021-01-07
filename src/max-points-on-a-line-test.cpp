/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "max-points-on-a-line.cpp"

using namespace std;

TEST(GCD, 5_0) { EXPECT_EQ(5, gcd(5, 0)); }
TEST(GCD, 0_5) { EXPECT_EQ(5, gcd(0, 5)); }

TEST(GCD, 5_1) { EXPECT_EQ(1, gcd(5, 1)); }
TEST(GCD, 1_5) { EXPECT_EQ(1, gcd(1, 5)); }

TEST(GCD, 4_2) { EXPECT_EQ(2, gcd(4, 2)); }
TEST(GCD, 2_4) { EXPECT_EQ(2, gcd(2, 4)); }

TEST(GCD, 18_4) { EXPECT_EQ(2, gcd(18, 4)); }
TEST(GCD, 4_18) { EXPECT_EQ(2, gcd(4, 18)); }

TEST(GCD, 4_28) { EXPECT_EQ(4, gcd(4, 28)); }
TEST(GCD, 28_4) { EXPECT_EQ(4, gcd(28, 4)); }

TEST(GCD, 7_18) { EXPECT_EQ(1, gcd(7, 18)); }
TEST(GCD, 18_7) { EXPECT_EQ(1, gcd(18, 7)); }

TEST(GCD, 160_42) { EXPECT_EQ(2, gcd(160, 42)); }
TEST(GCD, 42_160) { EXPECT_EQ(2, gcd(42, 160)); }

TEST(MaxPointsOnALine, 1_1__2_2__3_3) {
  vector<vector<int>> points = {
      {1, 1},
      {2, 2},
      {3, 3},
  };
  EXPECT_EQ(3, Solution().maxPoints(points));
}

TEST(MaxPointsOnALine, 1_1__3_2__5_3__4_1__2_3__1_4) {
  vector<vector<int>> points = {
      {1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4},
  };
  EXPECT_EQ(4, Solution().maxPoints(points));
}

TEST(MaxPointsOnALine, 0_0__0_0) {
  vector<vector<int>> points = {
      {0, 0},
      {0, 0},
  };
  EXPECT_EQ(2, Solution().maxPoints(points));
}

TEST(MaxPointsOnALine, 0_0__1_1__0_0) {
  vector<vector<int>> points = {
      {0, 0},
      {1, 1},
      {0, 0},
  };
  EXPECT_EQ(3, Solution().maxPoints(points));
}

TEST(MaxPointsOnALine, 0_0__94911150_94911151__94911151_94911152) {
  vector<vector<int>> points = {
      {0, 0}, {94911150, 94911151}, {94911151, 94911152}};
  EXPECT_EQ(2, Solution().maxPoints(points));
}

TEST(MaxPointsOnALine, 2_3__3_3__n5_3) {
  vector<vector<int>> points = {{2, 3}, {3, 3}, {-5, 3}};
  EXPECT_EQ(3, Solution().maxPoints(points));
}

TEST(MaxPointsOnALine, 3_1__12_3__3_1__n6_n1) {
  vector<vector<int>> points = {{3, 1}, {12, 3}, {3, 1}, {-6, -1}};
  EXPECT_EQ(4, Solution().maxPoints(points));
}

TEST(MaxPointsOnALine, 0_0__1_65536__65536_0) {
  vector<vector<int>> points = {{0, 0}, {1, 65536}, {65536, 0}};
  EXPECT_EQ(2, Solution().maxPoints(points));
}

TEST(
    MaxPointsOnALine,
    15_12__9_10__n16_3__n15_15__11_n10__n5_20__n3_n15__n11_n8__n8_n3__3_6__15_n14__n16_n18__n6_n8__14_9__n1_n7__n1_n2__3_11__6_20__10_n7__0_14__19_n18__n10_n15__n17_n1__8_7__20_n18__n4_n9__n9_16__10_14__n14_n15__n2_n10__n18_9__7_n5__n12_11__n17_n6__5_n17__n2_n20__15_n2__n5_n16__1_n20__19_n12__n14_n1__18_10__1_n20__n15_19__n18_13__13_n3__n16_n17__1_0__20_n18__7_19__1_n6__n7_n11__7_1__n15_12__n1_7__n3_n13__n11_2__n17_n5__n12_n14__15_n3__15_n11__7_3__19_7__n15_19__10_n14__n14_5__0_n1__n12_n4__4_18__7_n3__n5_n3__1_n11__1_n1__2_16__6_n6__n17_9__14_3__n13_8__n9_14__n5_n1__n18_n17__9_n10__19_19__16_7__3_7__n18_n12__n11_12__n15_20__n3_4__n18_1__13_17__n16_n15__n9_n9__15_8__19_n9__9_n17) {
  vector<vector<int>> points = {
      {15, 12},  {9, 10},    {-16, 3},   {-15, 15},  {11, -10},  {-5, 20},
      {-3, -15}, {-11, -8},  {-8, -3},   {3, 6},     {15, -14},  {-16, -18},
      {-6, -8},  {14, 9},    {-1, -7},   {-1, -2},   {3, 11},    {6, 20},
      {10, -7},  {0, 14},    {19, -18},  {-10, -15}, {-17, -1},  {8, 7},
      {20, -18}, {-4, -9},   {-9, 16},   {10, 14},   {-14, -15}, {-2, -10},
      {-18, 9},  {7, -5},    {-12, 11},  {-17, -6},  {5, -17},   {-2, -20},
      {15, -2},  {-5, -16},  {1, -20},   {19, -12},  {-14, -1},  {18, 10},
      {1, -20},  {-15, 19},  {-18, 13},  {13, -3},   {-16, -17}, {1, 0},
      {20, -18}, {7, 19},    {1, -6},    {-7, -11},  {7, 1},     {-15, 12},
      {-1, 7},   {-3, -13},  {-11, 2},   {-17, -5},  {-12, -14}, {15, -3},
      {15, -11}, {7, 3},     {19, 7},    {-15, 19},  {10, -14},  {-14, 5},
      {0, -1},   {-12, -4},  {4, 18},    {7, -3},    {-5, -3},   {1, -11},
      {1, -1},   {2, 16},    {6, -6},    {-17, 9},   {14, 3},    {-13, 8},
      {-9, 14},  {-5, -1},   {-18, -17}, {9, -10},   {19, 19},   {16, 7},
      {3, 7},    {-18, -12}, {-11, 12},  {-15, 20},  {-3, 4},    {-18, 1},
      {13, 17},  {-16, -15}, {-9, -9},   {15, 8},    {19, -9},   {9, -17}};
  EXPECT_EQ(6, Solution().maxPoints(points));
}

TEST(MaxPointsOnALine,
     84_250__0_0__1_0__0_n70__0_n70__1_n1__21_10__42_90__n42_n230) {
  vector<vector<int>> points = {{84, 250}, {0, 0},   {1, 0},
                                {0, -70},  {0, -70}, {1, -1},
                                {21, 10},  {42, 90}, {-42, -230}};
  EXPECT_EQ(6, Solution().maxPoints(points));
}
