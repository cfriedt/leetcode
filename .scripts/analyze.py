#!/usr/bin/env python3

import git
import glob
import sys
import math
import numpy as np
from matplotlib import pyplot as plt

def getProblemList():
    problems = []
    problems_tmp = glob.glob( '*-test.cpp' )
    for p in problems_tmp:
        p = p[:-9]
        problems.append( p )
    return problems

def plot( data, title ):
    bins = np.linspace(math.ceil(min(data)),math.floor(max(data)),20)
    plt.xlim([min(data), max(data)])
    plt.hist(data, bins=bins, alpha=0.5)
    plt.title( title )
    plt.xlabel( 'percentile' )
    plt.ylabel( '# results' )
    plt.show()

def main( arg ):

    retval = 0

    time_ranks = []
    space_ranks = []
    malformed = []

    problem_fixups = { 'peak-index-in-mountain-array': 'peak-index-in-a-mountain-array' }

    problems = getProblemList()

    repo = git.Repo('.')

    for p in problems:

        filename = p + '.cpp'

        leetcode_stats_commit = None

        for commit in repo.iter_commits( paths = filename ):

                msg = commit.message

                if 'https://leetcode.com/problems/' + p in msg or 'Implement ' + p in msg:
                        if 'time-rank: ' in msg and 'space-rank: ' in msg:
                            time_rank = 0.0
                            space_rank = 0.0
                            for line in msg.splitlines():
                                if line.startswith( 'time-rank: ' ):
                                    words = line.split()
                                    time_rank = words[ 1 ]
                                    time_rank = time_rank.replace( '%', '' )
                                    try:
                                        time_rank = float( time_rank )
                                    except:
                                        time_rank = -1
                                        break
                                    time_ranks.append( time_rank )
                                if line.startswith( 'space-rank: ' ):
                                    words = line.split()
                                    space_rank = words[ 1 ]
                                    space_rank = space_rank.replace( '%', '' )
                                    try:
                                        space_rank = float( space_rank )
                                    except:
                                        space_rank = -1
                                        break
                                    space_ranks.append( space_rank )
                            if time_rank is -1 or space_rank is -1:
                                break
                            print( '{}: time-rank: {} space-rank: {}'.format( p, time_rank, space_rank ) )
                            leetcode_stats_commit = commit
                            break

        if leetcode_stats_commit is None:
            #print( 'malformed commit for problem {}'.format( p ) )
            retval = 1
            malformed.append( p )
            continue

    print( 'time_ranks: len: {}: avg: {}: {}'.format( len( time_ranks ), np.average( time_ranks ), time_ranks ) )
    print( 'space_ranks: len: {}: avg: {}: {}'.format( len( space_ranks ), np.average( space_ranks ), space_ranks ) )
    print( 'malformed: {}: {}'.format( len( malformed ), malformed ) )

    plot( time_ranks, 'Time Rank' )
    plot( space_ranks, 'Space Rank' )

    return retval

if '__main__' == __name__:
    sys.exit( main( sys.argv ) )

