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

#include <unordered_map>

#include <gtest/gtest.h>

#include "random-pick-with-weight.cpp"

TEST( RandomPickWithWeight, Test_nil ) {
	vector<int> w;
	Solution soln(w);
	int expected_int = 0;
	int actual_int = soln.pickIndex();
	EXPECT_EQ(actual_int, expected_int);
}

TEST( RandomPickWithWeight, Test_1 ) {
	vector<int> w({1});
	Solution soln(w);
	int expected_int = 0;
	int actual_int = soln.pickIndex();
	EXPECT_EQ(actual_int, expected_int);
}

TEST( RandomPickWithWeight, Test_1000000 ) {
	vector<int> w({1000000});
	Solution soln(w);
	int expected_int = 0;
	int actual_int = soln.pickIndex();
	EXPECT_EQ(actual_int, expected_int);
}

TEST( RandomPickWithWeight, Test_1_3_1 ) {
	vector<int> w({1,3,1});
	Solution soln(w);

	size_t n1s = 0;
	for( size_t i = 0; i < 10; i++ ) {
		size_t idx = soln.pickIndex();
		if ( 1 == idx ) {
			n1s++;
		}
	}

	EXPECT_GT( n1s, 0 );
}

vector<float> createHistogram( const vector<int> & w ) {
	vector<float> chist( w.size() );
	size_t sum_of_weights = accumulate( w.begin(), w.end(), 0 );
	float cumulative;
	size_t i;
	for( cumulative = 0, i = 0; i < w.size(); i++ ) {
		float pcnt = float( w[ i ] ) / float( sum_of_weights );
		cumulative += pcnt;
		chist[ i ] = cumulative;
	}
	return chist;
}

vector<float> createHistogram( const size_t expected_size, const unordered_map<size_t,size_t> & results ) {
	vector<float> chist( expected_size, 0.0 );

	size_t samples = 0;
	for( auto & kv: results ) {
		samples += kv.second;
	}

	float cumulative = 0;
	for( size_t i = 0; i < chist.size(); i++ ) {
		size_t n;
		if ( 0 == results.count( i ) ) {
			n = 0;
		} else {
			n = results.at( i );
		}

		float pcnt = float( n ) / float( samples );
		cumulative += pcnt;
		chist[ i ] = cumulative;
	}
	return chist;
}

TEST( RandomPickWithWeight, Test_w_size_10000_with_elements_le_10000 ) {
	vector<int> w;
	for( size_t i = 0; i < 10000; i++ ) {
		if ( 5000 != i ) {
			w.push_back( 1 );
		} else {
			w.push_back( 10000 );
		}
	}
	Solution soln(w);

	unordered_map<size_t,size_t> results;
	for( size_t i = 0; i < 10000; i++ ) {
		int index = soln.pickIndex();
		ASSERT_GE( index, 0 );
		ASSERT_LT( index, w.size() );

		//cerr << "index: " << index << endl;

		results[ index ]++;
	}

	cout << endl;
}
