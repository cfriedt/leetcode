/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef UTIL_TRIM_HPP_
#define UTIL_TRIM_HPP_

#include <ctype.h>
#include <string>
static inline void trim(std::string &s) {
  for (; !s.empty() && ::isspace(s[0]);) {
    s = s.substr(1);
  }
  for (; !s.empty() && ::isspace(s[s.length() - 1]);) {
    s.pop_back();
  }
}

#endif /* UTIL_TRIM_HPP_ */
