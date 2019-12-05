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

#ifndef UTIL_TREENODE_HPP_
#define UTIL_TREENODE_HPP_

#if ! defined( GTEST_INCLUDE_GTEST_GTEST_H_ )
#error TreeNode.hpp should only be included in test cpp files
#endif /* ! defined( GTEST_INCLUDE_GTEST_GTEST_H_ ) */

#include <iosfwd>
#include <string>
#include <vector>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : TreeNode(0) {}
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Simple struct does not need friend decl because there are no private and protected fields.
// We make these global in order to not muck with LeetCode's TreeNode struct (i.e. cheat).
bool TreeNode_is_valid( const TreeNode *root );
bool TreeNode_string_is_valid( const std::string & s );
std::string TreeNode_to_string( TreeNode *root );
TreeNode *TreeNode_from_string( const std::string & s );
std::ostream &operator<<( std::ostream &os, const TreeNode * & root );
std::istream &operator>>( std::istream &is, TreeNode * & root );
void TreeNode_cleanup( TreeNode * & node );
size_t TreeNode_depth( TreeNode *node, size_t current_depth );

#endif /* UTIL_TREENODE_HPP_ */
