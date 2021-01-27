import sys
from math import floor
import operator as op
from functools import reduce
sys.path.append("../")
from parseTC import *

#START
class Solution:

    def ncr(self, n, r):
        r = min(r, n-r)
        numer = reduce(op.mul, range(n, n-r, -1), 1)
        denom = reduce(op.mul, range(1, r+1), 1)
        return numer / denom

    def climbStairs(self, n):
        max = floor(n/2) # max number of double steps we can take
        count = 0
        for i in range(max,-1,-1):
            count += self.ncr(n-i,i)
        return int(count)
#END

print('\n### TESTCASES ###')
tcs, exps = get_testcases()
for x in range(len(tcs)):
    inp = tcs[x]
    output = Solution().climbStairs(inp)
    outcome = 'pass' if output == exps[x] else 'FAIL'
    print(inp, '-->', output, ':::', exps[x], '[' + str(outcome) + ']')
print("")


