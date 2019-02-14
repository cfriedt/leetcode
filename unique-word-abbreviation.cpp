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
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// https://leetcode.com/problems/unique-word-abbreviation/

class ValidWordAbbr {
public:
	explicit ValidWordAbbr(vector<string> dictionary) {
    	for( auto & word: dictionary ) {
    		string abbrv = abbreviate( word );
    		original.insert(word);
    		abbreviated[ abbrv ]++;
    	}
    }

    bool isUnique(string word) {
    	string abbrv = abbreviate( word );
    	size_t oc = original.count( word );
    	size_t ac = (abbreviated.end() == abbreviated.find( abbrv )) ? 0 : abbreviated[ abbrv ];
    	return 0 == ac || ( 1 == oc && 1 == ac );
    }

protected:
    unordered_map<string,size_t> abbreviated;
    unordered_set<string> original;

    string abbreviate( const string & word ) {
		string abbrv = word[ 0 ] + to_string( word.size() - 2 ) + word[ word.size() - 1 ];
		return abbrv;
    }
};
