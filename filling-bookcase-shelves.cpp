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

#include <climits>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>

using namespace std;

struct book_t {
    size_t i;
    size_t thickness;
    size_t height;
    book_t() :  i( 0 ), thickness( 0 ), height( 0 ) {}
    book_t( int i, int thickness, int height ) : i( i ), thickness( thickness ), height( height ) {}
    book_t( int i, const vector<vector<int>> & books ) : i( i ), thickness( books[ i ][ 0 ] ), height( books[ i ][ 1 ] ) {}
};

struct shelf_t {
    const size_t width;
    size_t room;
    size_t tallest;
    vector<book_t> books;
    explicit shelf_t( size_t width ) : width( width ), room( width ), tallest( 0 ) {}
    void add( const book_t & book ) {
        if ( book.thickness > room ) {
            throw logic_error( "book with width " + to_string( book.thickness ) + " is too wide for shelf with room " + to_string( room ) );
        }
        books.push_back( book );
        room -= book.thickness;
        if ( book.height > tallest ) {
            tallest = book.height;
        }
    }
};

ostream & operator<<(ostream & os, const book_t & book);
ostream & operator<<(ostream & os, const shelf_t & shelf);

class Solution {

public:

	// https://leetcode.com/problems/filling-bookcase-shelves/

    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {

        int min_height = INT_MAX;

        helper( books, shelf_width, 0, vector<shelf_t>(), min_height );

        return min_height;
    }

protected:

    void helper( const vector<vector<int>> & books, const int & shelf_width, size_t i, vector<shelf_t> shelves, int & min_height ) {

        if ( i >= books.size() ) {

            // done. print contents of shelves and total height
            int total_height = 0;
            for( size_t j = 0; j < shelves.size(); j++ ) {
                total_height += shelves[ j ].tallest;
            }

            if ( total_height <= min_height ) {
                min_height = total_height;
#if 0
                cerr << "================================================================================" << endl;

                for( size_t j = 0; j < shelves.size(); j++ ) {
                    cerr << j << ": " << shelves[ j ] << endl;
                }

                cerr << "min height: " << min_height << endl;
#endif
            }

            return;
        }

        book_t book( i, books );

        for( size_t j = 0; j < shelves.size(); j++ ) {
            if ( shelves[ j ].room >= book.thickness ) {
                auto new_shelves = shelves;
                new_shelves[ j ].add( book );
                helper( books, shelf_width, i + 1, new_shelves, min_height );
            }
        }

        if ( shelves.size() < books.size() ) {
            auto new_shelves = shelves;
            new_shelves.push_back( shelf_t( shelf_width ) );
            new_shelves.back().add( book );
            helper( books, shelf_width, i + 1, new_shelves, min_height );
        }
    }
};

ostream & operator<<(ostream & os, const book_t & book) {
    stringstream ss;

    ss << "book: {i: " << book.i << ", t: " << book.thickness << ", h: " << book.height << "}";

    os << ss.str();
    return os;
}

ostream & operator<<(ostream & os, const shelf_t & shelf) {
    stringstream ss;

    ss << "shelf: {";

    for( size_t i = 0; i < shelf.books.size(); i++ ) {
        ss << shelf.books[ i ];
        if ( i < shelf.books.size() - 1 ) {
            ss << ", ";
        }
    }

    ss << "}";

    os << ss.str();
    return os;
}
