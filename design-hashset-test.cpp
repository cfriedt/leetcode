/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "design-hashset.cpp"

/*
static void graphHistogram( const vector<size_t> & histogram ) {

	enum { MIN, MAX };

	size_t lim[2]{ SIZE_MAX, 0 };

	for( auto & h: histogram ) {
		if ( h < lim[ MIN ] ) {
			lim[ MIN ] = h;
		}
		if ( h > lim[ MAX ] ) {
			lim[ MAX ] = h;
		}
	}

	size_t M = lim[ MAX ]; // number of rows
	size_t N = histogram.size(); // number of columns

	vector<vector<bool>> bmp( M, vector<bool>( N, false ) );
	for( size_t col = 0; col < N; col++ ) {
		for( size_t row = 0; row < histogram[ col ]; row++ ) {
			bmp[ lim[ MAX ] - row - 1 ][ col ] = true;
		}
	}

	for( size_t row = 0; row < M; row++ ) {
		for( size_t col = 0; col < N; col++ ) {
			if ( bmp[ row ][ col ] ) {
				cerr << 'x';
			} else {
				cerr << ' ';
			}
		}
		cerr << endl;
	}
	for( size_t col = 0; col < N; col++ ) cerr << '=';
	cerr << endl;
}
*/

size_t histogramNumSamples( const vector<size_t> & histogram ) {
	size_t n_samples = 0;
	for( auto & h: histogram ) {
		n_samples += h;
	}
	return n_samples;
}

TEST( DesignHashset, Test_Example ) {
	MyHashSet hashSet;

	hashSet.add(1);
	hashSet.add(2);
	EXPECT_TRUE( hashSet.contains(1) );
	EXPECT_FALSE( hashSet.contains(3) );
	hashSet.add(2);
	EXPECT_TRUE( hashSet.contains(2) );
	hashSet.remove(2);
	EXPECT_FALSE( hashSet.contains(2) );
}


TEST( DesignHashset, Test_remove_nonexistent ) {
	MyHashSet hashSet;
	vector<size_t> histogram;

	hashSet.add( 1 );
	EXPECT_TRUE( hashSet.contains( 1 ) );
	EXPECT_FALSE( hashSet.contains( 2 ) );
	hashSet.remove( 2 );
	EXPECT_FALSE( hashSet.contains( 2 ) );
	hashSet.remove( 1 );
	EXPECT_FALSE( hashSet.contains( 1 ) );
}

TEST( DesignHashset, Test_80Random ) {
	MyHashSet hashSet;
	vector<size_t> histogram;

	for( size_t i = 0; i < 80; i++ ) {
		int x;

		for( x = random(); hashSet.contains( x ); x = random() );

		ASSERT_FALSE( hashSet.contains( x ) );

		hashSet.add( x );

		ASSERT_TRUE( hashSet.contains( x ) );

		histogram = hashSet.histogram();

		ASSERT_EQ( histogramNumSamples( histogram ), i + 1 );

		// graphHistogram( histogram );
	}
}

TEST( DesignHashset, Test_1000Random ) {
	MyHashSet hashSet;
	vector<size_t> histogram;

	for( size_t i = 0; i < 1000; i++ ) {
		int x;

		for( x = random(); hashSet.contains( x ); x = random() );

		ASSERT_FALSE( hashSet.contains( x ) );

		hashSet.add( x );

		ASSERT_TRUE( hashSet.contains( x ) );

		histogram = hashSet.histogram();

		ASSERT_EQ( histogramNumSamples( histogram ), i + 1 );

		// graphHistogram( histogram );
	}
}

TEST( DesignHashset, Test_1000000Random ) {
	MyHashSet hashSet;

	for( size_t i = 0; i < 1000000; i++ ) {
		int x;

		bool add = !!random();
		x = random();

		if ( add ) {
			hashSet.add( x );
			ASSERT_TRUE( hashSet.contains( x ) );
		} else {
			hashSet.remove( x );
		}
	}
}
