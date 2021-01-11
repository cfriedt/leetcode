/*
 * Copyright (c) 2020 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    static const uint8_t lut[] = {
        0b0000, 0b1000, 0b0100, 0b1100, 0b0010, 0b1010, 0b0110, 0b1110,
        0b0001, 0b1001, 0b0101, 0b1101, 0b0011, 0b1011, 0b0111, 0b1111,
    };
    uint32_t r = 0;

    for (uint8_t i = 0, shift = 28; i < 8; ++i, n >>= 4, shift -= 4) {
      r |= lut[n & 0xf] << shift;
    }

    return r;
  }
};
