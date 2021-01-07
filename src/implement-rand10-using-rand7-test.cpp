/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "implement-rand10-using-rand7.cpp"

#include <array>
#include <functional>
#include <numeric>
#include <map>
#include <random>
#include <sstream>
#include <string>

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

int rand7() {

	// Very c++11-ish way of generating random values.
	// In a pinch, I would probably just use random().

	static random_device rd;
	static mt19937 gen(rd());
	static uniform_int_distribution<> dis(1,7);

	return dis( gen );
}

template <size_t N>
static float mean( array<int,N> & samples ) {
	float u = accumulate( samples.begin(), samples.end(), 0 );
	u /= samples.size();
	return u;
}

template <size_t N>
static float variance( array<int,N> & samples ) {
	float var = 0;
	for( auto & s: samples ) {
		var += ::powf( s, 2 );
	}
	var /= samples.size();
	var -= ::powf( mean( samples ), 2 );
	return var;
}

template <size_t N>
static void sample( array<int,N> & samples, function<float()> & func ) {
	for( auto & s: samples ) {
		s = func();
	}
}

#define MEAN_OK 0.1 // this is pretty high actually, for 1M samples!!!
#define VAR_OK 0.5  // this is pretty high actually, for 1M samples!!!

TEST( ImplementRand10UsingRand7, Test_rand7 ) {

	size_t n = 7;
	array<int,1000000> samples;
	function<float()> func( rand7 );

	sample( samples, func );

	float u = mean( samples );
	float var = variance( samples );

	EXPECT_NEAR( u, float(1 + n)/2, MEAN_OK );
	EXPECT_NEAR( var, (::powf(n - 1 + 1, 2) - 1)/12, VAR_OK );

#if 0
	// output clearly shows that this is uniformly distributed
	map<int,size_t> hist;
	for( auto & s: samples ) {
		hist[ s ]++;
	}

	cerr << to_string( hist ) << std::endl;
#endif
}

TEST( ImplementRand10UsingRand7, Test_rand10 ) {

	size_t n = 10;
	array<int,1000000> samples;
	function<float()> func( bind( & Solution::rand10, Solution() ) );

	sample( samples, func );

	float u = mean( samples );
	float var = variance( samples );

	EXPECT_NEAR( u, float(1 + n)/2, MEAN_OK );
	EXPECT_NEAR( var, (::powf(n - 1 + 1, 2) - 1)/12, VAR_OK );

#if 0
	// output shows that this is uniformly distributed
	map<int,size_t> hist;
	for( auto & s: samples ) {
		hist[ s ]++;
	}

	cerr << to_string( hist ) << std::endl;
#endif
}
