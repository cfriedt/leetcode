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

#include <vector>

#include <gtest/gtest.h>

using namespace std;

class MountainArray {
public:
    explicit MountainArray( const vector<int> & A ) : nQueries(0), A(A) {

    }

    int get(int index) {
        if ( nQueries == 100 ) {
            throw runtime_error( "no more guesses left :(" );
        }
        nQueries++;
        return A[index];
    }
    int length() {
        return int( A.size() );
    }

protected:
    size_t nQueries;
    const vector<int> A;
};

#include "find-in-mountain-array.cpp"

TEST( FindInMountainArray, Test_1_2_3_4_5_3_1__3 ) {
    MountainArray mountainArr(vector<int>{{1,2,3,4,5,3,1}});
    int target = 3;
    int expected_int = 2;
    int actual_int = Solution().findInMountainArray(target, mountainArr);
    EXPECT_EQ( actual_int, expected_int );
}

TEST( FindInMountainArray, Test_0_1_2_4_2_1__3 ) {
    MountainArray mountainArr(vector<int>{{0,1,2,4,2,1}});
    int target = 3;
    int expected_int = -1;
    int actual_int = Solution().findInMountainArray(target, mountainArr);
    EXPECT_EQ( actual_int, expected_int );
}

TEST( FindInMountainArray, Test_0_5_3_1__1 ) {
    MountainArray mountainArr(vector<int>{{0,5,3,1}});
    int target = 1;
    int expected_int = 3;
    int actual_int = Solution().findInMountainArray(target, mountainArr);
    EXPECT_EQ( actual_int, expected_int );
}

TEST( FindInMountainArray, Test_0_1_0__1 ) {
    MountainArray mountainArr(vector<int>{{0,1,0}});
    int target = 1;
    int expected_int = 1;
    int actual_int = Solution().findInMountainArray(target, mountainArr);
    EXPECT_EQ( actual_int, expected_int );
}
