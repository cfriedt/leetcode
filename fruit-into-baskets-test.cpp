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

#include "fruit-into-baskets.cpp"

TEST( FruitIntoBaskets, Test_1_2_1 ) {
	vector<int> tree({1,2,1});
	int expected_int = 3;
	int actual_int = Solution().totalFruit(tree);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( FruitIntoBaskets, Test_0_1_2_2 ) {
	vector<int> tree({0,1,2,2});
	int expected_int = 3;
	int actual_int = Solution().totalFruit(tree);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( FruitIntoBaskets, Test_1_2_3_2_2 ) {
	vector<int> tree({1,2,3,2,2});
	int expected_int = 4;
	int actual_int = Solution().totalFruit(tree);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( FruitIntoBaskets, Test_3_3_3_1_2_1_1_2_3_3_4 ) {
	vector<int> tree({3,3,3,1,2,1,1,2,3,3,4});
	int expected_int = 5;
	int actual_int = Solution().totalFruit(tree);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( FruitIntoBaskets, Test_1_0_1_4_1_4_1_2_3) {
	vector<int> tree({1,0,1,4,1,4,1,2,3});
	int expected_int = 5;
	int actual_int = Solution().totalFruit(tree);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( FruitIntoBaskets, Test_1_0_0_0_1_0_4_0_4) {
	vector<int> tree({1,0,0,0,1,0,4,0,4});
	int expected_int = 6;
	int actual_int = Solution().totalFruit(tree);
	EXPECT_EQ(actual_int, expected_int);
}
