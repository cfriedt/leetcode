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
