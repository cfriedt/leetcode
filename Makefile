# MIT License
#
# Copyright (c) 2018 Christopher Friedt
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

.PHONY: all clean check

CXX ?= $(CROSS_COMPILE)g++

CPPFLAGS = -I/usr/include/gtest
CXXFLAGS = -Wall -Werror -g -O0 -std=c++11

CPPSRC = $(shell find * -name '*-test.cpp')

EXE = $(CPPSRC:.cpp=)

all: check

%: %.cpp Makefile
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $< -lgtest -lgtest_main

clean:
	rm -f $(EXE)

check: $(EXE)
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
