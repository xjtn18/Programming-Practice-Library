######################################################
#  Author: Jacob Nardone
#  Date created: 2/8/2021
#  File type: Py file
#  Description: Given a list with a strict majority element, return that element.
######################################################

import sys
sys.path.append("../..")
from parseTC import *



"""
Idea:

     Since we know there is a majority, we can use the Boyer-Moore voting algorithm for constant space linear time.
"""


#START
class Solution:
    def majorityElement(self, nums : [int]) -> int:
        count = 0

        for e in nums:
            if count == 0:
                candidate = e
            count += 1 if candidate == e else -1

        return candidate
#END


print('\n### TESTCASES ###')
tcs, exps = get_testcases()
for x in range(len(tcs)):
    inp = tcs[x]
    func_name = "majorityElement"
    exec("output = Solution()." + func_name + "(" + inp + ")")
    outcome = 'pass' if output == exps[x] else 'FAIL'
    print(inp, '-->', output, ':::', exps[x], '[' + str(outcome) + ']')
print("")
