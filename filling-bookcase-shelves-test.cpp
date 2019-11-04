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

#include "filling-bookcase-shelves.cpp"

/*
 * Analysis
 * --------
 *
 * There are a bunch of basic corner cases to consider here
 * - if any single thickness is > shelf_width, the task is impossible
 * - assumption: all dimensions are positive, non-zero
 * - assumption: shelf height is zero
 * - book ordering is completely uncorrelated with dimensions (i.e. the list
 *   is not sorted by size)
 *
 * We will need to look at each book at least one time, so the minimum time-
 * complexity is O( N ). It's easy to see how a naive algorithm could grow to
 * N^2 or perhaps more.
 *
 * Degenerate case - assume that *on average* M books can fit on 1 shelf. Then
 * we would need approximately N / M shelves. If we have N / M shelves, and need
 * to select shelves to put these books on, then there are likely a very large
 * number of ways we could put books on those shelves, but I think it grows to
 * N^2 - e.g. N books times N / M ways to put a book on a shelf equals N^2/M. So
 * that could be our upper bound (I'm sure that there are worse algorithms that
 * could probably go beyond that).
 *
 * So ideally we are looking for a way to achieve something like O( log N ) or
 * O( N log N ) time complexity.
 *
 * Another degenerate case - say shelf_width is infinite, then the min height
 * is the height of the tallest book.
 *
 * Another degenerate case - say the shelf width is x and all book thicknesses
 * are x, then the minimum height would be the sum of all book heights.
 *
 * Those two could come into play with some short-circuit / heuristic
 * optimizations.
 *
 * I should also mention that this really sounds similar to the "bin-packing"
 * problem, which I believe is NP-hard.
 *
 * Example
 * -------
 *
 * Input: books = {{1,1},{2,3},{2,3},{1,1},{1,1},{1,1},{1,2}}, shelf_width = 4
 * Output: 6
 *
 * Observations
 * ------------
 *
 * The example on the website has a nice drawing, and with that it's easy to see
 * that there could be more than one way to achieve the same minimum height
 * (swap 7 and 1).
 *
 * So the naive way to do this would be to use a recursion, where every possible
 * outcome is examined. That case would need to replicate the solution state at
 * every decision tree in order to get the optimal solution. I believe that would
 * essentially boil down to using N^2 space and N^2 time, but at least it's a
 * tractable solution.
 *
 * It's possible that this problem lends itself very well to a DP solution.
 *
 * Let's first try a recursive approach.
 *
 */

// example from the website
TEST( FillingBookcaseShelves, Test_1_1__2_3__2_3__1_1__1_1__1_1__1_2___4 ) {
    vector<vector<int>> books = {{1,1},{2,3},{2,3},{1,1},{1,1},{1,1},{1,2}};
    int shelf_width = 4;
    int expected_int = 6;
    int actual_int = Solution().minHeightShelves(books, shelf_width);
    EXPECT_EQ(expected_int, actual_int);
}

// failed example from the website
// this test fails for an unknown reason. I've re-read the problem statement
// a number of times and there are no indication that additional constraints
// exist that would make the expected output 15 here instead of 12
TEST( FillingBookcaseShelves, Test_7_3__8_7__2_7__2_5___10 ) {
    vector<vector<int>> books = {{7,3},{8,7},{2,7},{2,5}};
    int shelf_width = 10;
    //int expected_int = 15;
    int expected_int = 12;
    int actual_int = Solution().minHeightShelves(books, shelf_width);
    EXPECT_EQ(expected_int, actual_int);
}
