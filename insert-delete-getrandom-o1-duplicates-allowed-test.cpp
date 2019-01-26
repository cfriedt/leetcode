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

#include "insert-delete-getrandom-o1-duplicates-allowed.cpp"

#include <array>
#include <string>
#include <map>

string to_string( const map<int,size_t> & x ) {
	stringstream ss;
	ss << "{ ";
	for( auto & kv: x ) {
		auto & k = kv.first;
		auto & v = kv.second;
		ss << "{ " + to_string( k ) + ", " + to_string( v ) + " }, ";
	}
	ss << "}";
	return ss.str();
}


#if 1
TEST( InsertDeleteGetRandomO1DuplicatesAllowed, Test_A ) {

	RandomizedCollection s;
	EXPECT_EQ( s.insert( 1 ), true );
	EXPECT_EQ( s.insert( 10 ), true );
	EXPECT_EQ( s.insert( 10 ), false );
	EXPECT_EQ( s.insert( 100 ), true );

	EXPECT_EQ( s.getNumUniqueItems(), size_t( 3 ) );

	map<int,size_t> hist;

	array<int,10000> samples;
	for( size_t i = 0; i < samples.size() / 2; i++ ) {
		int & sam = samples[ i ];
		sam = s.getRandom();
		EXPECT_TRUE( 1 == sam || 10 == sam || 100 == sam );
		hist[ sam ]++;
	}

	EXPECT_EQ( s.remove( 10 ), true );

	for( size_t i = samples.size() / 2; i < samples.size(); i++ ) {
		int & sam = samples[ i ];
		sam = s.getRandom();
		EXPECT_TRUE( 1 == sam || 10 == sam || 100 == sam );
		hist[ sam ]++;
	}

	cerr << to_string( hist ) << std::endl;
}
#endif

TEST( InsertDeleteGetRandomO1DuplicatesAllowed, Test_B ) {

	RandomizedCollection s;
	EXPECT_EQ( s.insert( 1 ), true );
	EXPECT_EQ( s.insert( 2 ), true );
	EXPECT_EQ( s.insert( 3 ), true );
	EXPECT_EQ( s.insert( 4 ), true );
	EXPECT_EQ( s.insert( 5 ), true );
	EXPECT_EQ( s.insert( 6 ), true );
	EXPECT_EQ( s.insert( 7 ), true );
	EXPECT_EQ( s.insert( 8 ), true );
	EXPECT_EQ( s.insert( 9 ), true );

	EXPECT_EQ( s.getNumUniqueItems(), size_t( 9 ) );

	map<int,size_t> hist;

	array<int,10000> samples;
	for( auto & sam: samples ) {
		sam = s.getRandom();
		EXPECT_TRUE( 1 <= sam && sam <= 9 );
		hist[ sam ]++;
	}

	cerr << to_string( hist ) << std::endl;
}

TEST( InsertDeleteGetRandomO1DuplicatesAllowed, Test_C ) {

	RandomizedCollection s;
	EXPECT_EQ( s.insert( 1 ), true );
	EXPECT_EQ( s.insert( 10 ), true );
	EXPECT_EQ( s.insert( 10 ), false );
	EXPECT_EQ( s.insert( 100 ), true );

	EXPECT_EQ( s.getNumUniqueItems(), size_t( 3 ) );

	EXPECT_EQ( s.remove( 10 ), true );

	EXPECT_EQ( s.getNumUniqueItems(), size_t( 3 ) );
}

TEST( InsertDeleteGetRandomO1DuplicatesAllowed, Test_D ) {

	//["RandomizedCollection","insert","insert","remove","getRandom"]
	//[[],[1],[1],[1],[]]

	RandomizedCollection s;
	EXPECT_EQ( s.insert( 1 ), true );
	EXPECT_EQ( s.insert( 1 ), false );
	EXPECT_EQ( s.remove( 1 ), true );
	EXPECT_EQ( s.getRandom(), 1 );
}
