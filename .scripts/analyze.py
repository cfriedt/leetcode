#!/usr/bin/env python3

import git
import glob
import sys

class GitAnalyzer(object):

    def __init__(self):
        self.repo = git.Repo('.')
        self.commits = list( self.repo.iter_commits( 'master' ) )

    def is_exists(self, filename, sha):
        """Check if a file in current commit exist."""
        files = self.repo.git.show("--pretty=", "--name-only", sha)
        if filename in files:
            return True
    
    def get_file_commits(self, filename):
        file_commits = []
        for commit in self.commits:
            if self.is_exists(filename, commit.hexsha):
                file_commits.append(commit)
    
        return file_commits

def getProblemList():
    problems = []
    problems_tmp = glob.glob( '*-test.cpp' )
    for p in problems_tmp:
        p = p[:-9]
        problems.append( p )
    return problems 

def main( arg ):
    
    retval = 0
    
    problem_fixups = { 'peak-index-in-mountain-array': 'peak-index-in-a-mountain-array' }
    
    
    ga = GitAnalyzer()
    problems = getProblemList()
    
    for p in problems:
        
        filename = p + '.cpp'
        
        if p in problem_fixups:
            p = problem_fixups[ p ]
        
        file_commits = ga.get_file_commits(filename)
        
        leetcode_stats_commit = None
        for fc in file_commits:
            msg = fc.message
            if 'https://leetcode.com/problems/' + p in msg or 'Implement ' + p in msg:
                leetcode_stats_commit = fc
                break

        if leetcode_stats_commit is None:
            print( 'failed to find stats commit for {}'.format( filename ) )
            retval = 1
            continue
            
        #print( '{}:\n{}'.format( filename, leetcode_stats_commit.message ) )
        
    return retval
    
if '__main__' == __name__:
    sys.exit( main( sys.argv ) )
  