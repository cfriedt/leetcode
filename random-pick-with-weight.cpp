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

#include <cstdlib>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:

	// https://leetcode.com/problems/random-pick-with-weight

    explicit Solution(vector<int> w) {
        // I think the easiest solution is to create a vector of indices, repeating elements for how many times w[i] is present
        // and then just use random() % indices.size() to choose an index.
        //
    	// vector<int> indices;
    	// ctor:
        // for( size_t i = 0; i < w.size(); i++ ) {
        //    for( size_t j = 0; j < w[ i ]; j++ ) {
        //        indices.push_back( i );
        //    }
        // }
    	// pick:
        // size_t r = random();
        // r %= indices.size();
        // return indices[ r ];
        //
        // The obvious problem with this is space complexity.
        // Say w.length is 10000 and each element is on the order of 10000
        // then that would mean our indices vector is 10000^2 elements long, or 100,000,000
        // That's O( N^2 ) space complexity, and O( KN^2 ) in time complexity!!
        // We have to be able to do it in less!!
        //
        // So say we sum up the total of weights and then form a discrete probability distribution.
        //
        // P(0) == w[0]/sum(w), P(1) = w[1]/sum(w), ... P(i) = w[i]/sum(w).
        //
        // Say we put these probabilities into a cumulative histogram - e.g. a vector<float>.
        //
        // Then, let's convert the value from random() into a float => random() / RAND_MAX.
        //
        // Then we just have to perform an O( N ) pass over our cumulative histogram to
    	// see at which percentile (i), the random percent lies!
        //
        // O( N ) to sum up the weights, O( N ) to create a cumulative histogram O( N ) to do a pass in pickIndex().
        //
        // O( N ) time and O( N ) space.
    	//
    	// However, taking into account K calls to pickIndex, that becomes O( KN ) time!!!
    	// Still quadratic!!!!!
    	//
    	// IMPROVEMENT
    	//
        // To improve times for pickIndex, which will be called up to 10000 times,
    	// the cumulative histogram could be kept inside of an ordered map (e.g. r-b tree)
        // The random percent would need to be rounded up to a floating point multiple of some number.
        //
        // This would improve times for K pickIndex from O( KN ) to O( K log N )
        // The overall time to construct and pick K random indices would then become
        //
        // O( N + NlogN + K log N ) instead of O( 2N + KN )
    	//
    	// Space would still be O( N )

        size_t sum_of_weights = accumulate( w.begin(), w.end(), 0 );

        float cumulative = 0;
        for( size_t i = 0; i < w.size(); i++ ) {
            float this_pcnt = float( w[i] ) / float( sum_of_weights );
            cumulative += this_pcnt;
            chist.push_back( cumulative );
        }
    }

    int pickIndex() {

        if ( chist.size() <= 1 ) {
            return 0;
        }

        float pcnt = randomPercent();

        size_t i;
        for( i = 0; i < chist.size(); i++ ) {
            if ( pcnt <= chist[ i ] ) {
                break;
            }
        }

        return i;
    }

protected:
    vector<float> chist;

    float randomPercent() {
        return float( ::random() ) / float( RAND_MAX );
    }
};
