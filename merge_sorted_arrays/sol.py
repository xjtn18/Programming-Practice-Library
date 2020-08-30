import sys
sys.path.append("../")
from parseTC import *

#START
class Solution:
    def merge(self, nums1: [int], m: int, nums2: [int], n: int) -> None:
        return 5
#END

print('\n### TESTCASES ###')
tcs, exps = get_testcases()
for x in range(len(tcs)):
    inp = tcs[x]
    func_name = "merge"
    exec("output = Solution()." + func_name + "(" + inp + ")")
    outcome = 'pass' if output == exps[x] else 'FAIL'
    print(inp, '-->', output, ':::', exps[x], '[' + str(outcome) + ']')
print("")


