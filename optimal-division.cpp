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
#include <cstdlib>
#include <stdexcept>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {

protected:
    enum {
        LPAREN = INT_MIN,
        RPAREN = INT_MAX,
        NPAREN = INT_MIN + 1,
    };

    using cache_t = unordered_map<string,float>;

public:

	// https://leetcode.com/problems/optimal-division

    string optimalDivision(vector<int>& nums) {

        cache_t cache;
        float optimal_quotient = -FLT_MAX;
        string optimal_string;

        check_input( nums );

        helper( nums, cache, optimal_quotient, optimal_string, vector<int>(), "" );

        return optimal_string;
    }

protected:

    static void check_input( const vector<int> & nums ) {
        for( auto & e: nums ) {
            if ( LPAREN == e || RPAREN == e || NPAREN == e ) {
                throw invalid_argument( "value " + to_string( e ) + " is reserved!" );
            }
        }
    }

    // this is mainly for unit tests..
    static float eval( const string & exprstr ) {
        cache_t cache;
        vector<int> expression = to_expression( exprstr );
        return eval( expression, exprstr, cache );
    }

    static vector<int> to_expression( const string & exprstr ) {

        string s = exprstr;
        vector<int> r;
        for( ; s.size(); ) {

            switch( s[ 0 ] ) {
            case '(':
                r.push_back( LPAREN );
                s = s.substr( 1 );
                continue;
            case ')':
                r.push_back( RPAREN );
                s = s.substr( 1 );
                continue;
            case '/':
                s = s.substr( 1 );
                continue;
            default:
                break;
            }

            size_t len;
            for( len = 0; !( '/' == s[ len ] || '(' == s[ len ] || ')' == s[ len ] ); len++ );
            r.push_back( ::atoi( s.substr( 0, len ).c_str() ) );
            s = s.substr( len );
        }
        return r;
    }

    static float eval( const vector<int> & nums, const vector<int> & decorator, const string & exprstr, cache_t & cache ) {
        return eval( combine( nums, decorator ), exprstr, cache );
    }

    static float eval( const vector<int> & expression, const string & exprstr, cache_t & cache ) {

        float r;
        bool simple;

        auto it = cache.find( exprstr );
        if ( cache.end() != it ) {
            return it->second;
        }

        switch( expression.size() ) {
        case 0: r = 0; simple = true; break;
        case 1: r = float( expression[ 0 ] ); simple = true; break;
        case 2: r = float( expression[ 0 ] ) / float( expression[ 1 ] ); simple = true; break;
        case 3:
            if ( LPAREN == expression[ 0 ] ) {
                r = float( expression[ 1 ] ); simple = true; break;
            }
            // fall through
            // no break

        default:
            break;
        }

        if ( simple ) {
            cache[ exprstr ] = r;
            return r;
        }

        return 0;
    }

    static vector<int> combine( const vector<int> & nums, const vector<int> & decorator ) {
        vector<int> r( nums.size() + decorator.size(), 0 );

        if ( decorator.size() != 2 * nums.size() ) {
            throw invalid_argument( "decorator size must be twice nums size!" );
        }

        for( size_t i = 0, j = 0; i < decorator.size(); i += 2, j += 3 ) {
            size_t k = i / 2;
            r[ j ] = decorator[ i ];
            r[ j + 1 ] = nums[ k ];
            r[ j + 2 ] = decorator[ i + 1 ];
        }

        return r;
    }

    static string stringify( const vector<int> & expression ) {
        string r;
        stringstream ss;
        for( auto & e: expression ) {
            switch( e ) {
            case LPAREN: ss << "("; break;
            case RPAREN: ss << ")"; break;
            case NPAREN: break;
            default: ss << e; break;
            }
        }
        r = ss.str();
        return r;
    }

    static string stringify( const vector<int> & nums, const vector<int> & decorator ) {
        return stringify( combine( nums, decorator ) );
    }

    static float helper( const vector<int> & nums, cache_t & cache, float & optimal_result, string & optimal_string, vector<int> decorator, string exprstr ) {

        (void) nums;
        (void) cache;
        (void) optimal_result;
        (void) optimal_string;
        (void) decorator;
        (void) exprstr;

        return 0;
    }
};
