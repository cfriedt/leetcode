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

#include "number-of-islands.cpp"

static void fixup( vector<vector<char>> & grid ) {
    for( auto & row: grid ) {
        for( auto & col: row ) {
            if ( '1' != col ) {
                col = '0';
            }
        }
    }
}

TEST( NumberOfIslands, Test_example1 ) {
    vector<vector<char>> grid {
        { '1', '1', '1', '1', ' ' },
        { '1', '1', ' ', '1', ' ' },
        { '1', '1', ' ', ' ', ' ' },
        { ' ', ' ', ' ', ' ', ' ' },
    };
    fixup( grid );
	int expected_int = 1;
    int actual_int = Solution().numIslands(grid);
    EXPECT_EQ( actual_int, expected_int );
}

TEST( NumberOfIslands, Test_example2 ) {
    vector<vector<char>> grid {
        { '1', '1', ' ', ' ', ' ' },
        { '1', '1', ' ', ' ', ' ' },
        { ' ', ' ', '1', ' ', ' ' },
        { ' ', ' ', ' ', '1', '1' },
    };
    fixup( grid );
	int expected_int = 3;
    int actual_int = Solution().numIslands(grid);
    EXPECT_EQ( actual_int, expected_int );
}

TEST( NumberOfIslands, Test_donut ) {
    vector<vector<char>> grid {
        { ' ', '1', '1', '1', ' ' },
        { ' ', '1', ' ', '1', ' ' },
        { ' ', '1', '1', '1', ' ' },
    };
    fixup( grid );
	int expected_int = 1;
    int actual_int = Solution().numIslands(grid);
    EXPECT_EQ( actual_int, expected_int );
}

TEST( NumberOfIslands, Test_c ) {
    vector<vector<char>> grid {
        { ' ', '1', '1', '1', ' ' },
        { ' ', '1', ' ', ' ', ' ' },
        { ' ', '1', '1', '1', ' ' },
    };
    fixup( grid );
	int expected_int = 1;
    int actual_int = Solution().numIslands(grid);
    EXPECT_EQ( actual_int, expected_int );
}

TEST( NumberOfIslands, Test_mirror_c ) {
    vector<vector<char>> grid {
        { ' ', '1', '1', '1', ' ' },
        { ' ', ' ', ' ', '1', ' ' },
        { ' ', '1', '1', '1', ' ' },
    };
    fixup( grid );
	int expected_int = 1;
    int actual_int = Solution().numIslands(grid);
    EXPECT_EQ( actual_int, expected_int );
}

TEST( NumberOfIslands, Test_u_umlaut ) {
    vector<vector<char>> grid {
        { ' ', '1', ' ', '1', ' ' },
        { ' ', ' ', ' ', ' ', ' ' },
        { ' ', '1', ' ', '1', ' ' },
        { ' ', '1', ' ', '1', ' ' },
        { ' ', '1', '1', '1', ' ' },
    };
    fixup( grid );
	int expected_int = 3;
    int actual_int = Solution().numIslands(grid);
    EXPECT_EQ( actual_int, expected_int );
}

TEST( NumberOfIslands, Test_x ) {
    vector<vector<char>> grid {
        { '1', ' ', ' ', ' ', '1' },
        { ' ', '1', ' ', '1', ' ' },
        { ' ', ' ', '1', ' ', ' ' },
        { ' ', '1', ' ', '1', ' ' },
        { '1', ' ', ' ', ' ', '1' },
    };
    fixup( grid );
	int expected_int = 9;
    int actual_int = Solution().numIslands(grid);
    EXPECT_EQ( actual_int, expected_int );
}

TEST( NumberOfIslands, Test_snek ) {
    vector<vector<char>> grid {
        { ' ', '1', '1', '1', '1' },
        { ' ', ' ', ' ', ' ', '1' },
        { '1', '1', '1', ' ', '1' },
        { '1', ' ', ' ', ' ', '1' },
        { '1', '1', '1', '1', '1' },
    };
    fixup( grid );
	int expected_int = 1;
    int actual_int = Solution().numIslands(grid);
    EXPECT_EQ( actual_int, expected_int );
}


TEST( NumberOfIslands, Test_great_big_sea ) {
    vector<vector<char>> grid {
        { ' ', ' ', ' ', ' ', ' ' },
        { ' ', ' ', ' ', ' ', ' ' },
        { ' ', ' ', ' ', ' ', ' ' },
        { ' ', ' ', ' ', ' ', ' ' },
        { ' ', ' ', ' ', ' ', ' ' },
    };
    fixup( grid );
	int expected_int = 0;
    int actual_int = Solution().numIslands(grid);
    EXPECT_EQ( actual_int, expected_int );
}

TEST( NumberOfIslands, Test_empty ) {
    vector<vector<char>> grid;
    fixup( grid );
	int expected_int = 0;
    int actual_int = Solution().numIslands(grid);
    EXPECT_EQ( actual_int, expected_int );
}

TEST( NumberOfIslands, Test_vzigzag ) {
    vector<vector<char>> grid {
        { '1', '1', '1', '1', '1' },
        { ' ', ' ', ' ', ' ', '1' },
        { '1', '1', '1', '1', '1' },
        { '1', ' ', ' ', ' ', ' ' },
        { '1', '1', '1', '1', '1' },
    };
    fixup( grid );
	int expected_int = 1;
    int actual_int = Solution().numIslands(grid);
    EXPECT_EQ( actual_int, expected_int );
}

TEST( NumberOfIslands, Test_hzigzag ) {
    vector<vector<char>> grid {
        { '1', ' ', '1', '1', '1' },
        { '1', ' ', '1', ' ', '1' },
        { '1', ' ', '1', ' ', '1' },
        { '1', ' ', '1', ' ', '1' },
        { '1', '1', '1', ' ', '1' },
    };
    fixup( grid );
	int expected_int = 1;
    int actual_int = Solution().numIslands(grid);
    EXPECT_EQ( actual_int, expected_int );
}

// currently not considering "lakes"
TEST( NumberOfIslands, Test_fillIslandTest ) {
    vector<vector<char>> grid {
        { '1', '1', '1', '1', ' ', ' ' },
        { ' ', '1', ' ', '1', ' ', ' ' },
        { '1', '1', '1', '1', '1', '1' },
        { '1', ' ', ' ', '1', ' ', '1' },
        { '1', ' ', ' ', '1', '1', '1' },
        { '1', '1', '1', '1', ' ', '1' },
    };
    fixup( grid );
	int expected_int = 1;
    int actual_int = Solution().numIslands(grid);
    EXPECT_EQ( actual_int, expected_int );
}

// what about an island within an island???

TEST( NumberOfIslands, Test_recursion ) {
    vector<vector<char>> grid {
        { '1', '1', '1', '1', '1', '1' },
        { '1', ' ', ' ', ' ', ' ', '1' },
        { '1', ' ', '1', '1', ' ', '1' },
        { '1', ' ', ' ', ' ', ' ', '1' },
        { '1', '1', '1', ' ', '1', '1' },
    };
    fixup( grid );
	int expected_int = 2;
    int actual_int = Solution().numIslands(grid);
    EXPECT_EQ( actual_int, expected_int );
}

TEST( NumberOfIslands, Test_islandWithinIsland ) {
    vector<vector<char>> grid {
        { '1', '1', '1', '1', '1' },
        { '1', ' ', ' ', ' ', '1' },
        { '1', ' ', '1', ' ', '1' },
        { '1', ' ', ' ', ' ', '1' },
        { '1', '1', '1', '1', '1' },
    };
    fixup( grid );
	int expected_int = 2;
    int actual_int = Solution().numIslands(grid);
    EXPECT_EQ( actual_int, expected_int );
}

TEST( NumberOfIslands, Test_islandWithinIslandWithDiag ) {
    vector<vector<char>> grid {
        { '1', '1', '1', '1', '1' },
        { '1', ' ', ' ', ' ', '1' },
        { '1', ' ', '1', ' ', '1' },
        { '1', ' ', ' ', '1', '1' },
        { '1', '1', '1', '1', '1' },
    };
    fixup( grid );
	int expected_int = 2;
    int actual_int = Solution().numIslands(grid);
    EXPECT_EQ( actual_int, expected_int );
}

TEST( NumberOfIslands, Test_perimeterShouldOnlyInclude2AroundCorners ) {
    vector<vector<char>> grid {
        { '1', ' ', ' ', ' ' },
        { '1', '1', '1', ' ' },
        { '1', ' ', '1', ' ' },
        { '1', ' ', '1', '1' },
        { '1', ' ', '1', ' ' },
        { ' ', '1', '1', ' ' },
        { '1', '1', ' ', ' ' },
    };
    fixup( grid );
    int expected_int = 1;
    int actual_int = Solution().numIslands(grid);
    EXPECT_EQ( actual_int, expected_int );
}

TEST( NumberOfIslands, Test_big ) {
    vector<vector<char>> grid {
        { '1', ' ', ' ', '1', '1', '1', ' ', '1', '1', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
        { '1', ' ', ' ', '1', '1', ' ', ' ', '1', ' ', ' ', ' ', '1', ' ', '1', ' ', '1', ' ', ' ', '1', ' ' },
        { ' ', ' ', ' ', '1', '1', '1', '1', ' ', '1', ' ', '1', '1', ' ', ' ', ' ', ' ', '1', ' ', '1', ' ' },
        { ' ', ' ', ' ', '1', '1', ' ', ' ', '1', ' ', ' ', ' ', '1', '1', '1', ' ', ' ', '1', ' ', ' ', '1' },
        { ' ', ' ', ' ', ' ', ' ', ' ', ' ', '1', '1', '1', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
        { '1', ' ', ' ', ' ', ' ', '1', ' ', '1', ' ', '1', '1', ' ', ' ', ' ', ' ', ' ', ' ', '1', ' ', '1' },
        { ' ', ' ', ' ', '1', ' ', ' ', ' ', '1', ' ', '1', ' ', '1', ' ', '1', ' ', '1', ' ', '1', ' ', '1' },
        { ' ', ' ', ' ', '1', ' ', '1', ' ', ' ', '1', '1', ' ', '1', ' ', '1', '1', ' ', '1', '1', '1', ' ' },
        { ' ', ' ', ' ', ' ', '1', ' ', ' ', '1', '1', ' ', ' ', ' ', ' ', '1', ' ', ' ', ' ', '1', ' ', '1' },
        { ' ', ' ', '1', ' ', ' ', '1', ' ', ' ', ' ', ' ', ' ', '1', ' ', ' ', '1', ' ', ' ', ' ', '1', ' ' },
        { '1', ' ', ' ', '1', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '1', ' ', ' ', '1', ' ', '1', ' ', '1', ' ' },
        { ' ', '1', ' ', ' ', ' ', '1', ' ', '1', ' ', '1', '1', ' ', '1', '1', '1', ' ', '1', '1', ' ', ' ' },
        { '1', '1', ' ', '1', ' ', ' ', ' ', ' ', '1', ' ', ' ', ' ', ' ', ' ', ' ', '1', ' ', ' ', ' ', '1' },
        { ' ', '1', ' ', ' ', '1', '1', '1', ' ', ' ', ' ', '1', '1', '1', '1', '1', ' ', '1', ' ', ' ', ' ' },
        { ' ', ' ', '1', '1', '1', ' ', ' ', ' ', '1', '1', ' ', ' ', ' ', '1', ' ', '1', ' ', ' ', ' ', ' ' },
        { '1', ' ', ' ', '1', ' ', '1', ' ', ' ', ' ', ' ', '1', ' ', ' ', ' ', '1', ' ', '1', ' ', '1', '1' },
        { '1', ' ', '1', ' ', ' ', ' ', ' ', ' ', ' ', '1', ' ', ' ', ' ', '1', ' ', '1', ' ', ' ', ' ', ' ' },
        { ' ', '1', '1', ' ', ' ', ' ', '1', '1', '1', ' ', '1', ' ', '1', ' ', '1', '1', '1', '1', ' ', ' ' },
        { ' ', '1', ' ', ' ', ' ', ' ', '1', '1', ' ', ' ', '1', ' ', '1', ' ', ' ', '1', ' ', ' ', '1', '1' },
        { ' ', ' ', ' ', ' ', ' ', ' ', '1', '1', '1', '1', ' ', '1', ' ', ' ', ' ', '1', '1', ' ', ' ', ' ' },
    };
    fixup( grid );
	int expected_int = 58;
    int actual_int = Solution().numIslands(grid);
    EXPECT_EQ( actual_int, expected_int );
}
