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

#include "car-fleet.cpp"

using namespace std;

TEST( CarFleet, Test_12__10_8_0_5_3__2_4_1_1_3 ) {
	int target = 12;
	vector<int> position{10,8,0,5,3};
	vector<int> speed{2,4,1,1,3};
	int expected_int = 3;
	int actual_int = Solution().carFleet(target, position, speed);
	EXPECT_EQ( actual_int, expected_int );
}

TEST( CarFleet, Test_10__empty__empty__noCars ) {
    int target = 10;
    vector<int> position;
    vector<int> speed;
    int expected_int = 0;
    int actual_int = Solution().carFleet(target, position, speed);
    EXPECT_EQ( actual_int, expected_int );
}

TEST( CarFleet, Test_10__0_1__oneCar ) {
    int target = 10;
    vector<int> position;
    vector<int> speed;
    int expected_int = 1;
    int actual_int = Solution().carFleet(target, position, speed);
    EXPECT_EQ( actual_int, expected_int );
}

TEST( CarFleet, Test_10__1_1_1_1_1__1_2_3_4_5__multipleCarsSameStartingPositionDifferentSpeeds ) {
    int target = 10;
    vector<int> position{1,1,1,1,1};
    vector<int> speed{1,2,3,4,5};
    int expected_int = 1;
    int actual_int = Solution().carFleet(target, position, speed);
    EXPECT_EQ( actual_int, expected_int );
}

TEST( CarFleet, Test_10__1_1_1_1_1__5_5_5_5_5__multipleCarsSameStartingPositionSameSpeeds ) {
    int target = 10;
    vector<int> position{1,1,1,1,1};
    vector<int> speed{1,2,3,4,5};
    int expected_int = 1;
    int actual_int = Solution().carFleet(target, position, speed);
    EXPECT_EQ( actual_int, expected_int );
}

TEST( CarFleet, Test_10__1_2_3_4_5__1_1_1_1_1__sameVelocity ) {
    int target = 10;
    vector<int> position{1,2,3,4,5};
    vector<int> speed{1,1,1,1,1};
    int expected_int = 5;
    int actual_int = Solution().carFleet(target, position, speed);
    EXPECT_EQ( actual_int, expected_int );
}

TEST( CarFleet, Test_10__1_2_3_4_5__5_4_3_2_1__multipleCarsDecreasingSpeeds ) {
    int target = 10;
    vector<int> position{1,2,3,4,5};
    vector<int> speed{5,4,3,2,1};
    int expected_int = 1;
    int actual_int = Solution().carFleet(target, position, speed);
    EXPECT_EQ( actual_int, expected_int );
}

TEST( CarFleet, Test_10__1_2_3_4_5__1_2_3_4_5__multipleCarsIncreasingSpeeds ) {
    int target = 10;
    vector<int> position{1,2,3,4,5};
    vector<int> speed{5,4,3,2,1};
    int expected_int = 5;
    int actual_int = Solution().carFleet(target, position, speed);
    EXPECT_EQ( actual_int, expected_int );
}
