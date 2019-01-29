#ifndef UTIL_SPLIT_HPP_
#define UTIL_SPLIT_HPP_

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>

#include "trim.hpp"

// split a string into words separated by whitespace
static inline std::vector<std::string> split( std::string & s ) {
	std::vector<std::string> r;

	trim( s );

	if ( "" == s ) {
		return r;
	}

	std::stringstream ss;
	std::string tok;

	ss.str( s );

	while( getline( ss, tok, ' ' ) ) {
		if ( ! tok.empty() ) {
			r.push_back( tok );
		}
	}

	return r;
}

#endif /* UTIL_SPLIT_HPP_ */
