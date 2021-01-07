/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:

	// https://leetcode.com/problems/binary-tree-preorder-traversal/

	// RECURSIVE
	/*
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> ret;
		if ( nullptr == root ) {
			return ret;
		}
		ret.push_back( root->val );
		vector<int> left = preorderTraversal( root->left );
		vector<int> right = preorderTraversal( root->right );
		for( auto l: left ) {
			ret.push_back( l );
		}
		for( auto r: right ) {
			ret.push_back( r );
		}
		return ret;
	}
	*/

	// NON-RECURSIVE
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> ret;
		if ( nullptr == root ) {
			return ret;
		}
		TreeNode *it;
		unordered_set<TreeNode*> visited;
		vector<TreeNode*> parent;
		for( it = root;; ) {
			if ( visited.end() == visited.find( it ) ) {
				visited.insert( it );
				ret.push_back( it->val );
			}
			if ( nullptr != it->left && visited.end() == visited.find( it->left ) ) {
				parent.push_back( it );
				it = it->left;
				continue;
			}
			if ( nullptr != it->right && visited.end() == visited.find( it->right ) ) {
				parent.push_back( it );
				it = it->right;
				continue;
			}
			if ( parent.empty() ) {
				break;
			}
			it = parent.back();
			parent.pop_back();
		}

		return ret;
	}
};
