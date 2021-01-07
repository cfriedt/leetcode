/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "longest-absolute-file-path.cpp"

TEST( LongestAbsoluteFilePath, Test_dir__subdir1__subdir2___file_ext ) {
	string input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
	int expected_int = 20;
	int actual_int = Solution().lengthLongestPath( input );
	EXPECT_EQ( actual_int, expected_int );
}

TEST( LongestAbsoluteFilePath, Test_dir__subdir1___file1_ext___subsubdir1__subdir2___subsubdir2____file2_ext ) {
	string input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
	int expected_int = 32;
	int actual_int = Solution().lengthLongestPath( input );
	EXPECT_EQ( actual_int, expected_int );
}

TEST( LongestAbsoluteFilePath, Test_a__aa___aaa____file1_txt_aaaaaaaaaaaaaaaaaaaaa__sth_png ) {
	string input = "a\n\taa\n\t\taaa\n\t\t\tfile1.txt\naaaaaaaaaaaaaaaaaaaaa\n\tsth.png";
	int expected_int = 29;
	int actual_int = Solution().lengthLongestPath( input );
	EXPECT_EQ( actual_int, expected_int );
}
