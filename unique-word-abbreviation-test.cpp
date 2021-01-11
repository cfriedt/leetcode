/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "unique-word-abbreviation.cpp"

TEST(UniqueWordAbbreviation, Test_deer_door_cake_card__dear__cart__cane__make) {
  vector<string> dictionary({"deer", "door", "cake", "card"});

  ValidWordAbbr vwa(dictionary);

  EXPECT_FALSE(vwa.isUnique("dear"));
  EXPECT_TRUE(vwa.isUnique("cart"));
  EXPECT_FALSE(vwa.isUnique("cane"));
  EXPECT_TRUE(vwa.isUnique("make"));
}

TEST(UniqueWordAbbreviation, Test_hello__hello) {
  vector<string> dictionary({"hello"});

  ValidWordAbbr vwa(dictionary);

  EXPECT_TRUE(vwa.isUnique("hello"));
}

TEST(UniqueWordAbbreviation, Test_deer_door_cake_card__dear__door__cart__cake) {
  vector<string> dictionary({"deer", "door", "cake", "card"});

  ValidWordAbbr vwa(dictionary);

  EXPECT_FALSE(vwa.isUnique("dear"));
  EXPECT_FALSE(vwa.isUnique("door"));
  EXPECT_TRUE(vwa.isUnique("cart"));
  EXPECT_TRUE(vwa.isUnique("cake"));
}
