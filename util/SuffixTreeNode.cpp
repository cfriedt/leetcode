#include <string>

#include "SuffixTreeNode.hpp"

using namespace std;

void SuffixTreeNode_cleanup( SuffixTreeNode **root ) {
	if ( nullptr == root || nullptr == *root ) {
		return;
	}

	for( auto & kv: (*root)->child ) {
		SuffixTreeNode_cleanup( & kv.second );
	}

	*root = nullptr;
}

static void SuffixTreeNode_to_string_helper( string & out, SuffixTreeNode *root ) {
	if ( nullptr == root ) {
		return;
	}

	out += "{";
	if ( root->child.empty() ) {
		out += std::to_string( root->leaf_number );
	} else {
		size_t i = 0;
		size_t n = root->child.size();
		for( auto & kv: root->child ) {
			string label = kv.first;
			SuffixTreeNode_to_string_helper( out, kv.second );
			if ( i + 1 < n ) {
				out += ",";
			}
			i++;
		}
	}
	out += "}";
}

string SuffixTreeNode_to_string( SuffixTreeNode *root ) {
	string out;
	SuffixTreeNode_to_string_helper( out, root );
	return out;
}

