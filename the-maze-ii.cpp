/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <algorithm>
#include <array>
#include <climits>
#include <functional>
#include <set>
#include <vector>

using namespace std;

//ostream & operator<<( ostream & os, const vector<int> & v ) {
//	os << "[";
//	for( size_t i = 0; i < v.size(); i++ ) {
//		os << v[i];
//		if ( i + 1 < v.size() ) {
//			os << ",";
//		}
//	}
//	os << "]";
//	return os;
//}

class Solution {
public:

	// https://leetcode.com/problems/the-maze-iii/


	// Analysis
	//
	// See analysis in the-maze.cpp

	enum {
		UP,
		RIGHT,
		DOWN,
		LEFT,
		NDIR
	};

	int shortestDistance( vector<vector<int>>& maze, vector<int> & start, vector<int> & destination ) {

		vector<vector<int>> cost( maze.size(), vector<int>( maze[0].size(), INT_MAX ));
		vector<vector<bool>> visited( maze.size(), vector<bool>( maze[0].size(), false ));

		struct Trajectory {
			int dir;
			vector<int> dest;
			Trajectory() : Trajectory( 0, vector<int>({0,0}) ) {}
			Trajectory( int dir, const vector<int> & dest ) : dir( dir ), dest( dest ) {}
		};

		auto is_gt = [&cost]( const Trajectory & a, const Trajectory & b ) -> bool {
			return costAt( cost, a.dest ) > costAt( cost, b.dest );
		};

		vector<Trajectory> q;

		vector<int> ball = start;

		//for( auto & v: maze ) {
		//	cerr << v << endl;
		//}
		//cerr << "ball: " << start << endl;
		//cerr << "hole: " << destination << endl;

		cost[ start[ 0 ] ][ start[ 1 ] ] = 0;
		q.push_back( Trajectory( NDIR, ball ) );
		push_heap( q.begin(), q.end(), is_gt );

		for( ; ! q.empty() ; ) {

			Trajectory t = q.front();
			int prev_dir = t.dir;
			ball = t.dest;

			//cerr << ball << endl;

			pop_heap( q.begin(), q.end(), is_gt );

			q.pop_back();

			markVisited( ball, visited );

			for( auto dir: vector<int>{ UP, RIGHT, DOWN, LEFT } ) {

				if ( oppositeDir( dir ) == prev_dir ) {
					continue;
				}

				vector<int> dest(2,-1);
				if ( exploreInOneDirection( maze, visited, ball, destination, dir, dest, cost ) ) {
					q.push_back( Trajectory( dir, dest ) );
					push_heap( q.begin(), q.end(), is_gt );
				}
			}
		}

		int shortest = costAt( cost, destination );

		if ( INT_MAX == shortest ) {
			return -1;
		} else {
			return shortest;
		}
	}

protected:

	static inline void markVisited( const vector<int> & ball, vector<vector<bool>> & visited ) {
		visited[ ball[ 0 ] ][ ball[ 1 ] ] = true;
	}

	static inline int nextRow( int dir, int row ) {
		switch( dir ) {
		case UP:   return row-1;
		case DOWN: return row+1;
		default: return row;
		}
	}

	static inline int nextCol( int dir, int col ) {
		switch( dir ) {
		case LEFT:  return col-1;
		case RIGHT: return col+1;
		default: return col;
		}
	}

	static inline bool updateCost( const vector<int> & dest, const vector<int> & ball, const int & n, vector<vector<int>> & cost ) {
		//if ( cost[ ball[ 0 ] ][ ball[ 1 ] ] + n <= cost[ dest[ 0 ] ][ dest[ 1 ] ] ) {
			cost[ dest[ 0 ] ][ dest[ 1 ] ] = cost[ ball[ 0 ] ][ ball[ 1 ] ] + n;
			return true;
		//}
		//return false;
	}

	static bool exploreInOneDirection( const vector<vector<int>> & maze, const vector<vector<bool>> & visited, const vector<int> & ball, const vector<int> & hole, const int dir, vector<int> & dest, vector<vector<int>> & cost ) {
		int n;
		int row, col;

		(void)visited;
		(void)hole;

		for(
			n = 0,
				row = ball[ 0 ],
				col = ball[ 1 ]
				;
			! isWall( maze, nextRow( dir, row ), nextCol( dir, col ) )
				;
			n++,
				row = nextRow( dir, row ),
				col = nextCol( dir, col )
		);
		if ( n != 0 ) {

			if ( costAt( cost, ball ) + n >= costAt( cost, vector<int>({row,col}) ) ) {
				return false;
			}

			dest[ 0 ] = row;
			dest[ 1 ] = col;
			return updateCost( dest, ball, n, cost );
		}

		return false;
	}

	static inline bool isWall( const vector<vector<int>> & maze, int row, int col ) {
		if ( row < 0 || size_t( row ) >= maze.size() ) {
			return true;
		}
		if ( col < 0 || size_t( col ) >= maze[ 0 ].size() ) {
			return true;
		}
		return maze[ row ][ col ];
	}

	static inline bool isVisited( const vector<vector<bool>> & visited, int row, int col ) {
//		if ( row < 0 || size_t( row ) >= visited.size() ) {
//			return false;
//		}
//		if ( col < 0 || size_t( col ) >= visited[ 0 ].size() ) {
//			return false;
//		}
		return visited[ row ][ col ];
	}

	static int costAt( const vector<vector<int>> & cost, const vector<int> & coord ) {
		return cost[ coord[ 0 ] ][ coord[ 1 ] ];
	}

	static inline int oppositeDir( int dir ) {
		static const array<int,NDIR+1> lut{{
			DOWN,
			LEFT,
			UP,
			RIGHT,
			-1,
		}};
		int r = lut[ dir ];
		return r;
	}

};
