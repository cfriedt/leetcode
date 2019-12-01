/*
 * MIT License
 *
 * Copyright (c) 2018 Christopher Friedt
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <vector>

#include <gtest/gtest.h>

#include "maximize-distance-to-closest-person.cpp"

using namespace std;

TEST( MaximizeDistanceToClosestPerson, Test_1000101 ) {
    vector<int> seats({1,0,0,0,1,0,1});
    int expected_int = 2;
    int actual_int = Solution().maxDistToClosest(seats);
    EXPECT_EQ( actual_int, expected_int );
}

#if 0

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
