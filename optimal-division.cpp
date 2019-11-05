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
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class Solution {

protected:

    enum {
        LPAREN = '(',
        RPAREN = ')',
        NPAREN = '_',
    };

public:

	// https://leetcode.com/problems/optimal-division

    /*
     * Example:
     * Input: [1000,100,10,2]
     * Output: "1000/(100/10/2)"
     * Explanation:
     * 1000/(100/10/2) = 1000/((100/10)/2) = 200
     * However, the bold parenthesis in "1000/((100/10)/2)" are redundant,
     * since they don't influence the operation priority. So you should return "1000/(100/10/2)".
     *
     * Other cases:
     * 1000/(100/10)/2 = 50
     * 1000/(100/(10/2)) = 50
     * 1000/100/10/2 = 0.5
     * 1000/100/(10/2) = 2
     */
    string optimalDivision(vector<int>& nums) {
        // so let's look at ways to approach solving this problem

        // First of all, we will need to keep track of an optimal_result
        // initialize it to the most negative value.
        float optimal_result = -FLT_MAX;
        // We will need to keep track of an optimal_expression
        // Originally, this was a string, but we can defer stringification
        // until the end, because it is an orthogonal problem. Since we
        // are encoding int
        vector<int> optimal_nums = nums;
        string optimal_expression = stringify( nums );

        // We will (likely) need to evaluate an expression after it has been generated
        // so create an eval() method to do so.

        // We will (likely) need to generate some expressions with added parentheses
        // I would just as soon do that recursively because it's often initially easier
        // to formalize than non-recursively. A non-recursive solution can always be
        // created from a recursive solution, and vice-versa, of course. The
        // non-recursive solution being less prone to stack overflows.

        // Rather than numbers as strings, it might make more sense to encode
        // strings as numbers (i.e. to encode parentheses as numbers).
        // Let's say that "(" corresponds to INT_MIN, and and ")" corresponds to
        // INT_MAX. This allows us to inject parenthesis into the input vector
        // of ints, and we can evaluate expressions without incurring repeated
        // string to number conversion overhead. Would likely need to scan the
        // input vector once for those numbers before proceeding, and throw
        // if they are in use.

        // some shortcuts here
        // 1) when the input is empty, just return ""
        // 2) when the input is length 1, just return the stringified version of it

        // _ 1000 _ / _ 100 _ / _ 10 _ / _ 2 _
        // * the underscores indicate an area where a parenthesis can be
        // * if there is a number to the right of '_' (and if the '_' is not last), then a '(' can go there, or not
        // * if there is a number to the left of '_' (and if the '_' is not first), then a ')' can go there, or not        // * If there are N numbers, then there are 2N underscores
        // * Each underscore may take on 2 possible values
        // * Therefore, there are 2^(2N) possible ways to permute the underscores
        // * Only a subset of those 2^(2N) possible ways are valid
        // * Say we can only put the values +1, 0, and -1 where the the
        //   underscores are, and the sum of those numbers must equal 0.
        // * It's possible to short-circuit and quit early if there is
        //   no way to achieve that equality.
        // * Solutions are not necessarily monotonically decreasing as
        //   you evaluate terms either, which makes it a bit more difficult
        // * The sum must always be >= 0
        // * A recursive solution follows directly
        // * The recursive solution is at least O( N 2^(2N) ) => O( N k^N ) which is absolutely horrible.
        // * Likely, there is a DP way to build-up toward the optimal solution in one pass.

        helper( nums, "", nums.size(), 0, optimal_result, optimal_expression );

        return optimal_expression;
    }

protected:

    void helper( const vector<int> & nums, const string decorator, size_t lparen, size_t score, float & optimal_result, string & optimal_expression) {
        const size_t N = nums.size();
        const size_t M = 2 * N;
        size_t j = decorator.size();

        if ( j == M ) {
            if ( 0 == score ) {

                if ( "__()__" == decorator ) {
                    cout << "";
                }
                string expression = stringify( nums, decorator );
                float result = eval( nums, decorator );

                //cerr << "expression: " << expression << " result: " << result;
                bool supercede = false;

                if ( result > optimal_result ) {

                    supercede = true;

                } else if ( result == optimal_result && expression.size() < optimal_expression.size() ) {

                    supercede = true;
                }
                if ( supercede ) {
                        optimal_result = result;
                        optimal_expression = expression;
                        //cerr << " (optimal)" << endl;
                } else {
                    //cerr << endl;
                }
            }
            return;
        }

        // append '_'
        string de3 = decorator;
        de3.push_back( NPAREN );
        helper( nums, de3, lparen, score, optimal_result, optimal_expression );

        if ( false ) {
        } else if ( lparen > 0 && 0 == ( j % 2 ) ) {
            // append '('
            string de1 = decorator;
            de1.push_back( LPAREN );
            helper( nums, de1, lparen - 1, score + 1, optimal_result, optimal_expression );
        } else if ( score > 0 && 1 == ( j % 2 ) ) {
//            if ( j > 0 && LPAREN == decorator[ j - 1 ] ) {
//                // we do not want e.g. (2) because the parenthesis are redundant
//                return;
//            }
            // append ')'
            string de2 = decorator;
            de2.push_back( RPAREN );
            helper( nums, de2, lparen, score - 1, optimal_result, optimal_expression );
        }
    }

    static vector<int> getExpr( const vector<int> & expression, const size_t & offset ) {

        vector<int> r;

        if ( offset >= expression.size() ) {
            return r;
        }

        size_t len = 0;
        if ( LPAREN == expression[ offset ] ) {
            // we are looking for the first RPAREN that settles the score
            for( size_t j = offset + 1, score = 1; j < expression.size(); j++ ) {
                if ( LPAREN == expression[ j ] ) {
                    score++;
                } else if ( RPAREN == expression[ j ] ) {
                    score--;
                    if ( 0 == score ) {
                        len = j - offset + 1;
                        break;
                    }
                }
            }
        } else {
            len = 1;
            // we are looking for the first LPAREN
            for( size_t j = offset + 1; j < expression.size(); j++, len++ ) {
                if ( LPAREN == expression[ j ] ) {
                    break;
                }
            }
        }
        r = vector<int>( expression.begin() + offset, expression.begin() + offset + len );
        return r;
    }

    static float eval( const vector<int> & expression ) {

        float divisor;
        float dividend;
        float quotient;
        vector<int> divisorExpr;
        vector<int> dividendExpr;
        vector<int> rest;

#if 0
        stringstream ss;
        ss << stringify( expression );
#endif

        if ( 0 == expression.size() ) {
            return 0;
        }

        switch( expression.size() ) {
            case 1:
                // a
                divisor = float( expression[ 0 ] );
                dividend = 1.0f;
                rest.clear();
                break;

            case 2:
                // a/b
                divisor = float( expression[ 0 ] );
                dividend = float( expression[ 1 ] );
                rest.clear();
                break;

            case 3:
                if ( LPAREN == expression[ 0 ] ) {
                    // (a)
                    divisor = float( expression[ 1 ] );
                    dividend = 1.0f;
                    rest.clear();
                    break;
                }
                /* fallthrough */
                /* no break */

            default:

                divisorExpr = getExpr( expression, 0 );

                if ( divisorExpr.size() == expression.size() ) {
                    if ( LPAREN == expression[ 0 ] ) {
                        // ( expr )
                        divisorExpr = vector<int>( expression.begin() + 1, expression.end() - 1 );
                        dividend = 1.0f;
                        rest.clear();
                    } else {
                        // a / b / c / d / ... / z
                        divisorExpr =  vector<int>( expression.begin(), expression.end() - 1 );
                        dividendExpr = vector<int>({ expression.back() });
                        dividend = eval( dividendExpr );
                    }
                } else {
                    dividendExpr = getExpr( expression, divisorExpr.size() );
                    dividend = eval( dividendExpr );

                    if ( expression.size() == divisorExpr.size() + dividendExpr.size() ) {
                        rest.clear();
                    } else {
                        rest = getExpr( expression, divisorExpr.size() + dividendExpr.size() );
                    }
                }
                divisor = eval( divisorExpr );

                break;
        }

        if ( rest.empty() ) {
            quotient = divisor / dividend;
        } else {
            quotient = divisor / dividend / eval( rest );
        }

#if 0
        ss << " = " << quotient;
        cerr << ss.str() << endl;
#endif

        return quotient;
    }

    static float eval( const vector<int> & nums, const string & decorator ) {
        if ( decorator.size() != 2 * nums.size() ) {
            throw invalid_argument( "nums.size() (" + to_string( nums.size() ) + ") != 2 * decorators.size() (" + to_string( decorator.size() ) + ")" );
        }
        vector<int> expression;
        for( size_t j = 0; j < decorator.size(); j += 2 ) {
            size_t i = j / 2;
            if ( LPAREN == decorator[ j ] ) {
                expression.push_back( LPAREN );
            }
            expression.push_back( nums[ i ] );
            if ( RPAREN == decorator[ j + 1 ] ) {
                expression.push_back( RPAREN );
            }
        }
        return eval( expression );
    }

    static string stringify( const vector<int> & nums, const string & decorator ) {
        if ( decorator.size() != 2 * nums.size() ) {
            throw invalid_argument( "nums.size() (" + to_string( nums.size() ) + ") != 2 * decorators.size() (" + to_string( decorator.size() ) + ")" );
        }
        vector<int> expression;
        for( size_t j = 0; j < decorator.size(); j += 2 ) {
            size_t i = j / 2;
            if ( LPAREN == decorator[ j ] ) {
                expression.push_back( LPAREN );
            }
            expression.push_back( nums[ i ] );
            if ( RPAREN == decorator[ j + 1 ] ) {
                expression.push_back( RPAREN );
            }
        }
        return stringify( expression );
    }

    static string stringify( const vector<int> & expression ) {
        string s;
        for( size_t i = 0; i < expression.size(); i++ ) {
            const int & e = expression[ i ];
            switch( e ) {
            case LPAREN: s += "("; break;
            case RPAREN: s += ")"; break;
            default: s += to_string( e ); break;
            }
            if (
                true
                && i < expression.size() - 1
                && LPAREN != expression[ i ]
                && RPAREN != expression[ i + 1 ]
             ) {
                s += "/";
            }
        }
        return s;
    }
};
