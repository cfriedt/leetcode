/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "design-search-autocomplete-system.cpp"

using namespace std;

TEST( DesignSearchAutocompleteSystem, Test_i_love_you__island__ironman__i_love_leetcode__5_3_2_2_i___a_pound ) {

    vector<string> sentences{"i love you","island","ironman","i love leetcode"};
    vector<int> times{5,3,2,2};

    AutocompleteSystem obj( sentences, times );

    char c;
    vector<string> expected_vs;
    vector<string> actual_vs;

    c = 'i';
    expected_vs = vector<string>{"i love you","island","i love leetcode"};
    actual_vs = obj.input(c);
    EXPECT_EQ( actual_vs, expected_vs );

    c = ' ';
    expected_vs = vector<string>{"i love you","i love leetcode"};
    actual_vs = obj.input(c);
    EXPECT_EQ( actual_vs, expected_vs );

    c = 'a';
    expected_vs = vector<string>();
    actual_vs = obj.input(c);
    EXPECT_EQ( actual_vs, expected_vs );

    c = '#';
    expected_vs = vector<string>();
    actual_vs = obj.input(c);
    EXPECT_EQ( actual_vs, expected_vs );
}

TEST( DesignSearchAutocompleteSystem, Test_fooa__foob__fooc__food__2_2_2_2_f ) {

    vector<string> sentences{"fooa", "foob", "fooc", "food"};
    vector<int> times{2,2,2,2};

    AutocompleteSystem obj( sentences, times );

    char c;
    vector<string> expected_vs;
    vector<string> actual_vs;

    c = 'f';
    expected_vs = vector<string>{"fooa","foob","fooc"};
    actual_vs = obj.input(c);
    EXPECT_EQ( actual_vs, expected_vs );
}
