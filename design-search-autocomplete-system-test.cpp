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
