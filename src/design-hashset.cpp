/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <functional>
#include <utility>
#include <vector>

using namespace std;

class MyHashSet {
public:

	// https://leetcode.com/problems/design-hashset

	MyHashSet()
	: n_items( 0 ), buckets( bucket_block_size, nullptr )
	{
	}

	void add( int key ) {
		add( key, nullptr );
	}

	void remove( int key ) {

		if ( ! contains( key ) ) {
			return;
		}

		size_t hashed_key = hasher( key );
		uint32_t modded = hashed_key % buckets.size();

		bucket_list_node *b, *b_prev;
		for( b_prev = nullptr, b = buckets[ modded ]; nullptr != b && b->key != key; b_prev = b, b = b->next );
		if ( b ) {
			if ( ! b_prev ) {
				buckets[ modded ] = b->next;
			} else {
				b_prev->next = b->next;
			}
			delete b;
			n_items--;
			refactor( false );
		}
	}

	bool contains( int key ) {

		size_t hashed_key = hasher( key );
		uint32_t modded = hashed_key % buckets.size();

		bucket_list_node *b;

		for( b = buckets[ modded ]; nullptr != b && b->key != key; b = b->next );

		return nullptr != b;
	}

	vector<size_t> histogram() {

		vector<size_t> hist;

		for( size_t i = 0; i < buckets.size(); i++ ) {
			size_t j;
			bucket_list_node *b;
			for( b = buckets[ i ], j = 0; nullptr != b; b = b->next ) j++;
			hist.push_back( j );
		}

		return hist;
	}

protected:

	// We're going to use the approach that a hash table is an array of buckets
	// containing linked lists. There is a hash function that translates the key to
	// a hashed key, and then the hashed key will be used as an index to say which
	// bucket / linked-list we are going to add / remove / check for our value.
	//
	// A critical measure of the speed of a hash table / set is its load factor.
	// Which (I believe) is defined as the number of items in the set / the number of
	// buckets. IIRC, this should definitely be less than unity - I would say less
	// than 0.5 to be on the safe side.
	//
	// Each time our hash table / set grows to a high threshold load factor, we need to
	// increase its size. Certain sizes might increase collisions, but I'm going to
	// ignore that for the purpose of this implementation.
	//
	// We'll start out with an initial hash size of 64, and when resizing, we'll keep
	// adding blocks of 64 until our load factor hits a lower threshold.
	//
	// Let's make the high threshold load factor 0.5 and the low threshold load factor
	// 0.25.
	//
	// We should always be able to get a histogram of bucket list lengths too, which
	// will indicate how uniform our hashing algorithm is and how many collisions it
	// produces for a given number of buckets.

	static constexpr size_t bucket_block_size = 64;
	static constexpr float load_factor_low  = 0.1;
	static constexpr float load_factor_high = 0.5;

	static const function<size_t(int)> hasher;

	explicit MyHashSet( size_t n_buckets )
	: n_items( 0 ), buckets( n_buckets, nullptr )
	{
	}

	struct bucket_list_node {
		int key;
		size_t hashed_key;
		bucket_list_node *next;
		bucket_list_node() : bucket_list_node( 0 ) {}
		explicit bucket_list_node( int key ) : key( key ), hashed_key( hasher( key ) ), next( nullptr ) {}
	};

	size_t n_items;
	vector<bucket_list_node *> buckets;

	void add( int key, bucket_list_node *bucket ) {

		size_t hashed_key;
		if ( nullptr == bucket ) {
			hashed_key = hasher( key );
		} else {
			key = bucket->key;
			hashed_key = bucket->hashed_key;
		}

		uint32_t modded = hashed_key % buckets.size();

		if ( nullptr == buckets[ modded ] ) {

			if ( nullptr == bucket ) {
				buckets[ modded ] = new bucket_list_node( key );
			} else {
				buckets[ modded ] = bucket;
			}

			n_items++;

			refactor( true );

		} else {

			bucket_list_node *b;
			for( b = buckets[ modded ]; nullptr != b->next && b->key != key; b = b->next );

			if ( b->key == key ) {
				return;
			} else {
				if ( nullptr == bucket ) {
					b->next = new bucket_list_node( key );
				} else {
					b->next = bucket;
				}
			}

			n_items++;

			refactor( true );
		}
	}

	void addAll( size_t n_items, vector<bucket_list_node *> & buckets ) {
		for( size_t i = 0; i < buckets.size() && n_items > 0; i++ ) {
			vector<bucket_list_node *> stack;
			for( bucket_list_node *b = buckets[ i ]; b; b = b->next ) {
				stack.push_back( b );
			}
			for( auto & b: stack ) {
				b->next = nullptr;
				add( -1, b );
			}
		}
	}

	float loadFactor() {
		return loadFactor( n_items, buckets.size() );
	}

	static float loadFactor( size_t n_items, size_t n_buckets ) {
		return float( n_items ) / n_buckets;
	}

	void refactor( bool increased ) {

		size_t n_items = this->n_items;

		size_t n_buckets = buckets.size();

		float lf = loadFactor( n_items, n_buckets );

		if ( increased ) {
			if ( lf >= load_factor_high ) {
				for( ; lf >= ( load_factor_low + load_factor_high ) / 2; n_buckets += bucket_block_size, lf = loadFactor( n_items, n_buckets ) );

				MyHashSet new_bucket_list( n_buckets );
				new_bucket_list.addAll( n_items, buckets );

				buckets = new_bucket_list.buckets;
			}
		} else {
			if ( lf < load_factor_low ) {
				for( ; n_buckets > bucket_block_size && lf < ( load_factor_low + load_factor_high ) / 2; n_buckets -= bucket_block_size, lf = loadFactor( n_items, n_buckets ) );

				if ( 0 != n_buckets ) {
					MyHashSet new_bucket_list( n_buckets );
					new_bucket_list.addAll( n_items, buckets );

					buckets = new_bucket_list.buckets;
				}
			}
		}
	}
};

const function<size_t(int)> MyHashSet::hasher = hash<int>();
