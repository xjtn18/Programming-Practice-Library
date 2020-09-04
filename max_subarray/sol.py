import sys
sys.path.append("../")
from parseTC import *
from math import inf

#START
class Solution:

    def maxSubArray(self, nums: [int]) -> int:
        maxnet = -2147483648
        net = 0

        for n in nums:
            net += n
            if n > net:
                net = n
            maxnet = max(net, maxnet)

        return maxnet
#END

print('\n### TESTCASES ###')
tcs, exps = get_testcases()
for x in range(len(tcs)):
    inp = tcs[x]
    func_name = "maxSubArray"
    exec("output = Solution()." + func_name + "(" + inp + ")")
    outcome = 'pass' if output == exps[x] else 'FAIL'
    print(inp, '-->', output, ':::', exps[x], '[' + str(outcome) + ']')
print("")


