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
