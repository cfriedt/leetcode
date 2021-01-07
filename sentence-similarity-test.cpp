/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
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

TEST( SentenceSimilarity, Test_identical ) {
    vector<string> words1{"great", "acting", "skills"};
    vector<string> words2{"great", "acting", "skills"};
    vector<vector<string>> pairs{{"foo","foo"}};
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

TEST( SentenceSimilarity, Test_great_acting_cowboy_pilot__fine_drama_talent_astronaut__great_fine_acting_drama_skills_talent ) {
    vector<string> words1{"great", "acting", "cowboy"};
    vector<string> words2{"fine", "drama", "talent"};
    vector<vector<string>> pairs {{"great", "fine"}, {"acting","drama"}, {"skills","talent"}, {"cowboy","rancher"}};
    bool expected_bool = false;
    bool actual_bool = Solution().areSentencesSimilar(words1, words2, pairs);
    EXPECT_EQ( actual_bool, expected_bool );
}

TEST( SentenceSimilarity, Test_great_acting_skills_pilot__fine_drama_talent_astronaut__great_fine_acting_drama_skills_talent ) {
    vector<string> words1{"great", "acting", "skills", "pilot"};
    vector<string> words2{"fine", "drama", "talent", "astronaut"};
    vector<vector<string>> pairs {{"great", "fine"}, {"acting","drama"}, {"skills","talent"}, {"cowboy","rancher"}};
    bool expected_bool = false;
    bool actual_bool = Solution().areSentencesSimilar(words1, words2, pairs);
    EXPECT_EQ( actual_bool, expected_bool );
}
