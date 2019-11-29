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

#include <algorithm>
#include <exception>

#include <gtest/gtest.h>

#include "find-and-replace-pattern.cpp"

TEST( FindAndReplacePattern, Test_abc_deq_mee_aqq_dkd_ccc__abb ) {
	vector<string> words({"abc","deq","mee","aqq","dkd","ccc"});
	string pattern("abb");

	vector<string> expected_sv({"mee","aqq"});
	vector<string> actual_sv = Solution().findAndReplacePattern( words, pattern );

	sort( actual_sv.begin(), actual_sv.end() );
	sort( expected_sv.begin(), expected_sv.end() );

	EXPECT_EQ( actual_sv, expected_sv );
}

TEST( FindAndReplacePattern, Test_boo_boo__see ) {
	vector<string> words({"boo","boo","bar"});
	string pattern("see");

	vector<string> expected_sv({"boo","boo"});
	vector<string> actual_sv = Solution().findAndReplacePattern( words, pattern );

	sort( actual_sv.begin(), actual_sv.end() );
	sort( expected_sv.begin(), expected_sv.end() );

	EXPECT_EQ( actual_sv, expected_sv );
}

TEST( FindAndReplacePattern, Test_t_k_g_n_k__v ) {
	vector<string> words({"t","k","g","n","k"});
	string pattern("v");

	vector<string> expected_sv(words);
	vector<string> actual_sv = Solution().findAndReplacePattern( words, pattern );

	sort( actual_sv.begin(), actual_sv.end() );
	sort( expected_sv.begin(), expected_sv.end() );

	EXPECT_EQ( actual_sv, expected_sv );
}

TEST( FindAndReplacePattern, Test_abc__d ) {
	exception_ptr e = nullptr;
	try {
		vector<string> words({"abc"});
		string pattern("d");

		vector<string> expected_sv(words);
		vector<string> actual_sv = Solution().findAndReplacePattern( words, pattern );

		sort( actual_sv.begin(), actual_sv.end() );
		sort( expected_sv.begin(), expected_sv.end() );

		EXPECT_EQ( actual_sv, expected_sv );
	} catch(...) {
		e = current_exception();
	}
	EXPECT_FALSE(e == nullptr);
}

