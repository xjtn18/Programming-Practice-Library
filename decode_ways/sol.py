######################################################
#  Author: Jacob Nardone
#  Date created:
#  File type: Py file
#  Description:
######################################################

import sys
sys.path.append("../")
from parseTC import *


from math import ceil

#START
class Solution:
    def numDecodings(self, s: str) -> int:
        count = 0
        si = int(s)
        for i in range(len(s)):
            if i <= or i > 26
        return count
        
#END


print('\n### TESTCASES ###')
tcs, exps = get_testcases()
for x in range(len(tcs)):
    inp = tcs[x]
    func_name = "numDecodings"
    exec("output = Solution()." + func_name + "(" + inp + ")")
    outcome = 'pass' if output == exps[x] else 'FAIL'
    print(inp, '-->', output, ':::', exps[x], '[' + str(outcome) + ']')
print("")
