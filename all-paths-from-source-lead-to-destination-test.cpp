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

#include "all-paths-from-source-lead-to-destination.cpp"

TEST( AllPathsLeadFromSourceToDestination, Test_example1 ) {
    int n = 3;
    vector<vector<int>> edges{{0,1},{0,2}};
    int source = 0;
    int destination = 2;
    bool expected_bool = false;
    bool actual_bool = Solution().leadsToDestination(n, edges, source, destination);
    EXPECT_EQ( actual_bool, expected_bool );
}

TEST( AllPathsLeadFromSourceToDestination, Test_example2 ) {
    int n = 4;
    vector<vector<int>> edges{{0,1},{0,3},{1,2},{2,1}};
    int source = 0;
    int destination = 3;
    bool expected_bool = false;
    bool actual_bool = Solution().leadsToDestination(n, edges, source, destination);
    EXPECT_EQ( actual_bool, expected_bool );
}

TEST( AllPathsLeadFromSourceToDestination, Test_example3 ) {
    int n = 4;
    vector<vector<int>> edges{{0,1},{0,2},{1,3},{2,3}};
    int source = 0;
    int destination = 3;
    bool expected_bool = true;
    bool actual_bool = Solution().leadsToDestination(n, edges, source, destination);
    EXPECT_EQ( actual_bool, expected_bool );
}

TEST( AllPathsLeadFromSourceToDestination, Test_example4 ) {
    int n = 3;
    vector<vector<int>> edges{{0,1},{1,1},{1,2}};
    int source = 0;
    int destination = 2;
    bool expected_bool = false;
    bool actual_bool = Solution().leadsToDestination(n, edges, source, destination);
    EXPECT_EQ( actual_bool, expected_bool );
}

TEST( AllPathsLeadFromSourceToDestination, Test_example5 ) {
    int n = 2;
    vector<vector<int>> edges{{0,1},{1,1}};
    int source = 0;
    int destination = 1;
    bool expected_bool = false;
    bool actual_bool = Solution().leadsToDestination(n, edges, source, destination);
    EXPECT_EQ( actual_bool, expected_bool );
}

TEST( AllPathsLeadFromSourceToDestination, Test_1__0_0___0_0 ) {
    int n = 1;
    vector<vector<int>> edges{{0,0}};
    int source = 0;
    int destination = 0;
    bool expected_bool = false;
    bool actual_bool = Solution().leadsToDestination(n, edges, source, destination);
    EXPECT_EQ( actual_bool, expected_bool );
}

TEST( AllPathsLeadFromSourceToDestination, Test_1__empty_0_0 ) {
    int n = 1;
    vector<vector<int>> edges;
    int source = 0;
    int destination = 0;
    bool expected_bool = true;
    bool actual_bool = Solution().leadsToDestination(n, edges, source, destination);
    EXPECT_EQ( actual_bool, expected_bool );
}
