/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <unordered_set>
#include <vector>

using namespace std;

// https://leetcode.com/problems/delete-nodes-and-return-forest/

class Solution {

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& _to_delete) {

        vector<TreeNode*> roots;

        unordered_set<int> to_delete;
        for( auto & d: _to_delete ) {
            to_delete.insert( d );
        }

        delNodesHelper( to_delete, roots, root, nullptr );

        return roots;
    }

protected:
    void delNodesHelper( const unordered_set<int> & to_delete, vector<TreeNode*> & roots, TreeNode *node, TreeNode *parent ) {
        if ( nullptr == node ) {
            return;
        }

        delNodesHelper( to_delete, roots, node->left, node );
        delNodesHelper( to_delete, roots, node->right, node );

        bool deleted = to_delete.end() != to_delete.find( node->val );

        if ( deleted ) {

            // clear this node's pointer from the parent node
            if ( nullptr != parent ) {
                if ( parent->left == node ) {
                    parent->left = nullptr;
                } else {
                    parent->right = nullptr;
                }
            }

            if ( nullptr != node->left ) {
                roots.push_back( node->left );
                node->left = nullptr;
            }

            if ( nullptr != node->right ) {
                roots.push_back( node->right );
                node->right = nullptr;
            }

            return;
        }

        if ( nullptr == parent ) {
            // this is the root node and it hasn't been deleted
            roots.push_back( node );
        }
    }
};
