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

#include <gtest.h>

#include "util/SuffixTreeNode.cpp"

#include "implement-ukkonens-algorithm.cpp"

class ImplementUkkonensAlgorithm : public ::testing::Test {

public:

	string text;
	SuffixTreeNode *output;

	Solution soln;
	string expected_string;
	string actual_string;

	ImplementUkkonensAlgorithm()
	:
		output( nullptr )
	{
	}

protected:

	void mSetUp() {
		output = soln.buildSuffixTree(text);
	}

	void doTest() {
		actual_string = SuffixTreeNode_to_string( output );
		EXPECT_EQ( actual_string, expected_string );
	}

	void TearDown() override {
		SuffixTreeNode_cleanup( & output );
	}
};


TEST_F( ImplementUkkonensAlgorithm, Test_cacao ) {
	text = "cacao";
	expected_string = "{ca{cao{5},o{3}},a{o{2},cao{4}},o{1}}";

	mSetUp();
	doTest();
}
