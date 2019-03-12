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

#include <array>
#include <vector>

using namespace std;

class Solution {
public:

	// https://leetcode.com/problems/fruit-into-baskets/

	int totalFruit(vector<int>& tree) {
		int most_fruit = 0;

		for( size_t starting_tree = 0; starting_tree < tree.size(); starting_tree++ ) {

			array<int,2> basket({-1,-1});
			vector<int> fruit;

			for( size_t i = starting_tree; i < tree.size(); i++ ) {
				if ( false ) {
				} else if ( tree[ i ] ==  basket[ 0 ] || tree[ i ] ==  basket[ 1 ] ) {
					fruit.push_back( tree[ i ] );
				} else if( -1 == basket[ 0 ] ) {
					basket[ 0 ] = tree[ i ];
					fruit.push_back( tree[ i ] );
				} else if( -1 == basket[ 1 ] ) {
					basket[ 1 ] = tree[ i ];
					fruit.push_back( tree[ i ] );
				} else {
					break;
				}
			}

			if ( int( fruit.size() ) > most_fruit ) {
				most_fruit = fruit.size();
			}
		}

		return most_fruit;
	}
};
