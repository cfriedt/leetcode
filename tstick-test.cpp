/*
 * Copyright (c) 2025 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "tstick.cpp"

constexpr uint32_t TICK_RATE(32768);
constexpr uint64_t NS_PER_SEC(1000000000);
constexpr uint64_t NS_PER_TICK(NS_PER_SEC / TICK_RATE);

TEST_F(Solution, test_tick_to_timespec) {
  timespec expected_ts;

  expected_ts = TS_NO_WAIT;
  EXPECT_EQ(expected_ts, tick_to_timespec(TICK_RATE, TICK_NO_WAIT));

  expected_ts = timespec{0, NS_PER_TICK};
  EXPECT_EQ(expected_ts, tick_to_timespec(TICK_RATE, 1));

  /* Note: 2 * NS_PER_TICK does not work here, since there are rounding errors! */
  expected_ts = timespec{0, muldiv(2, NS_PER_SEC, TICK_RATE) % NS_PER_SEC};
  EXPECT_EQ(expected_ts, tick_to_timespec(TICK_RATE, 2));

  expected_ts = timespec{TICK_MAX / TICK_RATE, 
                         muldiv(TICK_MAX, NS_PER_SEC, TICK_RATE) % NS_PER_SEC};
  EXPECT_EQ(expected_ts, tick_to_timespec(TICK_RATE, TICK_MAX));

  expected_ts = TS_FOREVER;
  EXPECT_EQ(expected_ts, tick_to_timespec(TICK_RATE, TICK_FOREVER));
}

TEST_F(Solution, test_timespec_to_tick) {
  bool exact;
  bool expected_exact;
  int64_t expected_tick;
  timespec input;

  expected_tick = TICK_NO_WAIT;
  expected_exact = true;
  exact = !expected_exact;
  EXPECT_EQ(expected_tick, timespec_to_tick(TICK_RATE, TS_NO_WAIT, &exact));
  EXPECT_EQ(expected_exact, exact);

  /* this is between TS_NO_WAIT and NS_PER_TICK, so it should get rounded up to 1 tick */
  input = timespec{0, 1};
  expected_tick = 1;
  expected_exact = false;
  exact = !expected_exact;
  EXPECT_EQ(expected_tick, timespec_to_tick(TICK_RATE, input, &exact));
  EXPECT_EQ(expected_exact, exact);

  input = timespec{0, NS_PER_TICK};
  expected_tick = 1;
  expected_exact = true;
  exact = !expected_exact;
  EXPECT_EQ(expected_tick, timespec_to_tick(TICK_RATE, input, &exact));
  EXPECT_EQ(expected_exact, exact);

  expected_tick = TICK_FOREVER;
  expected_exact = true;
  exact = !expected_exact;
  EXPECT_EQ(expected_tick, timespec_to_tick(TICK_RATE, TS_FOREVER, &exact));
  EXPECT_EQ(expected_exact, exact);

  expected_tick = TICK_FOREVER;
  expected_exact = true;
  exact = !expected_exact;
  EXPECT_EQ(expected_tick, timespec_to_tick(TICK_RATE, TS_FOREVER, &exact));
  EXPECT_EQ(expected_exact, exact);
}
