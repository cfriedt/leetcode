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

TEST_F( OptimalDivision, Test_eval ) {

    // 1 => 1
    // (1) => 1
    // 1/2 => 0.5
    // (1)/2 => 0.5
    // 1/(2) => 0.5
    // (1)/(2) => 0.5
    // ((1)/(2)) => 0.5
    // (1/2) => 0.5
    // 3/(1/2) => 6
    // 3/((1)/(2)) => 6
    // ((1)/(2))/3 => 0.16666666666666666

    // How do we evaluate an expression? Typically, division is evaluated
    // from left to right. I.e. quotient = divisor / dividend.

    // Assume that we have eliminated the degenerate case of an empty expression, but for argument's sake, let's assign
    // that a value of 0

    // An expression of length one is evaluated as the float version of itself.

    vector<int> expression;
    float expected_float;
    float actual_float;

    expression = vector<int>();
    expected_float = 0;
    actual_float = Solution::eval(expression);
    EXPECT_FLOAT_EQ( actual_float, expected_float );

    expression = vector<int>({ 1 });
    expected_float = 1;
    actual_float = Solution::eval(expression);
    EXPECT_FLOAT_EQ( actual_float, expected_float );

    expression = vector<int>({ Solution::LPAREN, 1, Solution::RPAREN });
    expected_float = 1;
    actual_float = Solution::eval(expression);
    EXPECT_FLOAT_EQ( actual_float, expected_float );

    expression = vector<int>({ 1, 2 });
    expected_float = 0.5;
    actual_float = Solution::eval(expression);
    EXPECT_FLOAT_EQ( actual_float, expected_float );

    expression = vector<int>({ Solution::LPAREN, 1, Solution::RPAREN, 2 });
    expected_float = 0.5;
    actual_float = Solution::eval(expression);
    EXPECT_FLOAT_EQ( actual_float, expected_float );

    expression = vector<int>({ 1, Solution::LPAREN, 2, Solution::RPAREN });
    expected_float = 0.5;
    actual_float = Solution::eval(expression);
    EXPECT_FLOAT_EQ( actual_float, expected_float );

    expression = vector<int>({ Solution::LPAREN, 1, Solution::RPAREN, Solution::LPAREN, 2, Solution::RPAREN });
    expected_float = 0.5;
    actual_float = Solution::eval(expression);
    EXPECT_FLOAT_EQ( actual_float, expected_float );

    expression = vector<int>({ Solution::LPAREN, Solution::LPAREN, 1, Solution::RPAREN, Solution::LPAREN, 2, Solution::RPAREN, Solution::RPAREN });
    expected_float = 0.5;
    actual_float = Solution::eval(expression);
    EXPECT_FLOAT_EQ( actual_float, expected_float );

    expression = vector<int>({ Solution::LPAREN, 1, 2, Solution::RPAREN });
    expected_float = 0.5;
    actual_float = Solution::eval(expression);
    EXPECT_FLOAT_EQ( actual_float, expected_float );

    expression = vector<int>({ 3, Solution::LPAREN, 1, 2, Solution::RPAREN });
    expected_float = 6;
    actual_float = Solution::eval(expression);
    EXPECT_FLOAT_EQ( actual_float, expected_float );

    expression = vector<int>({ Solution::LPAREN, 1, 2, Solution::RPAREN, 3 });
    expected_float = 0.16666666666666666;
    actual_float = Solution::eval(expression);
    EXPECT_FLOAT_EQ( actual_float, expected_float );

    expression = vector<int>({ 3, Solution::LPAREN, Solution::LPAREN, 1, Solution::RPAREN, Solution::LPAREN, 2, Solution::RPAREN, Solution::RPAREN });
    expected_float = 6;
    actual_float = Solution::eval(expression);
    EXPECT_FLOAT_EQ( actual_float, expected_float );

    expression = vector<int>({ Solution::LPAREN, Solution::LPAREN, 1, Solution::RPAREN, Solution::LPAREN, 2, Solution::RPAREN, Solution::RPAREN, 3 });
    expected_float = 0.16666666666666666;
    actual_float = Solution::eval(expression);
    EXPECT_FLOAT_EQ( actual_float, expected_float );

    // 2/(3/4) => 2.66666666666666666666
    expression = vector<int>({ 2, Solution::LPAREN, 3, 4, Solution::RPAREN });
    expected_float = 2.66666666666666666666;
    actual_float = Solution::eval(expression);
    EXPECT_FLOAT_EQ( actual_float, expected_float );

    // 2/3/4 => 1.66666666666666666667
    expression = vector<int>({ 2, 3, 4, });
    expected_float = 0.166666666666666666667;
    actual_float = Solution::eval(expression);
    EXPECT_FLOAT_EQ( actual_float, expected_float );

    // 5/(4/3/2/6)
    expression = vector<int>({ 5, Solution::LPAREN, 4, 3, 2, 6, Solution::RPAREN, });
    expected_float = 45;
    actual_float = Solution::eval(expression);
    EXPECT_FLOAT_EQ( actual_float, expected_float );

    // (4/3/2/6)
    expression = vector<int>({ Solution::LPAREN, 4, 3, 2, 6, Solution::RPAREN, });
    expected_float = 1.0f/9.0f;
    actual_float = Solution::eval(expression);
    EXPECT_FLOAT_EQ( actual_float, expected_float );
}

TEST_F( OptimalDivision, Test_getExpr_4_3_2_6 ) {
    // 4/3/2/6
    const size_t offset = 1;
    const vector<int> input({ 4, 3, 2, 6 });
    vector<int> expected_expression( input.begin() + offset, input.end() );
    vector<int> actual_expression = Solution::getExpr( input, offset );
    EXPECT_EQ( actual_expression, expected_expression );
}
