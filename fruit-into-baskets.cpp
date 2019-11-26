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

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {

	// https://leetcode.com/problems/fruit-into-baskets/

public:
	int totalFruit(vector<int>& tree) {

		cout << "tree size: " << tree.size() << endl;

		int most = 0;
		for( size_t start = 0; start < tree.size(); start++ ) {
			unordered_map<int,size_t> basket;
			//cerr << "start: " << start << endl;
			for( size_t i = start; i < tree.size(); i++ ) {
				if ( basket.empty() ) {
					basket[ tree[ i ] ] = 1;
					continue;
				}
				auto it = basket.find( tree[ i ] );
				if ( basket.end() == it ) {
					if ( 2 == basket.size() ) {
						break;
					}
					basket[ tree[ i ] ] = 1;
					continue;
				}

				it->second++;
			}
			int candidate_most = sum( basket );
			if ( candidate_most > most ) {
				most = candidate_most;
			}
		}
		return most;
	}

	int sum( const unordered_map<int,size_t> & basket ) {
		int sum = 0;
		for( auto & kv: basket ) {
			sum += kv.second;
		}
		return sum;
	}
};
