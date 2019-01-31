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
