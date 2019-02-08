#ifndef UTIL_SUFFIXTREENODE_HPP_
#define UTIL_SUFFIXTREENODE_HPP_

#if ! defined( GTEST_INCLUDE_GTEST_GTEST_H_ )
#error ListNode.hpp should only be included in test cpp files
#endif /* ! defined( GTEST_INCLUDE_GTEST_GTEST_H_ ) */

#include <string>
#include <unordered_map>

struct SuffixTreeNode {
	size_t leaf_number;
	std::unordered_map<std::string,SuffixTreeNode *> child;
};

std::string SuffixTreeNode_to_string( SuffixTreeNode *root );

void SuffixTreeNode_cleanup( SuffixTreeNode **root );

#endif /* UTIL_SUFFIXTREENODE_HPP_ */
