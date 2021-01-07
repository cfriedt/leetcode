# Copyright (c) 2018 Christopher Friedt
#
# SPDX-License-Identifier: MIT

.PHONY: all clean check gtest gcov clangtidy

CXX ?= $(CROSS_COMPILE)g++
#CXX := clang++

CPPFLAGS :=
CXXFLAGS :=
LDFLAGS :=
LDLIBS :=
GCOVFLAGS :=
GCOVRFLAGS :=
CTIDYFLAGS :=

CXXFLAGS += -Wall -Werror -Wextra -g -O0 -std=c++14

# gcov
CXXFLAGS += -fprofile-arcs -ftest-coverage
GCOVFLAGS += -r
GCOVRFLAGS += -r $(shell pwd) -e '.*-test.cpp' -e 'util/'

CPPFLAGS += $(shell pkg-config --cflags gtest)
LDLIBS += $(shell pkg-config --libs gtest_main)

CPPFLAGS += -Iutil

CTIDYCHECKS :=
CTIDYCHECKS += clang-analyzer-core*
CTIDYCHECKS += clang-analyzer-security*
CTIDYCHECKS += clang-analyzer-unix*
CTIDYCHECKS += clang-analyzer-valist*
CTIDYCHECKS += clang-analyzer-optin.cplusplus*
CTIDYCHECKS += clang-analyzer-optin.portability*
CTIDYCHECKS += clang-analyzer-nullability*
CTIDYCHECKS += clang-analyzer-deadcode*
CTIDYCHECKS += clang-analyzer-cplusplus*
NOTHING :=
SPACE := $(NOTHING) $(NOTHING)
COMMA := ,
CTIDYCHECKLIST := $(subst $(SPACE),$(COMMA),$(strip $(CTIDYCHECKS)))

CTIDYFLAGS += -header-filter='.*'
CTIDYFLAGS += -checks='$(CTIDYCHECKLIST)'
CTIDYFLAGS += -warnings-as-errors='$(CTIDYCHECKLIST)'

CPPSRC = $(shell ls *-test.cpp)

EXE = $(CPPSRC:.cpp=)

all: $(EXE)

%-test: %-test.cpp %.cpp Makefile
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $< $(LDLIBS)

clean:
	rm -f $(EXE) *-test *.gcno *.gcov *.gcda *.clangtidy

check:
	$(MAKE) gtest
	$(MAKE) gcov
	$(MAKE) clangtidy

gtest: $(EXE)
	NTEST=0; \
	NPASS=0; \
	if [ -z "$(strip $(EXE))" ]; then \
		exit 0; \
	fi; \
	for i in $(EXE); do \
		./$$i; \
		if [ $$? -eq 0 ]; then \
			NPASS=$$((NPASS+1)); \
		fi; \
		NTEST=$$((NTEST+1)); \
	done; \
	if [ $$NPASS -eq $$NTEST ]; then \
		exit 0; \
	else \
		exit 1; \
	fi

gcov: $(EXE)
	if [ -z "$(strip $(EXE))" ]; then \
		exit 0; \
	fi; \
	for i in $(EXE); do \
		gcov $(GCOVFLAGS) $${i}.cpp &> /dev/null; \
	done; \
	gcovr $(GCOVRFLAGS); \
	PCNT=`gcovr $(GCOVRFLAGS) | grep "^TOTAL" | tail -n 1 | awk '{print $$4}' | sed -e 's|%||'`; \
	if [ $${PCNT} -lt 90 ]; then \
		exit 1; \
	fi

%.clangtidy: %.cpp
	clang-tidy $(CTIDYFLAGS) $< -- $(CPPFLAGS) $(CXXFLAGS) &> $@ || cat $@

clangtidy: $(addsuffix .clangtidy,$(EXE))
