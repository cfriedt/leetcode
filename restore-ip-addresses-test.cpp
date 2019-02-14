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

#include <unordered_set>

#include <gtest/gtest.h>

#include "restore-ip-addresses.cpp"

TEST( RestoreIpAddresses, Test_25525511135 ) {
	string s = "25525511135";
	unordered_set<string> expected_uss({"255.255.11.135","255.255.111.35"});
	vector<string> output = Solution().restoreIpAddresses(s);
	unordered_set<string> actual_uss( output.begin(), output.end() );
	EXPECT_EQ(actual_uss, expected_uss);
}

TEST( RestoreIpAddresses, Test_too_short ) {
	string s = "123";
	unordered_set<string> expected_uss;
	vector<string> output = Solution().restoreIpAddresses(s);
	unordered_set<string> actual_uss( output.begin(), output.end() );
	EXPECT_EQ(actual_uss, expected_uss);
}

TEST( RestoreIpAddresses, Test_too_long ) {
	string s = "111222333444555";
	unordered_set<string> expected_uss;
	vector<string> output = Solution().restoreIpAddresses(s);
	unordered_set<string> actual_uss( output.begin(), output.end() );
	EXPECT_EQ(actual_uss, expected_uss);
}

TEST( RestoreIpAddresses, Test_invalid ) {
	string s = "abcdefghijkl";
	unordered_set<string> expected_uss;
	vector<string> output = Solution().restoreIpAddresses(s);
	unordered_set<string> actual_uss( output.begin(), output.end() );
	EXPECT_EQ(actual_uss, expected_uss);
}

TEST( RestoreIpAddresses, Test_leading_zeros ) {
	string s = "010010";
	unordered_set<string> expected_uss({"0.10.0.10","0.100.1.0"});
	vector<string> output = Solution().restoreIpAddresses(s);
	unordered_set<string> actual_uss( output.begin(), output.end() );
	EXPECT_EQ(actual_uss, expected_uss);
}
