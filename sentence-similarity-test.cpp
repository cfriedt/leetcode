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

#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "sentence-similarity.cpp"

using namespace std;

TEST( SentenceSimilarity, Test_great_acting_skills__fine_drama_talent__great_fine_acting_drama_skills_talent ) {
    vector<string> words1{"great", "acting", "skills"};
    vector<string> words2{"fine", "drama", "talent"};
    vector<vector<string>> pairs {{"great", "fine"}, {"acting","drama"}, {"skills","talent"}};
    bool expected_bool = true;
    bool actual_bool = Solution().areSentencesSimilar(words1, words2, pairs);
    EXPECT_EQ( actual_bool, expected_bool );
}

TEST( SentenceSimilarity, Test_unequalSentenceLength ) {
    vector<string> words1{"great", "acting"};
    vector<string> words2{"fine", "drama", "talent"};
    vector<vector<string>> pairs {{"great", "fine"}, {"acting","drama"}, {"skills","talent"}};
    bool expected_bool = false;
    bool actual_bool = Solution().areSentencesSimilar(words1, words2, pairs);
    EXPECT_EQ( actual_bool, expected_bool );
}

TEST( SentenceSimilarity, Test_symmetry ) {
    vector<string> words1{"great", "acting", "skills"};
    vector<string> words2{"fine", "drama", "talent"};
    vector<vector<string>> pairs {{"fine", "great"}, {"acting","drama"}, {"skills","talent"}};
    bool expected_bool = true;
    bool actual_bool = Solution().areSentencesSimilar(words1, words2, pairs);
    EXPECT_EQ( actual_bool, expected_bool );
}

TEST( SentenceSimilarity, Test_great_acting_cowboy__fine_drama_talent__great_fine_acting_drama_skills_talent ) {
    vector<string> words1{"great", "acting", "cowboy"};
    vector<string> words2{"fine", "drama", "talent"};
    vector<vector<string>> pairs {{"great", "fine"}, {"acting","drama"}, {"skills","talent"}};
    bool expected_bool = false;
    bool actual_bool = Solution().areSentencesSimilar(words1, words2, pairs);
    EXPECT_EQ( actual_bool, expected_bool );
}
