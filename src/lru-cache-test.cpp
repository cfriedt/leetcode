/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "lru-cache.cpp"

TEST( LruCache, Test_Example ) {
	int expected_int;
	int actual_int;

	LRUCache cache( 2 );

	cache.put( 1, 1 );
	cache.put( 2, 2 );

	expected_int = 1;
	actual_int = cache.get( 1 );
	EXPECT_EQ( actual_int, expected_int );

	cache.put( 3, 3 ); // evict key 2
	expected_int = -1;
	actual_int = cache.get( 2 );
	EXPECT_EQ( actual_int, expected_int );

	cache.put( 4, 4 ); // evict key 1
	expected_int = -1;
	actual_int = cache.get( 1 );
	EXPECT_EQ( actual_int, expected_int );

	expected_int = 3;
	actual_int = cache.get( 3 );
	EXPECT_EQ( actual_int, expected_int );

	expected_int = 4;
	actual_int = cache.get( 4 );
	EXPECT_EQ( actual_int, expected_int );
}
