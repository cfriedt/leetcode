#ifndef UTIL_TRIM_HPP_
#define UTIL_TRIM_HPP_

#include <ctype.h>
#include <string>
static inline void trim( std::string & s ) {
	for( ; !s.empty() && ::isspace( s[ 0 ] ); ) {
		s = s.substr( 1 );
	}
	for( ; !s.empty() && ::isspace( s[ s.length() - 1 ] ); ) {
		s = s.substr( 0, s.length() - 2 );
	}
}

#endif /* UTIL_TRIM_HPP_ */
