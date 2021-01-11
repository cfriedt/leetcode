/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <string>

using namespace std;

class Solution {
public:
  bool validWordAbbreviation(string word, string abbr) {

    // O(N) time, O(1) space

    // i is the index in word, and j in abbr
    size_t i, j;
    for (i = 0, j = 0; i < word.size() && j < abbr.size();) {

      // say we have word "apple" and abbr "apple"
      // we iterate over each letter.
      if (::isalpha(abbr[j])) {

        if (word[i] != abbr[j]) {
          //					cerr << "word[" << i << "] (" << (word[i])
          //<<
          //"
          //!= abbr[" << j << "] (" << abbr[j] << ")" << endl;
          return false;
        }

        i++;
        j++;

        continue;
      }

      if ('0' == abbr[j]) {
        //				cerr << "abbr[" << j << "] is a number
        // that begins with zero" << endl;
        return false;
      }

      size_t number_length; // number length
      for (number_length = 1; number_length + j < abbr.size();
           number_length++) {
        if (!('0' <= abbr[number_length + j] &&
              abbr[number_length + j] <= '9')) {
          break;
        }
      }

      string number_str = abbr.substr(j, number_length);

      //			cerr << "number_str is " << number_str << endl;

      uint32_t number;
      sscanf(number_str.c_str(), "%u", &number);

      // say we have i == 1, number == 5, and word == "internationalization"
      // 1 + 5 == 6 is less than the word size, which is 20, so we're good
      // but if number was 30, then we would report an error

      if (i + number > word.size()) {
        //				cerr << "i + number (" << (i + number)
        //<<
        //") is >= word.size() (" << word.size() << ")" << endl;
        return false;
      }

      i += number;
      j += number_length;
    }

    // We break out of the loop as soon as we have reached the end of a string,
    // but if the other string has extra characters that do not correspond to
    // the other, then there is a bad return case.
    if (!(i == word.size() && j == abbr.size())) {
      //			cerr << "i (" << i << ") != word.size() (" <<
      // word.size() << ") OR "
      //				<< "j (" << j << ") != abbr.size() (" <<
      // abbr.size() << ")"
      //				<< endl;
      return false;
    }
    return true;
  }
};
