/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "implement-trie-prefix-tree.cpp"
TEST( ImplementTriePrefixTree, Test_Example1 ) {

	 Trie obj;
	 obj.insert( "apple" );
	 EXPECT_EQ( true, obj.search( "apple" ) );
	 EXPECT_EQ( false, obj.search( "app" ) );
	 EXPECT_EQ( true, obj.startsWith( "app" ) );
	 obj.insert( "app" );
	 EXPECT_EQ( true, obj.search( "app" ) );
}
TEST( ImplementTriePrefixTree, Test_Example2 ) {

	 Trie obj;
	 obj.insert( "hello" );
	 EXPECT_EQ( false, obj.search( "hell" ) );
	 EXPECT_EQ( false, obj.search( "helloa" ) );
	 EXPECT_EQ( true, obj.search( "hello" ) );
	 EXPECT_EQ( true, obj.startsWith( "hell" ) );
	 EXPECT_EQ( false, obj.startsWith( "helloa" ) );
	 EXPECT_EQ( true, obj.startsWith( "hello" ) );
}

TEST( ImplementTriePrefixTree, Test_Example3 ) {
	 Trie obj;
	 EXPECT_EQ( false, obj.search( "a" ) );
}
