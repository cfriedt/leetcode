#include <algorithm>
#include <sstream>
#include <vector>

#include "ListNode.hpp"
#include "split.hpp"

using namespace std;

ListNode *ListNode_from_string( const string & s ) {

	ListNode head(-1);
	ListNode *it;

	string _s( s );

	replace( _s.begin(), _s.end(), '-', ' ' );
	replace( _s.begin(), _s.end(), '>', ' ' );

	vector<string> elements = split( _s );

	it = & head;
	for( auto & e: elements ) {
		it->next = new ListNode( stoi( e ) );
		it = it->next;
	}

	return head.next;
}

string ListNode_to_string( ListNode *head ) {
	stringstream ss;
	ListNode *it;
	for( it =  head;; it = it->next ) {
		ss << it->val;
		if ( nullptr == it->next ) {
			break;
		}
		ss << "->";
	}
	return ss.str();
}

void ListNode_cleanup( ListNode **head ) {

	if ( nullptr == head || nullptr == *head ) {
		return;
	}

	ListNode *it = *head;

	ListNode_cleanup( & it->next );

	delete it;

	*head = nullptr;
}
