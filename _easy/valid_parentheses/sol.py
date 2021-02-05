######################################################
#  Author: Jacob Nardone
#  Date created: 2/4/21
#  File type: Py file
#  Description: Check if a string of parentheses is valid structure.
######################################################

import sys
sys.path.append("../..")
from parseTC import *


#START
class Solution:
    def isValid(self, s : str) -> bool:
        stack = []
        openers = ['(', '[', '{']
        closers = [')', ']', '}']

        for c in s:
            try: # if its a closer
                idx = closers.index(c)
                if not len(stack) or stack.pop() != openers[idx]:
                    # if there was no opener or the last opener was a different symbol
                    return False

            except ValueError: # its an opener
                stack.append(c)

        return not len(stack)

#END


print('\n### TESTCASES ###')
tcs, exps = get_testcases()
for x in range(len(tcs)):
    inp = tcs[x]
    func_name = "isValid"
    exec("output = Solution()." + func_name + "(" + inp + ")")
    outcome = 'pass' if output == exps[x] else 'FAIL'
    print(inp, '-->', output, ':::', exps[x], '[' + str(outcome) + ']')
print("")
