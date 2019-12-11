#!/usr/bin/env python3

import git
import glob
import sys

def getProblemList():
    problems = []
    problems_tmp = glob.glob( '*-test.cpp' )
    for p in problems_tmp:
        p = p[:-9]
        problems.append( p )
    return problems

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
                                        break
                                    time_ranks.append( time_rank )
                                if line.startswith( 'space-rank: ' ):
                                    words = line.split()
                                    space_rank = words[ 1 ]
                                    space_rank = space_rank.replace( '%', '' )
                                    try:
                                        space_rank = float( space_rank )
                                    except:
                                        break
                                    space_ranks.append( space_rank )
                            print( '{}: time-rank: {} space-rank: {}'.format( p, time_rank, space_rank ) )
                            leetcode_stats_commit = commit
                            break

        if leetcode_stats_commit is None:
            #print( 'malformed commit for problem {}'.format( p ) )
            retval = 1
            malformed.append( p )
            continue

    print( 'time_ranks: {}: {}'.format( len( time_ranks ), time_ranks ) )
    print( 'space_ranks: {}: {}'.format( len( space_ranks ), space_ranks ) )
    print( 'malformed: {}: {}'.format( len( malformed ), malformed ) )

    return retval

if '__main__' == __name__:
    sys.exit( main( sys.argv ) )

