######################################################
#  Author: Jacob Nardone
#  Date created: 9/17/2020
#  File type: Py file
#  Description: Simple DP problem, summing unique paths to bottom corner of memo array
######################################################

import sys
sys.path.append("../")
from parseTC import *


#START
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        memo = [[0 for i in range(n+1)] for j in range(m+1)] # create our 2d DP array with zero filled padding to avoid edge checks
        memo[1][0] = 1 # so that the first corner (where the robot is) will equate to 1
        for x in range(1, m+1):
            for y in range(1, n+1):
                memo[x][y] = memo[x-1][y] + memo[x][y-1]
        return memo[m][n]
#END


print('\n### TESTCASES ###')
tcs, exps = get_testcases()
for x in range(len(tcs)):
    inp = tcs[x]
    func_name = "uniquePaths"
    exec("output = Solution()." + func_name + "(" + inp + ")")
    outcome = 'pass' if output == exps[x] else 'FAIL'
    print(inp, '-->', output, ':::', exps[x], '[' + str(outcome) + ']')
print("")
