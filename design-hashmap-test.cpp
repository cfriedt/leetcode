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

#include "design-hashmap.cpp"

TEST( DesignHashset, Test_Example ) {
	MyHashMap hashMap;

	hashMap.put( 1, 1 );
	hashMap.put( 2, 2 );
	EXPECT_EQ( 1, hashMap.get( 1 ) );
	EXPECT_EQ( -1, hashMap.get( 3 ) );
	hashMap.put( 2, 1 );
	EXPECT_EQ( 1, hashMap.get( 2 ) );
	hashMap.remove( 2 );
	hashMap.get( 2 );
	EXPECT_EQ( -1, hashMap.get( 2 ) );
}


TEST( DesignHashset, Test_1000000Random ) {
	MyHashMap hashMap;

	for( size_t i = 0; i < 1000000; i++ ) {
		int key;
		int value;

		bool add = !!random();
		key = random();
		value = random();

		if ( add ) {
			hashMap.put( key, value );
			ASSERT_TRUE( hashMap.contains( key ) );
		} else {
			hashMap.remove( key );
		}
	}
}