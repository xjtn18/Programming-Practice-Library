######################################################
#  Author: Jacob Nardone
#  Date created:
#  File type: Py file
#  Description:
######################################################

import sys
sys.path.append("../")
from parseTC import *


#START
class Solution:
    def twoSum(self, nums : [int], target : int) -> [int]:
        """
        Idea: Keep a has map that maps values seen to their index
                For each value:
                    If target - value in map:
                        return current loop index and value from map query of target - value
                if not in map, add to map
        """
        nmap = {}
        for i in range(len(nums)):
            comp = target - nums[i]
            if nums[i] in nmap:
                return [nmap[nums[i]], i]
            nmap[target - nums[i]] = i
        return None

#END


print('\n### TESTCASES ###')
tcs, exps = get_testcases()
for x in range(len(tcs)):
    inp = tcs[x]
    func_name = "twoSum"
    exec("output = Solution()." + func_name + "(" + inp + ")")
    outcome = 'pass' if output == exps[x] else 'FAIL'
    print(inp, '-->', output, ':::', exps[x], '[' + str(outcome) + ']')
print("")
