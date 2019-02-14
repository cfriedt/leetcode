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
