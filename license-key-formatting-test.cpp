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

#include "license-key-formatting.cpp"

TEST( LicenseKeyFormatting, Test_5F3Z_2e_9_w__4 ) {
	string S = "5F3Z-2e-9-w";
	int K = 4;
	string expected_string = "5F3Z-2E9W";
	string actual_string = Solution().licenseKeyFormatting(S, K);

	EXPECT_EQ( actual_string, expected_string );
}

TEST( LicenseKeyFormatting, Test_2_5g_3_J__2 ) {
	string S = "2-5g-3-J";
	int K = 2;
	string expected_string = "2-5G-3J";
	string actual_string = Solution().licenseKeyFormatting(S, K);

	EXPECT_EQ( actual_string, expected_string );
}
