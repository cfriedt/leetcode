#ifndef UTIL_TREENODE_HPP_
#define UTIL_TREENODE_HPP_

#if ! defined( GTEST_INCLUDE_GTEST_GTEST_H_ )
#error TreeNode.hpp should only be included in test cpp files
#endif /* ! defined( GTEST_INCLUDE_GTEST_GTEST_H_ ) */

#include <iosfwd>
#include <string>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Simple struct does not need friend decl because there are no private and protected fields.
// We make these global in order to not muck with LeetCode's TreeNode struct (i.e. cheat).
bool TreeNode_is_valid( const TreeNode *root );
bool TreeNode_string_is_valid( const std::string & s );
std::string TreeNode_to_string( const TreeNode *root );
TreeNode *TreeNode_from_string( const std::string & s );
std::ostream &operator<<( std::ostream &os, const TreeNode * & root );
std::istream &operator>>( std::istream &is, TreeNode * & root );
void TreeNode_cleanup( TreeNode * & node );
size_t TreeNode_depth( TreeNode *node, size_t current_depth );

#endif /* UTIL_TREENODE_HPP_ */
