/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

// clang-format off
// name: insert-delete-getrandom-o1-duplicates-allowed
// url: https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed
// difficulty: 3
// clang-format on

#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class RandomizedCollection {
public:
  RandomizedCollection() {}

  /** Inserts a value to the collection. Returns true if the collection did not
   * already contain the specified element. */
  bool insert(int val) {

    auto it = index.find(val);
    bool unique;

    if (index.end() == it) {
      unique = true;
    } else {
      unique = false;
    }

    elements.push_back(val);
    index[val].insert(elements.size() - 1);

    return unique;
  }

  /** Removes a value from the collection. Returns true if the collection
   * contained the specified element. */
  bool remove(int val) {

    auto it = index.find(val);
    if (index.end() == it) {
      return false;
    }

    int val_idx = *(it->second.begin());

    // val2 is whatever is at the back / tail of elements
    int val2_idx = elements.size() - 1;
    int val2 = elements[val2_idx];

    if (val2_idx == val_idx) {
      // element is already at the back, so just
      // pop it out and erase the back index
      // O(1)
      elements.pop_back();
      // O(1)*O(1) = O(1)
      index[val].erase(val_idx);
      if (index[val].empty()) {
        index.erase(val);
      }
      return true;
    }

    // swap values at the two indeces
    swap(elements[val_idx], elements[val2_idx]);
    // get rid of val
    elements.pop_back();
    index[val].erase(val_idx);
    if (index[val].empty()) {
      index.erase(val);
    }

    // update the index of the val2 instance that moved
    index[val2].erase(val2_idx);
    index[val2].insert(val_idx);

    return true;
  }

  /** Get a random element from the collection. */
  int getRandom() {
    long pos = ::random() % elements.size();
    return elements[pos];
  }

protected:
  vector<int> elements;

  // key is the "value" to be added / removed from the collection
  // value is an set of indices where "value" is found in elements
  unordered_map<int, unordered_set<int>> index;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
