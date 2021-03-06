/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <cstring>
#include <strings.h>

#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  // https://leetcode.com/problems/set-matrix-zeroes/

  void setZeroes(vector<vector<int>> &matrix) {

    // This is O( M x N ) in time and O( 1 ) in space

    size_t rows = matrix.size();
    size_t cols = 0 == matrix.size() ? 0 : matrix[0].size();

    if (0 == rows || 0 == cols) {
      return;
    }

    bool row0 = false;
    bool col0 = false;

    for (size_t row = 0; row < rows; row++) {
      for (size_t col = 0; col < cols; col++) {
        if (0 == matrix[row][col]) {
          if (0 == row && 0 == col) {
            row0 = true;
            col0 = true;
            continue;
          }
          if (0 == row) {
            row0 = true;
          } else {
            matrix[row][0] = 0;
          }
          if (0 == col) {
            col0 = true;
          } else {
            matrix[0][col] = 0;
          }
        }
      }
    }

    for (size_t row = 1; row < rows; row++) {
      if (0 == matrix[row][0]) {
        for (size_t col = 0; col < cols; col++) {
          matrix[row][col] = 0;
        }
      }
    }

    for (size_t col = 0; col < cols; col++) {
      if (0 == matrix[0][col]) {
        for (size_t row = 0; row < rows; row++) {
          matrix[row][col] = 0;
        }
      }
    }

    if (row0) {
      for (size_t col = 0; col < cols; col++) {
        matrix[0][col] = 0;
      }
    }

    if (col0) {
      for (size_t row = 0; row < rows; row++) {
        matrix[row][0] = 0;
      }
    }
  }

  /*
          void setZeroes(vector<vector<int>>& matrix) {
                  if ( matrix.size() == 0 || matrix[ 0 ].size() == 0 ) {
                          return;
                  }
                  if ( matrix.size() > 64 || matrix[ 0 ].size() > 64 ) {
                          throw invalid_argument( "matrix dimensions too large"
     );
                  }
                  // use bits to encode which rows / cols are to be zeroed
                  uint64_t zero_rows = 0;
                  uint64_t zero_cols = 0;

                  size_t rows = matrix.size();
                  size_t cols = matrix[ 0 ].size();

                  // O( rows * cols ) :(
                  for( size_t row = 0; row < rows; row++ ) {
                          for( size_t col = 0; col < cols; col++ ) {
                                  if ( 0xffffffff == zero_rows || 0xffffffff ==
     zero_cols ) { break;
                                  }
                                  if ( 0 == matrix[ row ][ col ] ) {
                                          zero_rows |= (uint64_t(1) << row);
                                          zero_cols |= (uint64_t(1) << col);
                                  }
                          }
                  }

                  // if either all rows or all cols are to be zero'd, the entire
                  // matrix should be zero'd. std::fill (hopefully?) uses some
                  // simd intrinsics and can do this very quickly and
     efficiently
                  // so it should be a shortcut.
                  if ( 0xffffffff == zero_rows || 0xffffffff == zero_cols ) {
                          for( size_t row = 0; row < rows; row++ ) {
                                  fill( matrix[ row ].begin(), matrix[ row
     ].end(), 0 );
                          }
                          return;
                  }

                  // iterative approach for sparse zeros
                  for( size_t offs = 0, fsb = ::ffsll( zero_rows ); fsb > 0;
     zero_rows >>= fsb, offs += fsb, fsb = ::ffsll( zero_rows ) ) { size_t row =
     offs + fsb - 1; for( size_t col = 0; col < cols; col++ ) { matrix[ row ][
     col ] = 0;
                          }
                  }

                  for( size_t offs = 0, fsb = ::ffsll( zero_cols ); fsb > 0;
     zero_cols >>= fsb, offs += fsb, fsb = ::ffsll( zero_cols ) ) { size_t col =
     offs + fsb - 1; for( size_t row = 0; row < rows; row++ ) { matrix[ row ][
     col ] = 0;
                          }
                  }
          }
  */
};
