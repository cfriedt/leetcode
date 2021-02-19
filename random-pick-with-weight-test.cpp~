/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <unordered_map>

#include <gtest/gtest.h>

#include "random-pick-with-weight.cpp"

TEST(RandomPickWithWeight, Test_nil) {
  vector<int> w;
  Solution soln(w);
  int expected_int = 0;
  int actual_int = soln.pickIndex();
  EXPECT_EQ(actual_int, expected_int);
}

TEST(RandomPickWithWeight, Test_1) {
  vector<int> w({1});
  Solution soln(w);
  int expected_int = 0;
  int actual_int = soln.pickIndex();
  EXPECT_EQ(actual_int, expected_int);
}

TEST(RandomPickWithWeight, Test_1000000) {
  vector<int> w({1000000});
  Solution soln(w);
  int expected_int = 0;
  int actual_int = soln.pickIndex();
  EXPECT_EQ(actual_int, expected_int);
}

TEST(RandomPickWithWeight, Test_1_3_1) {
  vector<int> w({1, 3, 1});
  Solution soln(w);

  size_t n1s = 0;
  for (size_t i = 0; i < 5; i++) {
    size_t idx = soln.pickIndex();
    if (1 == idx) {
      n1s++;
    }
  }

  EXPECT_GT(n1s, 0);
}

vector<float> createHistogram(const vector<int> &w) {
  vector<float> chist(w.size());
  size_t sum_of_weights = accumulate(w.begin(), w.end(), 0);
  float cumulative;
  size_t i;
  for (cumulative = 0, i = 0; i < w.size(); i++) {
    float pcnt = float(w[i]) / float(sum_of_weights);
    cumulative += pcnt;
    chist[i] = cumulative;
  }
  return chist;
}

vector<float> createHistogram(const size_t expected_size,
                              const unordered_map<size_t, size_t> &results) {
  vector<float> chist(expected_size, 0.0);

  size_t samples = 0;
  for (auto &kv : results) {
    samples += kv.second;
  }

  float cumulative = 0;
  for (size_t i = 0; i < chist.size(); i++) {
    size_t n;
    if (0 == results.count(i)) {
      n = 0;
    } else {
      n = results.at(i);
    }

    float pcnt = float(n) / float(samples);
    cumulative += pcnt;
    chist[i] = cumulative;
  }
  return chist;
}

TEST(RandomPickWithWeight, Test_w_size_10000_with_elements_le_10000) {
  vector<int> w;
  for (size_t i = 0; i < 1000; i++) {
    for (size_t j = 0; j < 10; j++) {
      w.push_back(j * 1000);
    }
  }
  Solution soln(w);

  vector<float> expected_chist = createHistogram(w);

  unordered_map<size_t, size_t> results;
  for (size_t i = 0; i < 10000; i++) {
    int index = soln.pickIndex();
    ASSERT_GE(index, 0);
    ASSERT_LT(index, w.size());
    results[index]++;
  }

  vector<float> actual_chist = createHistogram(w.size(), results);

  // this would be a nice-to-have
  // EXPECT_NEAR( actual_chist, expected_chist, 0.001 );

  for (size_t i = 0; i < w.size(); i++) {
    EXPECT_NEAR(actual_chist[i], expected_chist[i], 0.01);
  }
}
