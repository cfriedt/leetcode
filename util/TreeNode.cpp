#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <string>
#include <unordered_set>
#include <vector>

#include <gtest.h>

#include "split.hpp"

#include "TreeNode.hpp"

using namespace std;

// In the way that LeetCode represents trees as a string, it is
// read out much like a paragraph in most western languages;
// left to right, top to bottom.
//
// For an intermediate representation, it's sort of like 2D array,
// but with C++ we can achieve the same with approximately O( N )
// space by using a vector<vector<TreeNode *>>.
//
// We'll call that type TreeIR.
//
// When transforming from TreeNode * to TreeIR, it's important to
// detect cycles, so keep a cache of visited TreeNodes *'s in the
// form of unordered_set<TreeNode *>.
//
// We'll call that type NodeCache.
//
// When transforming from string to TreeIR, the links need to be
// populated, which makes going from TreeIR to TreeNode * practically a no-op.
//
// Using the semantics of an array, we can access individual TreeNode *'s as
// if they were on a grid of with H rows and W = 2^H columns.
//
// The exact row and column that each node occupies in the grid is a function
// of the node's depth in the graph, it's parent's column number, and
// whether or not the node is the left or right child.
//
//            a               [ a               ]
//      b          c       => [ b c             ]
//   d     e    f     g       [ d e f g         ]
//  h i   j k  l m   n o      [ h i j k l m n o ]
//
// #   | node  D   P C | (row,col)
// -------------------------------
// 0   | a     0   0 0 | (0,0)
//
// 1   | b     1   0 0 | (1,0)
// 2   | c     1   0 1 | (1,1)
//
// 3   | d     2   0 0 | (2,0)
// 4   | e     2   0 1 | (2,1)
// 5   | f     2   1 0 | (2,2)
// 6   | g     2   1 1 | (2,3)
//
// 7   | h     3   0 0 | (3,0)
// 8   | i     3   0 1 | (3,1)
// 9   | j     3   1 0 | (3,2)
// 10  | k     3   1 1 | (3,3)
// 11  | l     3   2 0 | (3,4)
// 12  | m     3   2 1 | (3,5)
// 13  | n     3   3 0 | (3,6)
// 14  | o     3   3 1 | (3,7)
//
// If we encode the depth as D, the parent's column as P, and
// C as 0 for left child, 1 for right child, then
// the row and column can be determined with the following formulas.
//
// row = D
// col = 2 * P + C
//
// For example, m:
// row = D = 3,
// col = 2 * P + C = 2 * 2 + 1 = 5
//
// For example, n:
// row = D = 3
// col = 2 * P + C = 2 * 3 + 0 = 6
//
// In fact, D, P, and C can all be deduced from the node's number (#).
//
// Let's encode the node's number with i, then
// D = floor( log2( i + 1 ) );
// P = ( (i + 1) / 2 ) % ( 1 << ( D - 1 ) );
// C = ( 0 == i ) ? 0 : ( i + 1 ) % 2;
//
// In LeetCode's representation, they also do not displace unnecessary
// nodes that are null. Only null nodes that have at least 1 non-null
// right sibling are encoded with the string "null".


using TreeIR = vector<vector<const TreeNode *>>;
using NodeCache = unordered_set<const TreeNode *>;

static void TreeNode_to_TreeIR( const size_t D, const size_t P, const size_t C, const TreeNode *node, TreeIR & ir, NodeCache & cache );
static TreeNode *TreeIR_to_TreeNode( TreeIR & ir );

static void string_to_TreeIR( const string & s, TreeIR & ir );
static string TreeIR_to_string( const TreeIR & ir );

static TreeNode *TreeIR_root( const TreeIR & ir );

bool TreeNode_string_is_valid( const string & s ) {
	(void)s;
	// TODO: implement me
	(void)s;
	return true;
}

bool TreeNode_is_valid( const TreeNode * root ) {
	(void) root;
	// TODO: implement me
	(void)root;
	return true;
}

string TreeNode_to_string( const TreeNode *root ) {

	TreeIR ir;
	NodeCache cache;

	TreeNode_to_TreeIR( 0, 0, 0, root, ir, cache );

	return TreeIR_to_string( ir );
}

TreeNode *TreeNode_from_string( const string & s ) {
	TreeIR ir;
	string_to_TreeIR( s, ir );
	return TreeIR_to_TreeNode( ir );
}

ostream & operator<<( ostream & os, const TreeNode * & root ) {
	string s = TreeNode_to_string( root );
	os << s;
	return os;
}

istream &operator>>( istream  & is, TreeNode * & root ) {
	(void)root;
	return is;
}

void TreeNode_cleanup( TreeNode * & node ) {

	// cleanup uses postorder traversal

	if ( nullptr == node ) {
		return;
	}

	TreeNode_cleanup( node->left );
	TreeNode_cleanup( node->right );

	delete node;
	node = nullptr;
}

size_t TreeNode_depth( TreeNode *node, size_t current_depth ) {

	if ( nullptr == node ) {
		return current_depth;
	}

	size_t ldepth = TreeNode_depth( node->left, current_depth );
	size_t rdepth = TreeNode_depth( node->right, current_depth );

	return max( ldepth, rdepth );
}

static void TreeNode_to_TreeIR( const size_t D, const size_t P, const size_t C, const TreeNode *node, TreeIR & ir, NodeCache & cache ) {

		if ( nullptr == node ) {
			return;
		}

		if ( cache.end() != cache.find( node ) ) {
			throw logic_error( "tree has cycles" );
		}

		size_t row = D;
		size_t col = 2 * P + C;

		TreeNode_to_TreeIR( D + 1, col, 0, node->left, ir, cache );

		cache.insert( node );
		if ( row >= ir.size() ) {
			ir.resize( row + 1 );
			ir[ row ] = vector<const TreeNode *>();
		}
		if ( col >= ir[ row ].size() ) {
			ir[ row ].resize( col + 1 );
		}
		ir[ row ][ col ] = node;

//		if ( 0 != D ) {
//			const TreeNode *parent = ir[ D - 1 ][ P ];
//			if ( 0 == C ) {
//				throw logic_error( "parent " + to_string( parent->val ) + " left child pointer is wrong" );
//			} else {
//				if ( parent->right != node ) {
//					throw logic_error( "parent " + to_string( parent->val ) + " right child pointer is wrong" );
//				}
//			}
//		}

		TreeNode_to_TreeIR( D + 1, col, 1, node->right, ir, cache );
}

static TreeNode *TreeIR_to_TreeNode( TreeIR & ir ) {
	return TreeIR_root( ir );
}

static void string_to_TreeIR( const string & s, TreeIR & ir ) {

	if ( s.empty() ) {
		throw invalid_argument("empty string. empty trees should be []");
	}

	if ( s.front() != '[' ) {
		throw invalid_argument("invalid starting character 0 '" + string( s.front(), 1 ) + "'");
	}

	if ( s.back() != ']' ) {
		throw invalid_argument("invalid ending character at " + to_string( s.length() - 1 ) + ", '" + string( s.back(), 1 ) + "'");
	}

	string _s = s.substr( 1, s.length() - 2 );
	replace( _s.begin(), _s.end(), ',', ' ' );

	vector<string> vals = split( _s );

	for( size_t i = 0; i < vals.size(); i++) {

		size_t D = size_t( ::floorf( ::log2f( float( i + 1 ) ) ) );
		size_t P = ( (i + 1) / 2 ) % ( 1 << ( D - 1 ) );
		size_t C = ( 0 == i ) ? 0 : ( i + 1 ) % 2;
		size_t row = D;
		size_t col = 2 * P + C;

		if ( row >= ir.size() ) {
			ir.resize( row + 1 );
		}
		if ( col >= ir[ row ].size() ) {
			ir[ row ].resize( col + 1 );
		}

		TreeNode *node =
			( "null" == vals[ i ] )
			? NULL
			: new TreeNode( stoi( vals[ i ] ) )
			;
		ir[ row ][ col ] = node;

		if ( 0 == i ) {
			if ( nullptr == node ) {
				throw logic_error( "an empty tree is specified with [], not with [null]" );
			}
		} else {
			TreeNode *parent = (TreeNode *)ir[ row - 1 ][ P ];
			for( ; nullptr == parent; ) {
				P++;
				parent = (TreeNode *)ir[ row - 1 ][ P ];
			}
			//TreeNode *parent = (TreeNode *)ir[ row - 1 ][ P ];
			//if ( nullptr == parent ) {
			//	continue;
			//	throw logic_error( "all nodes must have a non-null parent" );
			//}
			if ( C ) {
				parent->right = node;
			} else {
				parent->left = node;
			}
		}
	}
}

static string TreeIR_to_string( const TreeIR & ir ) {
	stringstream ss;

	ss << "[";

	size_t rows = ir.size();

	for( size_t row = 0; row < rows; row++ ) {

		size_t cols = ir[ row ].size();

		for( size_t col = 0; col < cols; col++ ) {

			const TreeNode *node = ir[ row ][ col ];
			if ( nullptr == node ) {
				ss << "null";
			} else {
				ss << to_string( node->val );
			}

			// unless it's the very last node, print a trailing ','
			if (
				! (
					true
					&& row == rows - 1
					&& col == cols - 1
				)
			) {
				ss << ",";
			}
		}
	}

	ss << "]";

	return ss.str();
}

static TreeNode *TreeIR_root( const TreeIR & ir ) {
	if ( ir.empty() ) {
		return nullptr;
	}
	if ( ir[ 0 ].empty() ) {
		throw logic_error("non-empty tree missing root element!!@!");
	}
	return (TreeNode *)ir[ 0 ][ 0 ];
}
