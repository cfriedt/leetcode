/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "insert-delete-getrandom-o1.cpp"

TEST( InsertDeleteGetRandomO1, Test_A ) {

//	["RandomizedSet","insert","remove","insert","getRandom","remove","insert","getRandom"]
//	[[],[1],[2],[2],[],[1],[2],[]]

	RandomizedSet s;
	EXPECT_EQ( s.insert( 1 ), true );
	EXPECT_EQ( s.remove( 2 ), false );
	EXPECT_EQ( s.insert( 2 ), true );
	int x = s.getRandom();
	EXPECT_TRUE( x == 1 || x == 2 );
	EXPECT_EQ( s.remove( 1 ), true );
	EXPECT_EQ( s.insert( 2 ), false );
	EXPECT_EQ( s.getRandom(), 2 );
}

TEST( InsertDeleteGetRandomO1, Test_B ) {

	//Call: ["RandomizedSet","remove","remove","insert","getRandom","remove","insert"]
	//Arg: [[],[0],[0],[0],[],[0],[0]]
	//Expected: [null,false,false,true,0,true,true]

	RandomizedSet s;
	EXPECT_EQ(s.remove(0), false);
	EXPECT_EQ(s.remove(0), false);
	EXPECT_EQ(s.insert(0), true);
	EXPECT_EQ(s.getRandom(), 0 );
	EXPECT_EQ(s.remove(0), true);
	EXPECT_EQ(s.insert(0), true);
}

TEST( InsertDeleteGetRandomO1, Test_C ) {

	//Call: ["RandomizedSet","insert","insert","getRandom","getRandom","insert","remove","getRandom","getRandom","insert","remove"]
	//Arg:  [[],[3],[3],[],[],[1],[3],[],[],[0],[0]]
	//Expected: [null,true,false,3,3,true,true,3,3,true,true]

	RandomizedSet s;
	EXPECT_EQ(s.insert(3), true);
	EXPECT_EQ(s.insert(3), false);
	EXPECT_EQ(s.getRandom(), 3 );
	EXPECT_EQ(s.getRandom(), 3 );
	EXPECT_EQ(s.insert(1), true);
	EXPECT_EQ(s.remove(3), true);
	EXPECT_EQ(s.getRandom(), 1 );
	EXPECT_EQ(s.getRandom(), 1 );
	EXPECT_EQ(s.insert(0), true);
	EXPECT_EQ(s.remove(0), true);
}
