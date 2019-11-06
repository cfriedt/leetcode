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

#include <gtest/gtest.h>

#include "optimal-division.cpp"

using namespace std;

class OptimalDivision : public Solution, public ::testing::Test {
public:
    OptimalDivision() : Solution() {}
};


TEST_F( OptimalDivision, Test_empty ) {
    vector<int> nums;
    string expected_string( "" );
    string actual_string = optimalDivision(nums);
    EXPECT_EQ(actual_string, expected_string);
}
TEST_F( OptimalDivision, Test_1 ) {
    vector<int> nums({ 1 });
    string expected_string( "1" );
    string actual_string = optimalDivision(nums);
    EXPECT_EQ(actual_string, expected_string);
}
TEST_F( OptimalDivision, Test_1_2 ) {
    vector<int> nums({ 1, 2 });
    string expected_string( "1/2" );
    string actual_string = optimalDivision(nums);
    EXPECT_EQ(actual_string, expected_string);
}
TEST_F( OptimalDivision, Test_2_3_4 ) {
    vector<int> nums = { 2, 3, 4 };
    string expected_string( "2/(3/4)" );
    string actual_string = optimalDivision(nums);
    EXPECT_EQ(actual_string, expected_string);
}
TEST_F( OptimalDivision, Test_1000_100_10_2 ) {
    vector<int> nums = { 1000, 100, 10, 2 };
    string expected_string( "1000/(100/10/2)" );
    string actual_string = optimalDivision(nums);
    EXPECT_EQ(actual_string, expected_string);
}

TEST_F( OptimalDivision, Test_5_4_3_2_6 ) {
    vector<int> nums = { 5, 4, 3, 2, 6 };
    string expected_string( "5/(4/3/2/6)" );
    string actual_string = optimalDivision(nums);
    EXPECT_EQ(actual_string, expected_string);
}

TEST_F( OptimalDivision, Test_5_2_9_4_7_3_10_8_8_2 ) {
    vector<int> nums = { 5,2,9,4,7,3,10,8,8,2 };
    string expected_string( "5/(2/9/4/7/3/10/8/8/2)" );
    string actual_string = optimalDivision(nums);
    EXPECT_EQ(actual_string, expected_string);
}
