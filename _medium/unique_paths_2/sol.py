######################################################
#  Author: Jacob Nardone
#  Date created: 9/18/2020
#  File type: Py file
#  Description: DP solution of summing total paths to corner of memo array; necessary because of obstacles
######################################################

import sys
sys.path.append("../")
from parseTC import *


#START
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: [[int]]) -> int:
        m, n = len(obstacleGrid[0]), len(obstacleGrid) # get dimensions of grid
        memo = [[0 for i in range(n+1)] for j in range(m+1)] # create our 2d DP array with zero filled padding to avoid edge checks
        memo[1][0] = 1 # so that the first corner (where the robot is) will equate to 1
        for x in range(1, m+1):
            for y in range(1, n+1):
                # if theres an obstacle here, no paths can get to this square, so set it to 0
                memo[x][y] = 0 if obstacleGrid[y-1][x-1] else memo[x-1][y] + memo[x][y-1]
        return memo[m][n]

#END


print('\n### TESTCASES ###')
tcs, exps = get_testcases()
for x in range(len(tcs)):
    inp = tcs[x]
    func_name = "uniquePathsWithObstacles"
    exec("output = Solution()." + func_name + "(" + inp + ")")
    outcome = 'pass' if output == exps[x] else 'FAIL'
    print(inp, '-->', output, ':::', exps[x], '[' + str(outcome) + ']')
print("")
