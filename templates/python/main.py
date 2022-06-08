######################################################
#  Author: Jacob Nardone
#  Date created:
#  File type: Py file
#  Description:
######################################################

import sys
sys.path.append("../..")
from parseTC import *
from debug import *


class Solution:
	def ___(self):


print('\n### TESTCASES ###')
tcs, exps = get_testcases()
for x in range(len(tcs)):
    inp = tcs[x]
    func_name = ""
    exec("output = Solution()." + func_name + "(" + inp + ")")
    outcome = 'pass' if output == exps[x] else 'FAIL'
    print(inp, '-->', output, ':::', exps[x], '[' + str(outcome) + ']')
print("")
