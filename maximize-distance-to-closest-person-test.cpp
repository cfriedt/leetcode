/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <vector>

#include <gtest/gtest.h>

#include "maximize-distance-to-closest-person.cpp"

using namespace std;

TEST( MaximizeDistanceToClosestPerson, Test_nothing ) {
}

#if 0

TEST( MaximizeDistanceToClosestPerson, Test_1000101 ) {
    vector<int> seats({1,0,0,0,1,0,1});
    int expected_int = 2;
    int actual_int = Solution().maxDistToClosest(seats);
    EXPECT_EQ( actual_int, expected_int );
}

TEST( MaximizeDistanceToClosestPerson, Test_01 ) {
    vector<int> seats({0,1});
    int expected_int = 1;
    int actual_int = Solution().maxDistToClosest(seats);
    EXPECT_EQ( actual_int, expected_int );
}

TEST( MaximizeDistanceToClosestPerson, Test_10 ) {
    vector<int> seats({1,0});
    int expected_int = 1;
    int actual_int = Solution().maxDistToClosest(seats);
    EXPECT_EQ( actual_int, expected_int );
}

TEST( MaximizeDistanceToClosestPerson, Test_100101 ) {
    vector<int> seats({1,0,0,1,0,1});
    int expected_int = 1;
    int actual_int = Solution().maxDistToClosest(seats);
    EXPECT_EQ( actual_int, expected_int );
}

TEST( MaximizeDistanceToClosestPerson, Test_0001 ) {
    vector<int> seats({0,0,0,1});
    int expected_int = 3;
    int actual_int = Solution().maxDistToClosest(seats);
    EXPECT_EQ( actual_int, expected_int );
}

TEST( MaximizeDistanceToClosestPerson, Test_000101 ) {
    vector<int> seats({0,0,0,1,0,1});
    int expected_int = 3;
    int actual_int = Solution().maxDistToClosest(seats);
    EXPECT_EQ( actual_int, expected_int );
}

TEST( MaximizeDistanceToClosestPerson, Test_1000 ) {
    vector<int> seats({1,0,0,0});
    int expected_int = 3;
    int actual_int = Solution().maxDistToClosest(seats);
    EXPECT_EQ( actual_int, expected_int );
}

TEST( MaximizeDistanceToClosestPerson, Test_101000 ) {
    vector<int> seats({1,0,1,0,0,0});
    int expected_int = 3;
    int actual_int = Solution().maxDistToClosest(seats);
    EXPECT_EQ( actual_int, expected_int );
}

TEST( MaximizeDistanceToClosestPerson, Test_1100010 ) {
    vector<int> seats({1,1,0,0,0,1,0});
    int expected_int = 2;
    int actual_int = Solution().maxDistToClosest(seats);
    EXPECT_EQ( actual_int, expected_int );
}
#endif
