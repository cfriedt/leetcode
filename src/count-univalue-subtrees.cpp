/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include "TreeNode.hpp"

using namespace std;

class Solution {
public:

	// https://leetcode.com/problems/count-univalue-subtrees/
    //
    // A uni-value subtree means all nodes of the subtree have the same value.
    //
    // E.g.
    // Input: root = [5,1,5,5,5,null,5]
    // Output: 4

    int countUnivalSubtrees(TreeNode* root) {

		/*
		 * Analysis
		 * --------
         *
         * My first instinct would be to approach this problem recursively,
         * although of course, all recursive problems can also be done
         * iteratively. It's just sometimes easier to formulate a solution
         * when using recursion.
         *
         * As pointed-out in the test cases, we have some boundary-cases and
         * just quick observations.
         * * an empty tree should return 0
         * * a tree with 1 node (a subtree with 0 children) should return 1
         * ** by extension, a tree with all unique nodes should return the number
         *    of all non-null leaf nodes
         * ** a full tree with all the same values should return the number of
         *    subtrees (i.e. the number of non-null nodes)
         * * a subtree must include all child nodes
         *
         * Let's take the example [a=5,b=1,c=5,d=5,e=5,f=null,g=5] => 4
         *
         * This is a post-order recursion
         *
         *         (a)
         *       /     \
         *    (b)       (c)
         *   /   \     /   \
         * (d)   (e) (f)   (g)
         *
         *
         * step   node  count val  lval   rval
         * 0      a       0    5    1      5
         * 1      b       0    1    5      5
         * 2      d       1    5    -      -
         * 3      e       1    5    -      -
         * 4      b       2    1    5      5
         * 5      c       0    5    -      5
         * 6      g       1    5    -      -
         * 7      c       2    5    -      5
         * 8      a       4    5    1      5
         *
         * Important note: I failed this on the first try because
         * I did not recognize that there were 2 pieces of information to
         * convey from each iteration of recurse:
         * 1) whether the subtree was unival or not
         * 2) the unival subtree count
         *
         * Time Complexity: 2 * N => O( N )
         * Space Complexity: O( 1 ) no additional memory was required
         */

        return recurse( root ).count;
	}

protected:

    struct ret_t {
        ret_t() : ret_t( false, 0 ) {}
        ret_t( bool is_unival, int count ) : is_unival( is_unival ), count( count ) {}
        bool is_unival;
        int count;
    };

    static ret_t recurse( TreeNode *node ) {
        int lval;
        int rval;
        ret_t lret;
        ret_t rret;
        ret_t r;

        if ( false ) {
        } else if ( ! node ) {

            // empty tree
            return ret_t( false, 0 );

        } else if ( node->left && node->right ) {

            lval = node->left->val;
            rval = node->right->val;

            ret_t lret = recurse( node->left );
            ret_t rret = recurse( node->right );

            r.is_unival = lret.is_unival && rret.is_unival && lval == rval && lval == node->val;
            r.count = lret.count + rret.count + ( r.is_unival ? 1 : 0 );

            return r;

        } else if ( node->left && ! node->right ) {

            lval = node->left->val;
            lret = recurse( node->left );

            r.is_unival = lret.is_unival && lval == node->val;
            r.count = lret.count + ( r.is_unival ? 1 : 0 );

            return r;

        } else if ( ! node->left && node->right ) {

            rval = node->right->val;
            rret = recurse( node->right );

            r.is_unival = rret.is_unival && rval == node->val;
            r.count = rret.count + ( r.is_unival ? 1 : 0 );

            return r;

        } else {

            // leaf node
            return ret_t( true, 1 );
        }
    }
};
