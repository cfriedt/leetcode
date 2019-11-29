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

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

// https://leetcode.com/problems/find-and-replace-pattern/

using namespace std;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {

	vector<string> r;
	unordered_set<string> cache;

	for( auto word: words ) {

		if ( word.size() != pattern.size() ) {
			throw invalid_argument( word + " and " + pattern + " are not the same length" );
		}

		if ( cache.end() != cache.find( word ) ) {
			r.push_back( word );
			continue;
		}

		if ( matches( word, pattern ) ) {
			cache.insert( word );
			r.push_back( word );
		}
	}

	return r;
    }

protected:
	bool matches( const string & word, const string & pattern ) {

		unordered_map<char,char> p;
		unordered_map<char,char> q;

		// cout << "checking word '" << word << "' against pattern '" << pattern << "'" << endl;

		for( size_t i = 0; i < word.size(); i++ ) {

			auto & a = word[ i ];
			auto & b = pattern[ i ];

			// cout << "comparing " << a << " and " << b << endl;

			auto it = p.find( a );
			if ( p.end() == it ) {
				auto it2 = q.find( b );
				if ( q.end() == it2 ) {
					// cout << "adding " << a << " -> " << b << endl;
					p[ a ] = b;
					q[ b ] = a;
				} else {
					// cout << it2->first  << " -> " << b << " already!!! returning false.." << endl;
					return false;
				}
			} else {
				if ( it->second != b ) {
					// cout << a << " -> " << it->second << " not " << b <<  "!!! returning false.." << endl;
					return false;
				}
			}
		}

		// cout << "returning true" << endl;

		return true;
	}
};
