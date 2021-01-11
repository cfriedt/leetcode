/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "design-hashmap.cpp"

TEST(DesignHashset, Test_Example) {
  MyHashMap hashMap;

  hashMap.put(1, 1);
  hashMap.put(2, 2);
  EXPECT_EQ(1, hashMap.get(1));
  EXPECT_EQ(-1, hashMap.get(3));
  hashMap.put(2, 1);
  EXPECT_EQ(1, hashMap.get(2));
  hashMap.remove(2);
  hashMap.get(2);
  EXPECT_EQ(-1, hashMap.get(2));
}

TEST(DesignHashset, Test_1000000Random) {
  MyHashMap hashMap;

  for (size_t i = 0; i < 1000000; i++) {
    int key;
    int value;

    bool add = !!random();
    key = random();
    value = random();

    if (add) {
      hashMap.put(key, value);
      ASSERT_TRUE(hashMap.contains(key));
    } else {
      hashMap.remove(key);
    }
  }
}
