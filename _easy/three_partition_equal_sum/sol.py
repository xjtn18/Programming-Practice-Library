######################################################
#  Author: Jacob Nardone
#  Date created: 1/26/2021
#  File type: Py file
#  Description: A function that returns true it an array can be partitioned into 3 parts (w/out rearranging elements) such that each partition sums to the same value.
######################################################

import sys
sys.path.append("../")
from parseTC import *


#START
class Solution:
    def canThreePartsEqualSum(self, arr : [int]) -> bool:
        total = sum(arr)
        if total % 3 != 0: return False
        count, tmp_sum, target = 0, 0, total / 3
        for num in arr:
            tmp_sum += num
            if tmp_sum == target:
                tmp_sum = 0
                count += 1
        return count >= 3 # count can be greater if the target is 0

#END


print('\n### TESTCASES ###')
tcs, exps = get_testcases()
for x in range(len(tcs)):
    inp = tcs[x]
    func_name = "canThreePartsEqualSum"
    exec("output = Solution()." + func_name + "(" + inp + ")")
    outcome = 'pass' if output == exps[x] else 'FAIL'
    print(inp, '-->', output, ':::', exps[x], '[' + str(outcome) + ']')
print("")
