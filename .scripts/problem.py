#!/usr/bin/env python3

# Copyright (c) 2021, Christopher Friedt
#
# SPDX-License-Identifier: MIT

from datetime import datetime
import enum
import os
import re
import sys
import types


LEETCODE_URL_BASE = 'https://leetcode.com/problems'
GITHUB_URL_BASE = 'https://github.com/cfriedt/leetcode'
SPDX_LICENSE_IDENTIFIER = 'MIT'
COPYRIGHT_HOLDER = 'Christopher Friedt'

NAME_RE = re.compile(r'^[A-Za-z0-9][A-Za-z0-9-]*[A-Za-z0-9]+$')


class Difficulty(enum.IntEnum):
    INVALID = 0
    EASY = 1
    MEDIUM = 2
    HARD = 3


class Problem(object):

    @staticmethod
    def to_camel(name):
        # converts e.g. 3sum to 3Sum, n-queens-ii to NQueensIi
        prev = '-'
        camel = ''

        for i in range(len(name)):
            c = name[i]
            if c != '-':
                if (prev == '-' or prev.isnumeric() or i == 0) and c.isalpha():
                    c = c.upper()
                camel += c
            prev = c

        return camel

    def is_name_valid(name):
        return re.match(NAME_RE, name)

    @staticmethod
    def default_args():
        args = types.SimpleNamespace()
        args.verbose = False
        args.name = ''
        args.issue = -1
        args.problem_template = ''
        args.difficulty = Difficulty.INVALID
        args.time = -1  # ms
        args.time_rank = -1  # %
        args.time_complexity = ''  # O(...)
        args.space = -1  # MB
        args.space_rank = -1  # %
        args.space_complexity = ''  # O(...)
        return args

    def D(self, msg):
        if self._verbose:
            print(msg)

    def __init__(self, args):
        self._verbose = args.verbose
        if args.verbose is not True and args.verbose is not False:
            raise ValueError('invalid verbosity "{}"'.format(args.verbose))

        self._name = args.name
        if not Problem.is_name_valid(args.name):
            raise ValueError('invalid name "{}"'.format(args.name))

        self._camel = Problem.to_camel(self._name)

        # leetcode attributes
        self._url = '{}/{}'.format(LEETCODE_URL_BASE, args.name)

        # github attributes
        self._issue = args.issue

        # problem attributes
        # self._leetcode_number = -1
        self._problem_template = args.problem_template

        self._difficulty = args.difficulty

        self._time = args.time  # ms
        self._time_rank = args.time_rank  # %
        self._time_complexity = args.time_complexity  # O(...)

        self._space = args.space  # MB
        self._space_rank = args.space_rank  # %
        self._space_complexity = args.space_complexity  # O(...)

    # would be ideal to provie an init_from_url() method
    # but leetcode's page is mostly populated via async JS
    # which makes scraping (without heavyweight frameworks)
    # kind of difficult
    # def init_from_url(self):
    #    pass

    def create_impl_and_test(self):
        impl_cpp = self._name + '.cpp'
        test_cpp = self._name + '-test.cpp'

        year = datetime.today().year
        try:
            if os.path.exists(impl_cpp):
                raise ValueError(
                    'file {} already exists'.format(impl_cpp))

            if os.path.exists(test_cpp):
                raise ValueError('file {} already exists'.format(test_cpp))

            # create the implementation
            with open(impl_cpp, 'x') as f:
                self.D('opened {} as {}'.format(impl_cpp, f))

                # write the copyright and license info in SPDX format
                f.write('/*\n')
                f.write(' * Copyright (c) {}, {}\n'.format(year, COPYRIGHT_HOLDER))
                f.write(' *\n')
                f.write(
                    ' * SPDX-License-Identifier: {}\n'.format(SPDX_LICENSE_IDENTIFIER))
                f.write(' */\n')
                f.write('\n')

                # boilerplate C++
                f.write('#include <vector>\n'.format(self._name))
                f.write('\n')
                f.write('using namespace std;\n'.format(self._url))
                f.write('\n')

                # write problem metadata
                f.write('// name: {}\n'.format(self._name))
                f.write('// url: {}\n'.format(self._url))
                f.write('// difficulty: {}\n'.format(self._difficulty))
                f.write('\n')

                # write the problem template
                f.write(self._problem_template + '\n')

            self.D('created file {}'.format(impl_cpp))

            # create the test
            with open(test_cpp, 'x') as f:
                self.D('opened {} as {}'.format(test_cpp, f))

                # write the copyright and license info in SPDX format
                f.write('/*\n')
                f.write(' * Copyright (c) {}, {}\n'.format(year, COPYRIGHT_HOLDER))
                f.write(' *\n')
                f.write(
                    ' * SPDX-License-Identifier: {}\n'.format(SPDX_LICENSE_IDENTIFIER))
                f.write(' */\n')
                f.write('\n')

                # include gtest
                f.write('#include <gtest/gtest.h>\n'.format(self._name))
                f.write('\n')

                # include impl
                f.write('#include "{}.cpp"\n'.format(self._name))
                f.write('\n')

                # boilerplate C++
                f.write('using namespace std;\n'.format(self._url))
                f.write('\n')

                # trivial test
                f.write('TEST({}, empty) {{\n'.format(self._camel))
                f.write('}\n')
                f.write('\n')

            self.D('created file {}'.format(test_cpp))

        except Exception as e:
            try:
                os.remove(impl_cpp)
                os.remove(test_cpp)
            except:
                pass

            raise

def new_problem():
    args = Problem.default_args()

    print('Enter the problem name: ', end='', flush=True)
    for line in sys.stdin:
        args.name = line.rstrip()
        break

    print('Enter the GitHub issue number: ', end='', flush=True)
    for line in sys.stdin:
        args.issue = int(line.rstrip())
        break

    print('Enter the difficulty level (1=easy, 2=medium, 3=hard): ',
          end='', flush=True)
    for line in sys.stdin:
        args.difficulty = int(line.rstrip())
        if 1 <= args.difficulty and args.difficulty <= 3:
            break

    print('Enter the Solution template:')
    for line in sys.stdin:
        if line == '\n':
            break
        args.problem_template += line

    p = Problem(args)
    p.create_impl_and_test()

    return p
