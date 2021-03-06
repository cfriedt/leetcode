#!/usr/bin/env python3

from datetime import datetime
import git
import glob
import sys
import math
import numpy as np
from matplotlib import pyplot as plt


def getProblemList():
    problems = []
    problems_tmp = glob.glob('*-test.cpp')
    for p in problems_tmp:
        p = p[:-9]
        problems.append(p)
    return problems


def plot(data, title, filename):
    mean = np.average(data)
    median = np.median(data)
    mode = max(np.histogram(data)[1])
    bins = np.linspace(math.ceil(min(data)), math.floor(max(data)), 20)
    plt.xlim([min(data), max(data)])
    plt.hist(data, bins=bins, alpha=0.5)
    plt.axvline(mean, color='r', linestyle='dashed', linewidth=1, marker='^')
    plt.axvline(median, color='g', linestyle='dashed', linewidth=1, marker='s')
    plt.axvline(mode, color='b', linestyle='dashed', linewidth=1, marker='o')
    min_ylim, max_ylim = plt.ylim()
    plt.text(mean, max_ylim * 0.33,
             'Mean: {:.2f}'.format(mean), color='r', rotation=270)
    plt.text(median, max_ylim * 0.66,
             'Median: {:.2f}'.format(median), color='g', rotation=270)
    plt.text(mode, max_ylim * 0.90,
             'Mode: {:.2f}'.format(mode), color='b', rotation=270)
    plt.title(title)
    plt.xlabel('percentile')
    plt.ylabel('# results')
    # plt.show()
    plt.savefig(filename)
    plt.close()


def main(arg):

    retval = 0

    time_ranks = []
    space_ranks = []
    malformed = []

    repo = git.Repo('.')

    problems = getProblemList()
    for diff in repo.index.diff("HEAD"):
        suffix = '-test.cpp'
        # do not attempt to collect stats from files that are staged for commit
        a = diff.a_path
        prefix = a[: - len(suffix)]
        if a.endswith(suffix) and prefix in problems:
            problems.remove(prefix)
        b = diff.b_path
        prefix = b[: - len(suffix)]
        if b.endswith(suffix) and prefix in problems:
            problems.remove(prefix)

    for p in problems:

        filename = p + '.cpp'

        leetcode_stats_commit = None

        for commit in repo.iter_commits(paths=filename):

            msg = commit.message

            time_rank = -1
            space_rank = -1

            if 'https://leetcode.com/problems/' + p in msg or 'Implement ' + p in msg:
                if 'time-rank: ' in msg and 'space-rank: ' in msg:
                    for line in msg.splitlines():
                        if line.startswith('time-rank: '):
                            words = line.split()
                            time_rank = words[1]
                            time_rank = time_rank.replace('%', '')
                            try:
                                time_rank = float(time_rank)
                            except:
                                time_rank = -1
                                break
                            time_ranks.append(time_rank)
                        if line.startswith('space-rank: '):
                            words = line.split()
                            space_rank = words[1]
                            space_rank = space_rank.replace('%', '')
                            try:
                                space_rank = float(space_rank)
                            except:
                                space_rank = -1
                                break
                            space_ranks.append(space_rank)
                    if time_rank == -1 or space_rank == -1:
                        continue

                    #print( '{}: time-rank: {} space-rank: {}'.format( p, time_rank, space_rank ) )
                    leetcode_stats_commit = commit
                    break

        if leetcode_stats_commit is None:
            #print( 'malformed commit for problem {}'.format( p ) )
            retval = 1
            malformed.append(p)
            continue

    #print( 'time_ranks: len: {}: avg: {}: {}'.format( len( time_ranks ), np.average( time_ranks ), time_ranks ) )
    #print( 'space_ranks: len: {}: avg: {}: {}'.format( len( space_ranks ), np.average( space_ranks ), space_ranks ) )
    # malformed.sort()
    # for f in malformed:
    #    print( f + '.cpp' )

    plot(time_ranks, 'Time Rank ({})'.format(
        datetime.now().strftime('%Y-%m-%d')), '.scripts/time-rank.png')
    repo.git.add('.scripts/time-rank.png')

    plot(space_ranks, 'Space Rank ({})'.format(
        datetime.now().strftime('%Y-%m-%d')), '.scripts/space-rank.png')
    repo.git.add('.scripts/space-rank.png')

    return retval


if '__main__' == __name__:
    sys.exit(main(sys.argv))
