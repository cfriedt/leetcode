/*
 * Copyright (c) 2025 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <cstdint>
#include <ctime>
#include <limits>

#include <gtest/gtest.h>

using namespace std;

static inline bool operator==(timespec const& lhs, timespec const& rhs)
{
    return lhs.tv_sec == rhs.tv_sec && lhs.tv_nsec == rhs.tv_nsec;
}

static inline bool operator<(timespec const &lhs, timespec const &rhs) {
  return (lhs.tv_sec < rhs.tv_sec) ||
         (lhs.tv_sec == rhs.tv_sec && lhs.tv_nsec < rhs.tv_nsec);
}

static inline bool operator>(timespec const &lhs, timespec const &rhs) {
  return (lhs.tv_sec > rhs.tv_sec) ||
         (lhs.tv_sec == rhs.tv_sec && lhs.tv_nsec > rhs.tv_nsec);
}

static inline bool operator<=(timespec const &lhs, timespec const &rhs) {
  return (lhs < rhs) || (lhs == rhs);
}

static inline bool operator>=(timespec const &lhs, timespec const &rhs) {
  return (lhs > rhs) || (lhs == rhs);
}

static inline constexpr uint64_t muldiv(uint64_t a, uint64_t b, uint64_t c) {
    return (a * b) / c;
}

class Solution : public ::testing::Test {
public:
  // this is not a leetcode problem

  static constexpr uint64_t NS_PER_SEC = 1000000000;
  static constexpr int64_t TICK_NO_WAIT = 0;
  static constexpr int64_t TICK_FOREVER = -1;
  static constexpr int64_t TICK_MAX = numeric_limits<int64_t>::max();
  static constexpr timespec TS_NO_WAIT = {0, 0};
  static constexpr timespec TS_FOREVER = {INT64_MAX, 999999999L};

  timespec tick_to_timespec(uint32_t tick_rate, int64_t tick);
  int64_t timespec_to_tick(uint32_t tick_rate, const timespec &ts, bool *exact = nullptr);
};

timespec Solution::tick_to_timespec(uint32_t tick_rate, int64_t tick) {
  assert(tick_rate > 0);
  assert(tick >= -1);

  if (tick == TICK_NO_WAIT) {
    return TS_NO_WAIT;
  }

  if (tick == TICK_FOREVER) {
    return TS_FOREVER;
  }

  auto sec = tick / tick_rate;
  auto nsec = muldiv(tick, NS_PER_SEC, tick_rate) % NS_PER_SEC;

  return timespec{.tv_sec = (time_t)sec, .tv_nsec = (long)nsec};
}

int64_t Solution::timespec_to_tick(uint32_t tick_rate, const timespec &ts, bool *exact)
{
  assert(tick_rate > 0);

  int64_t tick = INT64_MIN;
  timespec TS_1_TICK = {0, (long)NS_PER_SEC / tick_rate};
  timespec TS_MAX = {(time_t)((uint64_t)TICK_MAX / tick_rate), (long)(muldiv(TICK_MAX, NS_PER_SEC, tick_rate) % NS_PER_SEC)};

  if (ts <= TS_NO_WAIT) {
    tick = TICK_NO_WAIT;
  } else if (ts == TS_FOREVER) {
    tick = TICK_FOREVER;
  } else if (ts <= TS_1_TICK) {
    tick = 1;
  } else if (ts >= TS_MAX) {
    tick = TICK_MAX;
  } else {
    tick = (uint64_t)ts.tv_sec * tick_rate + (uint64_t)ts.tv_nsec * tick_rate / NS_PER_SEC;
  }

  if (exact) {
    timespec ts_check = tick_to_timespec(tick_rate, tick);
    *exact = (ts_check == ts);
  }
  
  return tick;
}
