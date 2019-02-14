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

#include <gtest.h>

#include "unique-word-abbreviation.cpp"

TEST( UniqueWordAbbreviation, Test_deer_door_cake_card__dear__cart__cane__make ) {
	vector<string> dictionary({"deer","door","cake","card"});

	ValidWordAbbr vwa( dictionary );

	EXPECT_FALSE( vwa.isUnique( "dear" ) );
	EXPECT_TRUE( vwa.isUnique( "cart" ) );
	EXPECT_FALSE( vwa.isUnique( "cane" ) );
	EXPECT_TRUE( vwa.isUnique( "make" ) );
}

TEST( UniqueWordAbbreviation, Test_hello__hello ) {
	vector<string> dictionary({"hello"});

	ValidWordAbbr vwa( dictionary );

	EXPECT_TRUE( vwa.isUnique( "hello" ) );
}

TEST( UniqueWordAbbreviation, Test_deer_door_cake_card__dear__door__cart__cake ) {
	vector<string> dictionary({"deer","door","cake","card"});

	ValidWordAbbr vwa( dictionary );

	EXPECT_FALSE( vwa.isUnique( "dear" ) );
	EXPECT_FALSE( vwa.isUnique( "door" ) );
	EXPECT_TRUE( vwa.isUnique( "cart" ) );
	EXPECT_TRUE( vwa.isUnique( "cake" ) );
}

