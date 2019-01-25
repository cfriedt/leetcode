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

#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:

	// https://leetcode.com/problems/find-duplicate-subtrees/


	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

		//
		// Assumptions:
		// - obviously not a binary search tree (there would be no identical subtrees)
		// - do not assume that the tree is balanced or partially complete or complete
		// - subtrees are only the proper subsets of the full tree
		// - integers can be any value in the range of all integers
		//   (cannot use a magic number to indicate null child, and therefore must use e.g. strings)
		//
		// Analysis:
		//
		// The brute force approach would
		// - find all tree nodes O( N ) + compare all of them with recursion O( N*N*N )
		// - ~ O( N^3 )
		//
		// We can do better by creating "signatures" for the subtrees that get updated
		// via backtracking, and then we can check each subtree's signature
		// using a hash table / hash set.
		//
		// The ideal way to do that would be crc32, but we can also rely on
		// string hashing in C++, for the purposes of this problem.
		//
		// Note, that these signatures are not proper serializations of the trees.
		// That is a whole other (hard) problem! https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
		//
		// So, the algorithm is:
		// * perform a pre-order traversal of the tree
		// * after traversal of a subtree combine the signatures
		//   of each subtree in pre-order format
		// * if the signature has not been seen before, add it to a hash map
		//   mapping it to the root of the subtree.
		// * if the signature has been seen before, check if we have already
		//   added the signature to a hash set of duplicate signatures.
		// * if the duplicate signature has not been seen already, add the
		//   node to the list of duplicates.
		//
		// Analysis of this method:
		// O( N ) time for traversal (every node is traversed at most once)
		// O( 1 ) time for performing checks on signatures
		// O( N ) space for signatures, hash map, and hash set
		//
		// Taking the example in question as a runthrough.
		//
		//      1
		//    2   3
		//  4    2  4
		//     4
		//
		// Let's label those nodes with an index in left to right / top to bottom
		// convention.
		//
		// i    subtrees    dups      comment
		// ----------------------------------
		// 0    {}           {}
		//                              .. skipping ahead until we have a leaf node
		// 3    {[4]}        {}
		// 1    {[2,4,#],[4]} {}          .. after backtracking 1 step
		//                              .. root node is not a proper subtree, so ignore
		// 6    {[2,4,#],[4]} {[4]}
		// 4    {[2,4,#],[4]} {[4],[2,4,#]} .. note that we are allowed to add either node pointer,
		//                                 and not the first encountered
		// 2    {[2,4,#],[4],[3,2,4,4,#]
		//
		// Linear time is pretty good, so let's assume that we can
		// go ahead and code this.

		if ( nullptr == root ) {
			return dups;
		}

		// use a helper function for the recursion
		helper( nullptr, root );

		return dups;
	}

	unordered_map<string,TreeNode*> subtrees;
	vector<TreeNode *> dups;
	unordered_set<string> dup_signatures;

	string helper( TreeNode * parent, TreeNode *node ) {

		string signature( to_string( node->val ) );

		if ( !( nullptr == node->left && nullptr == node->right ) ) {

			string lsignature;

			if ( nullptr == node->left ) {
				lsignature = ",#";
			} else {
				lsignature = "," + helper( node, node->left );
			}

			string rsignature;
			if ( nullptr == node->right ) {
				rsignature = ",#";
			} else {
				rsignature = "," + helper( node, node->right );
			}

			signature += lsignature;
			signature += rsignature;
		}

		if ( nullptr != parent ) {
			// only consider proper subtrees

			if ( subtrees.end() == subtrees.find( signature ) ) {
				subtrees[ signature ] = node;
			} else {

				if ( dup_signatures.end() == dup_signatures.find( signature ) ) {
					dup_signatures.insert( signature );
					dups.push_back( node );
				}
			}
		}

		return signature;
	}
};
