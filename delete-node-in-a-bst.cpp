/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <utility>

using namespace std;

class Solution {
public:

	// https://leetcode.com/problems/delete-node-in-a-bst/

	TreeNode* deleteNode(TreeNode* root, int key) {

		TreeNode *parent;
		TreeNode *node;

		findNode( root, key, node, parent );

		if ( nullptr == node ) {
			return root;
		}

		// The rules according to Hibbard, '62 are:
		//
		// 0 Children:
		//    Simply mark the applicable link in the parent node to null.
		//
		// 1 Child:
		//    Set the applicable link the in the parent node to point to the child.
		//
		// 2 Children:
		//    Choose either the in-order predecessor or in-order successor.
		//    Copy the value from the predecessor or successor to the node to be deleted.
		//    If the predecessor or successor has a child (there can be only one), reparent
		//    the child to the predecessor or successor's parent.

		TreeNode *removed_node = nullptr; // This memory would be leaked, since we don't give it back to
								// the user. Normally, I would make deleteNode() return
								// the actual node that was deleted rather than the
								// tree root.

		if ( false ) {
		} else if ( nullptr == node->left && nullptr == node->right ) {

			// Case #0

			if ( parent ) {
				if ( parent->left == node ) {
					parent->left = nullptr;
				} else {
					parent->right = nullptr;
				}
			} else {
				root = nullptr;
			}

			removed_node = node;

		} else if ( nullptr == node->left || nullptr == node->right ) {

			// Case #1

			TreeNode *child = nullptr == node->left ? node->right : node->left;

			if ( parent ) {
				if ( parent->left == node ) {
					parent->left = child;
				} else {
					parent->right = child;
				}
				removed_node = node;
			} else {
				removed_node = root;
				root = child;
			}

		} else if ( !( nullptr == node->left || nullptr == node->right ) ) {

			// Case #2

			TreeNode *xessor;
			TreeNode *xessor_parent;
			TreeNode *xessor_child;

			// Find in-order successor (i.e. left-most child of node's right subtree)
			// N.B. we're just choosing the successor every time, which will unbalance
			// a balanced tree, but it's simple. Self-balancing trees will use
			// more advanced strategies.
			for(
				xessor = node->right,
				xessor_parent = node
					;
				nullptr != xessor->left
					;
				xessor_parent = xessor,
					xessor = xessor->left
			);

			swap( xessor->val, node->val );

			xessor_child = nullptr == xessor->left ? xessor->right : xessor->left;
			if ( xessor_parent->left == xessor ) {
				xessor_parent->left = xessor_child;
			} else {
				xessor_parent->right = xessor_child;
			}

			removed_node = xessor;
		}

		if ( nullptr != removed_node ) {
			// don't leave any dangling pointers!
			removed_node->left = nullptr;
			removed_node->right = nullptr;

			// I'm not a big fan of the design of this problem.
			// It forces memory allocation *into* the node deletion
			// routine, where really, the node deletion should be done
			// *outside* of this function, if it needs to be done so at all.
			// Typically node removal methods return the node that is
			// removed, so the caller can free memory, *if* the caller needs to,
			// rather than the base of the tree again... which is almost
			// useless without a TreeNode **.
			delete removed_node;
		}

		return root;
	}

protected:
	void findNode( TreeNode *root, int key, TreeNode * & node, TreeNode * & parent ) {

		for( parent = nullptr, node = root;; ) {
			if ( nullptr == node ) {
				break;
			}

			if ( false ) {
			} else if ( key < node->val ) {
				parent = node;
				node = node->left;
			} else if ( key > node->val ) {
				parent = node;
				node = node->right;
			} else {

				break;
			}
		}
	}
};
