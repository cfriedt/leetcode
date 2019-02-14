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
