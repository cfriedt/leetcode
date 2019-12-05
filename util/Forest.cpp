#include <sstream>

#include "Forest.hpp"
#include "TreeNode.cpp"

using namespace std;

vector<string> Forest_to_string( const vector<TreeNode *> &forest ) {
    vector<string> r;
    for( auto & root: forest ) {
        r.push_back( TreeNode_to_string( root ) );
    }
    return r;
}
void Forest_cleanup( vector<TreeNode*> & forest ) {
    for( auto & root: forest ) {
        TreeNode_cleanup( root );
    }
}
