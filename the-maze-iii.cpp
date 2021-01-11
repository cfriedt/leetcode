/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <algorithm>
#include <array>
#include <climits>
#include <set>
#include <vector>

using namespace std;

// ostream & operator<<( ostream & os, const vector<int> & v ) {
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

  string findShortestWay(vector<vector<int>> &maze, vector<int> &ball,
                         vector<int> &hole) {

    vector<vector<int>> cost(maze.size(), vector<int>(maze[0].size(), INT_MAX));
    vector<vector<bool>> visited(maze.size(),
                                 vector<bool>(maze[0].size(), false));

    cost[ball[0]][ball[1]] = 0;

    //		for( auto & line: maze ) {
    //			cerr << line << endl;
    //		}

    //		cerr << "ball (" << ball[ 0 ] << "," << ball[ 1 ] << ")" <<
    // endl; 		cerr << "hole (" << hole[ 0 ] << "," << hole[ 1 ] << ")"
    // << endl;

    string shortest;
    helper(maze, ball, hole, NDIR, visited, cost, "", shortest);

    if ("" == shortest) {
      return "impossible";
    } else {
      return compress(shortest);
    }
  }

protected:
  enum { UP, RIGHT, DOWN, LEFT, NDIR };

  void helper(const vector<vector<int>> &maze, const vector<int> &ball,
              const vector<int> &hole, int prev_dir,
              vector<vector<bool>> &visited, vector<vector<int>> &cost,
              string path, string &shortest) {

    // cerr << "(" << ball[ 0 ] << "," << ball[ 1 ] << ") path " << path <<
    // endl;

    if (ball == hole) {

      if ("" == shortest) {
        //				cerr
        //					<< "path " << path << " (" <<
        // path.size() << ") beats" << endl
        //					<< "shortest " << shortest << "
        //("
        //<< shortest.size() << ")" << endl
        //					;
        shortest = path;
        return;
      }

      if (path.size() < shortest.size()) {
        //				cerr
        //					<< "path     " << path << " ("
        //<< path.size() << ") beats" << endl
        //					<< "shortest " << shortest << "
        //("
        //<< shortest.size() << ")" << endl
        //					;
        shortest = path;
      } else if (path.size() == shortest.size() && path < shortest) {
        //				cerr
        //					<< "path     " << path << " ("
        //<< path.size() << ") beats" << endl
        //					<< "shortest " << shortest << "
        //("
        //<< shortest.size() << ")" << endl
        //					;
        shortest = path;
      }
      return;
    }

    struct EdgeData {
      int cumulative_cost;
      int edge_cost;
      int dir;
      vector<int> dest;
      EdgeData() : EdgeData(0, 0, -1, vector<int>()) {}
      EdgeData(int cumulative_cost, int edge_cost, int dir,
               const vector<int> &dest)
          : cumulative_cost(cumulative_cost), edge_cost(edge_cost), dir(dir),
            dest(dest) {}
    };

    struct is_gt {
      bool operator()(const EdgeData &a, const EdgeData &b) {
        return a.cumulative_cost > b.cumulative_cost;
      }
    };

    vector<EdgeData> q;

    vector<int> dest = ball; // location of next cell (typically against a wall,
                             // or over the hole)

    for (auto dir : vector<int>({UP, RIGHT, DOWN, LEFT})) {

      if (oppositeDir(prev_dir) == dir) {
        continue;
      }

      if (exploreInOneDirection(maze, visited, ball, hole, dir, dest, cost)) {
        EdgeData ed(costAt(cost, dest), costAt(cost, dest) - costAt(cost, ball),
                    dir, dest);
        q.push_back(ed);
        push_heap(q.begin(), q.end(), is_gt());
      }
    }

    markVisited(ball, visited);

    for (; !q.empty();) {

      EdgeData e = q.front();
      pop_heap(q.begin(), q.end(), is_gt());
      q.pop_back();

      helper(maze, e.dest, hole, e.dir, visited, cost,
             path + string(e.edge_cost, dirToChar(e.dir)), shortest);
    }
  }

  static inline void markVisited(const vector<int> &ball,
                                 vector<vector<bool>> &visited) {
    visited[ball[0]][ball[1]] = true;
  }

  static inline int nextRow(int dir, int row) {
    switch (dir) {
    case UP:
      return row - 1;
    case DOWN:
      return row + 1;
    default:
      return row;
    }
  }

  static inline int nextCol(int dir, int col) {
    switch (dir) {
    case LEFT:
      return col - 1;
    case RIGHT:
      return col + 1;
    default:
      return col;
    }
  }

  static inline bool updateCost(const vector<int> &dest,
                                const vector<int> &ball, const int &n,
                                vector<vector<int>> &cost) {
    if (cost[ball[0]][ball[1]] + n <= cost[dest[0]][dest[1]]) {
      cost[dest[0]][dest[1]] = cost[ball[0]][ball[1]] + n;
      return true;
    }
    return false;
  }

  static bool exploreInOneDirection(const vector<vector<int>> &maze,
                                    const vector<vector<bool>> &visited,
                                    const vector<int> &ball,
                                    const vector<int> &hole, const int dir,
                                    vector<int> &dest,
                                    vector<vector<int>> &cost) {
    int n;
    int row, col;

    for (n = 0, row = ball[0], col = ball[1];
         !isWall(maze, nextRow(dir, row), nextCol(dir, col));
         n++, row = nextRow(dir, row), col = nextCol(dir, col)) {
      // this lets us fall in the hole if we roll over it
      if (isHole(row, col, hole)) {
        break;
      }

      if (isVisited(visited, row, col)) {
        if (costAt(cost, ball) + n <= costAt(cost, vector<int>({row, col}))) {
          continue;
        }
        return false;
      }
    }
    if (n != 0) {
      dest[0] = row;
      dest[1] = col;
      return updateCost(dest, ball, n, cost);
    }

    return false;
  }

  static inline bool isWall(const vector<vector<int>> &maze, int row, int col) {
    if (row < 0 || size_t(row) >= maze.size()) {
      return true;
    }
    if (col < 0 || size_t(col) >= maze[0].size()) {
      return true;
    }
    return maze[row][col];
  }

  static inline bool isVisited(const vector<vector<bool>> &visited, int row,
                               int col) {
    //		if ( row < 0 || size_t( row ) >= visited.size() ) {
    //			return false;
    //		}
    //		if ( col < 0 || size_t( col ) >= visited[ 0 ].size() ) {
    //			return false;
    //		}
    return visited[row][col];
  }

  static inline bool isHole(const int row, const int col,
                            const vector<int> &hole) {
    vector<int> ball({row, col});
    return ball == hole;
  }

  static int costAt(const vector<vector<int>> &cost, const vector<int> &coord) {
    return cost[coord[0]][coord[1]];
  }

  static inline char dirToChar(int dir) {
    static const array<char, NDIR> lut{{
        'u',
        'r',
        'd',
        'l',
    }};
    return lut[dir];
  }
  static inline int oppositeDir(int dir) {
    static const array<int, NDIR + 1> lut{{
        DOWN,
        LEFT,
        UP,
        RIGHT,
        -1,
    }};
    int r = lut[dir];
    if (-1 == r) {
      r++;
      r--;
    }
    return r;
  }

  static string compress(const string &s) {
    string r;
    r += s[0];
    for (size_t i = 1; i < s.size(); i++) {
      if (s[i] != s[i - 1]) {
        r += s[i];
      }
    }
    return r;
  }
};
