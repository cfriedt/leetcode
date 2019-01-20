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

#include <gtest.h>

#include "koko-eating-bananas.cpp"

TEST( KokoEatingBananas, Test_3_6_7_11__8 ) {
	vector<int> piles({3,6,7,11});
	int H( 8 );
	int expected_int( 4 );
	int actual_int = Solution().minEatingSpeed(piles, H);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( KokoEatingBananas, Test_30_11_23_4_20__5 ) {
	vector<int> piles({30,11,23,4,20});
	int H( 5 );
	int expected_int( 30 );
	int actual_int = Solution().minEatingSpeed(piles, H);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( KokoEatingBananas, Test_30_11_23_4_20__6 ) {
	vector<int> piles({30,11,23,4,20});
	int H( 6 );
	int expected_int( 23 );
	int actual_int = Solution().minEatingSpeed(piles, H);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( KokoEatingBananas, Test_312884470__968709470 ) {
	vector<int> piles({312884470});
	int H( 968709470 );
	int expected_int( 1 );
	int actual_int = Solution().minEatingSpeed(piles, H);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( KokoEatingBananas, Test_332484035_524908576_855865114_632922376_222257295_690155293_112677673_679580077_337406589_290818316_877337160_901728858_679284947_688210097_692137887_718203285_629455728_941802184__823855818 ) {
	vector<int> piles({332484035, 524908576, 855865114, 632922376, 222257295, 690155293, 112677673, 679580077, 337406589, 290818316, 877337160, 901728858, 679284947, 688210097, 692137887, 718203285, 629455728, 941802184});
	int H( 823855818 );
	int expected_int( 14 );
	int actual_int = Solution().minEatingSpeed(piles, H);
	EXPECT_EQ(actual_int, expected_int);
}
