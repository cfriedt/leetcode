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

#include <unordered_set>

#include <gtest.h>

#include "minimum-unique-word-abbreviation.cpp"

TEST( MinimumUniqueWordAbbreviation, Test_apple__foo ) {
	vector<string> dictionary({"foo"});
	string target = "apple";

	unordered_set<string> expected_string_values({to_string( target.size() )});

	string actual_string = Solution().minAbbreviation(target, dictionary);

	EXPECT_GT( expected_string_values.count( actual_string ), size_t( 0 ) );
}

TEST( MinimumUniqueWordAbbreviation, Test_apple__blade ) {
	vector<string> dictionary({"blade"});
	string target = "apple";

	unordered_set<string> expected_string_values({"a4"});

	string actual_string = Solution().minAbbreviation(target, dictionary);

	EXPECT_GT( expected_string_values.count( actual_string ), size_t( 0 ) );
}

TEST( MinimumUniqueWordAbbreviation, Test_apple__plain_amber_blade ) {
	vector<string> dictionary({"plain", "amber", "blade"});
	string target = "apple";

	unordered_set<string> expected_string_values({"1p3", "ap3", "a3e", "2p2", "31e", "3l1"});

	string actual_string = Solution().minAbbreviation(target, dictionary);

	EXPECT_GT( expected_string_values.count( actual_string ), size_t( 0 ) );
}

TEST( MinimumUniqueWordAbbreviation, Test_apple__kkkkk ) {
	vector<string> dictionary({"kkkkk"});
	string target = "apple";

	string actual_string = Solution().minAbbreviation(target, dictionary);

	unordered_set<string> expected_string_values({"a4"});

	EXPECT_GT( expected_string_values.count( actual_string ), size_t( 0 ) );
}

TEST( MinimumUniqueWordAbbreviation, Test_abcdef__ablade_xxxxef_abdefi ) {
	vector<string> dictionary({"ablade","xxxxef","abdefi"});
	string target = "abcdef";

	string expected_string = "2c3";
	string actual_string = Solution().minAbbreviation(target, dictionary);

	EXPECT_EQ( actual_string, expected_string );
}

static string generateRandomStringOfLength( const size_t & M ) {
	string r( M, '\0' );
	for( size_t i = 0; i < M; i++ ) {
		size_t j = ::rand() % 26;
		r[ i ] = 'a' + j;
	}
	return r;
}

string expandAbbreviated( const string & abbrev, const char marker ) {
	string r;
	uint32_t n;
	for( size_t i = 0; i < abbrev.size(); i++ ) {
		if( '1' <= abbrev[ i ] && abbrev[ i ] <= '9' ) {
			sscanf( abbrev.substr( i ).c_str(), "%u", & n );
			for( ; i + 1 < abbrev.size() && '0' <= abbrev[ i + 1 ] && abbrev[ i + 1 ] <= '9'; i++ );
			for( ; n != 0; n-- ) {
				r += marker;
			}
		} else {
			r += abbrev[ i ];
		}
	}
	return r;
}

static void verifyRandom( const string & abbrev, const string & target, const vector<string> & dictionary ) {

	const size_t M = target.size();

	string expanded = expandAbbreviated( abbrev, '*' );

	ASSERT_EQ( M, expanded.size() );

	// verify that the expanded string matches the target string

	for( size_t i = 0; i < M; i++ ) {
		if ( expanded[ i ] == '*' ) {
			continue;
		}
		ASSERT_EQ( expanded[ i ], target[ i ] );
	}

	for( auto & word: dictionary ) {
		if ( M != word.size() ) {
			continue;
		}

		bool one_character_differs = false;
		for( size_t i = 0; i < M; i++ ) {
			if ( expanded[ i ] == '*' ) {
				continue;
			}
			if ( expanded[ i ] != word[ i ] ) {
				one_character_differs = true;
				break;
			}
		}
		ASSERT_TRUE( one_character_differs );
	}
}

TEST( MinimumUniqueWordAbbreviation, Test_limits ) {

	const size_t M = 21;
	const size_t N = 1000;

	unordered_set<string> dict;
	for( ; dict.size() != N; ) {
		dict.insert( generateRandomStringOfLength( M ) );
	}

	vector<string> dictionary(dict.begin(), dict.end());
	string target;

	for( target = generateRandomStringOfLength( M ); dict.count( target ) > 0; target = generateRandomStringOfLength( M ) );

	string abbrev = Solution().minAbbreviation(target, dictionary);

	verifyRandom( abbrev, target, dictionary );
}
