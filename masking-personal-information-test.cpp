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

#include "masking-personal-information.cpp"

TEST( MaskingPersonalInformation, Test_LeetCodeATLeedCodeDOTcom ) {
	string S = "LeetCode@LeetCode.com";
	string expected_string = "l*****e@leetcode.com";
	string actual_string = Solution().maskPII(S);
	EXPECT_EQ(actual_string, expected_string);
}

TEST( MaskingPersonalInformation, Test_ABATqqDOTcom ) {
	string S = "AB@qq.com";
	string expected_string = "a*****b@qq.com";
	string actual_string = Solution().maskPII(S);
	EXPECT_EQ(actual_string, expected_string);
}

TEST( MaskingPersonalInformation, Test_1234567890 ) {
	string S = "1(234)567-890";
	string expected_string = "***-***-7890";
	string actual_string = Solution().maskPII(S);
	EXPECT_EQ(actual_string, expected_string);
}

TEST( MaskingPersonalInformation, Test_86_10_12345678 ) {
	string S = "86-(10)12345678";
	string expected_string = "+**-***-***-5678";
	string actual_string = Solution().maskPII(S);
	EXPECT_EQ(actual_string, expected_string);
}
