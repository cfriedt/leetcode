/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
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
