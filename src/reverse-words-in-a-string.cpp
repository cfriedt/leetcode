/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:

	// https://leetcode.com/problems/reverse-words-in-a-string/

	static void trim( string & s ) {
		for( ; !s.empty() && ::isspace( s[ 0 ] ); ) {
			s = s.substr( 1 );
		}
		for( ; !s.empty() && ::isspace( s[ s.length() - 1 ] ); ) {
			s = s.substr( 0, s.length() - 2 );
		}
	}

	void reverseWords(string &s) {
	//Assumptions:
	//ok to use stringstream
	//following prototype is ok
	//string reverseWords( string input );
	//
	//Notes:
	//Kind of the nice thing about stringstream is that it skips whitespace for you automatically when used with getline (unless you tell it not to!)
	//
	//Algorithm Outline
	//Use a vector<string> as a stack to append strings to the back until the last of the words has been parsed
	//once all of the strings have been parsed, pop the back of the vector and append a space and the popped word to the output string
	//
	//Corner cases:
	//Obviously if the input is empty then the output will be empty
	//Have to consider multiple spaces, tabs, etc, but I believe the ss / getline will handle that.

		string tok;

		// O( N ) space, N being the number of words
		vector<string> stack;

		trim( s );

		if ( "" == s ) {
			return;
		}

		stringstream ss( s );

		// O( N ) time
		while( getline( ss, tok, ' ' ) ) {
			if ( ! tok.empty() ) {
				stack.push_back( tok );
			}
		}

		ss.clear();

		// O( N ) time
		for( bool first = true; ! stack.empty(); first = false ) {
			tok = stack.back();
			stack.pop_back();
			// cannot have preceding whitespace
			if ( ! first ) {
				ss << " ";
			}
			ss << tok;
		}

		s = ss.str();
	}
};
