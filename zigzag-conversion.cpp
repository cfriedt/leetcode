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

using namespace std;

class Solution {
public:

	// https://leetcode.com/problems/zigzag-conversion/

	string convert(string s, int numRows) {
		// Example:
		// ("PAYPALISHIRING",3) => "PAHNAPLSIIGYIR"
		// P   A   H   N
		// A P L S I I G
		// Y   I   R

		// Assumptions:
		// - rows is > 0

		if ( numRows <= 0 || s.empty() ) {
			return "";
		}

		// Observations:
		// - in the example, the string is 14 characters long
		// - there are 7 columns
		// - seems like the number of columns is s.length() / ( rows - 1 )
		// - what if numRows == 1 ? Then you just have the original string :-)

		if ( 1 == numRows || s.length() <= (size_t)numRows ) {
			return s;
		}

		// A really straightforward approach to this problem would be to allocate a matrix and then
		// just keep track of the direction, row, col, etc, and use the modulus operator to alternate.
		//
		// Then perform another sweep of the matrix and collect the matrix into the output string.
		//
		// The sacrifice in that approach would be space complexity because you need to allocate
		// numRows * numCols bytes.
		//
		// A non-printable character (e.g. '\0') would be used to indicate an empty cell in the matrix.
		//
		// I think it would be done in linear time though, which should be good enough.

		// E.g.
		//
		//    0           6
		// 0 [P   A   H   N]
		//   [A P L S I I G]
		// 2 [Y   I   R    ]
		//
		// i   s[i]   row     col    dir   comment
		// 0   P      0       0      +1    start in the downward direction, row += dir
		// 1   A      1       0      +1    continue
		// 2   Y      2       0      -1    after writing character, switch directions because row == numRows - 1
		//                                 - row += dir, => 1
		//                                 - increment column because dir == -1 and row > 0
		// 3   P      1       1      -1
		// ..
		vector<string> rows( min( (size_t)numRows, s.size() ), "" );

		size_t i, row;
		bool down;
		for(
			i = 0,
				row = 0,
				down = true
				;
			i < s.length()
				;
			i++
		) {

			rows[ row ] += s[ i ];

			if ( down && row == (size_t)numRows - 1 ) {
				down = false;
			} else if ( !down && 0 == row ) {
				down = true;
			}
			row += down ? +1 : -1;
		}

		string zigzag;
		for( auto & r: rows ) {
			zigzag += r;
		}

		return zigzag;
	}
};
