/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "optimal-division.cpp"

using namespace std;

class OptimalDivision : public Solution, public ::testing::Test {
public:
  OptimalDivision() : Solution() {}
};

TEST_F(OptimalDivision, Test_empty) {
  vector<int> nums;
  string expected_string("");
  string actual_string = optimalDivision(nums);
  EXPECT_EQ(actual_string, expected_string);
}
TEST_F(OptimalDivision, Test_1) {
  vector<int> nums({1});
  string expected_string("1");
  string actual_string = optimalDivision(nums);
  EXPECT_EQ(actual_string, expected_string);
}
TEST_F(OptimalDivision, Test_1_2) {
  vector<int> nums({1, 2});
  string expected_string("1/2");
  string actual_string = optimalDivision(nums);
  EXPECT_EQ(actual_string, expected_string);
}
TEST_F(OptimalDivision, Test_2_3_4) {
  vector<int> nums = {2, 3, 4};
  string expected_string("2/(3/4)");
  string actual_string = optimalDivision(nums);
  EXPECT_EQ(actual_string, expected_string);
}
TEST_F(OptimalDivision, Test_1000_100_10_2) {
  vector<int> nums = {1000, 100, 10, 2};
  string expected_string("1000/(100/10/2)");
  string actual_string = optimalDivision(nums);
  EXPECT_EQ(actual_string, expected_string);
}

TEST_F(OptimalDivision, Test_5_4_3_2_6) {
  vector<int> nums = {5, 4, 3, 2, 6};
  string expected_string("5/(4/3/2/6)");
  string actual_string = optimalDivision(nums);
  EXPECT_EQ(actual_string, expected_string);
}

TEST_F(OptimalDivision, Test_5_2_9_4_7_3_10_8_8_2) {
  vector<int> nums = {5, 2, 9, 4, 7, 3, 10, 8, 8, 2};
  string expected_string("5/(2/9/4/7/3/10/8/8/2)");
  string actual_string = optimalDivision(nums);
  EXPECT_EQ(actual_string, expected_string);
}
