#!/usr/bin/env python3

# Copyright (c) 2021, Christopher Friedt
#
# SPDX-License-Identifier: MIT

import git
from git import Repo
import io
import os
import requests
import types

import pytest

import problem
from problem import Problem
from problem import Difficulty

def test_init_happy_path():
    args = Problem.default_args()
    args.name = '3sum'
    p = Problem(args)

    # misc attributes
    assert(p._verbose == False)

    # leetcode attributes
    assert(p._name == args.name)
    assert(p._url == problem.LEETCODE_URL_BASE + '/' + args.name)

    # github attributes
    assert(p._issue == -1)

    # problem attributes
    #assert(p._leetcode_number == -1)
    assert(p._problem_template == '')

    assert(p._difficulty == Difficulty.INVALID)

    assert(p._time == -1)
    assert(p._time_rank == -1)
    assert(p._time_complexity == '')

    assert(p._space == -1)
    assert(p._space_rank == -1)
    assert(p._space_complexity == '')


def test_missing_args():
    # no attributes
    with pytest.raises(AttributeError):
        args = types.SimpleNamespace()
        p = Problem(args)

    # missing name attribute
    with pytest.raises(AttributeError):
        args = types.SimpleNamespace()
        args.verbose = False
        p = Problem(args)

    # missing verbose attribute
    with pytest.raises(AttributeError):
        args = types.SimpleNamespace()
        args.name = 'abc'
        p = Problem(args)


def test_init_invalid_verbose():
    invalid = [None, 42, 'Foo']
    for i in invalid:
        with pytest.raises(ValueError, match=r'invalid verbosity ".*"'):
            args = Problem.default_args()
            args.name = 'abc'
            args.verbose = i
            p = Problem(args)


def test_init_invalid_name():
    invalid = ['', 'a', 'a-', '-a', '!', 'ab!c']
    for i in invalid:
        with pytest.raises(ValueError, match=r'invalid name ".*"'):
            args = Problem.default_args()
            args.name = i
            p = Problem(args)


def test_create_problem(monkeypatch):

    repo = Repo(os.getcwd())
    assert(repo.bare == False)
    git = repo.git

    solution = \
        '''class Solution {
public:
    int fooBar(int z) {
        
    }
};

'''

    my_stdin = 'TEST-foo-bar\n42\n3\n' + solution
    my_stdout = ''

    try:
        git.branch('-D', 'issue/42/TEST-foo-bar')
    except:
        pass

    monkeypatch.setattr('sys.stdin', io.StringIO(my_stdin))
    p = problem.new_problem()

    assert(p._name == 'TEST-foo-bar')
    assert(p._camel == 'TESTFooBar')
    assert(p._issue == 42)
    assert(p._branch == 'issue/42/TEST-foo-bar')
    assert(p._difficulty == Difficulty.HARD)
    assert(p._problem_template + '\n' == solution)

    io_fail = False

    impl_cpp = p._name + '.cpp'
    test_cpp = p._name + '-test.cpp'

    if not os.path.exists(impl_cpp):
        io_fail = True

    if not os.path.exists(test_cpp):
        io_fail = True

    git.checkout('master')
    git.branch('-D', p._branch)

    if io_fail:
        try:
            os.remove(impl_cpp)
        except:
            pass
        try:
            os.remove(test_cpp)
        except:
            pass

    assert(os.path.exists(impl_cpp))
    assert(os.path.exists(test_cpp))

    os.remove(impl_cpp)
    os.remove(test_cpp)

    # expected = ''
    # expected += 'Enter the problem name: '
    # expected += 'Enter the GitHub issue number: '
    # expected += 'Enter the difficulty level (1=easy, 2=medium, 3=hard): '
    # expected += 'Enter the Solution template: '
    ## this needs using capsys as a function, but it's already monkeypatch
    # my_stdout = capsys.readouterr()
    # assert(my_stdout == expected)

    assert(p._time == -1)
    assert(p._time_rank == -1)
    assert(p._time_complexity == '')

    assert(p._space == -1)
    assert(p._space_rank == -1)
    assert(p._space_complexity == '')


def test_checkout_branch():

    repo = Repo(os.getcwd())
    assert(repo.bare == False)
    git = repo.git

    git.checkout('master')
    assert('master' == '{}'.format(repo.active_branch))

    args = Problem.default_args()
    args.issue = 123
    args.name = 'foo-bar'
    p = Problem(args)

    p.checkout_branch()
    branch_name = repo.active_branch

    git.checkout('master')
    try:
        git.branch('-D', branch_name)
    except:
        pass

    assert('{}'.format(branch_name) == 'issue/{}/{}'.format(args.issue, args.name))
