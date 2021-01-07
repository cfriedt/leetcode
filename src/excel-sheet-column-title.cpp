/*
 * Copyright (c) 2020 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
  string convertToTitle(int n) {
    string column_title = "";
    uint8_t rem;
    char c;

    do {
      --n;
      rem = n % 26;
      c = 'A' + rem;
      column_title.push_back(c);
      n /= 26;
    } while (n != 0);

    reverse(column_title.begin(), column_title.end());

    return column_title;
  }
};
