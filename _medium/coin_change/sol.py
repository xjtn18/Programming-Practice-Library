######################################################
#  Author: Jacob Nardone
#  Date created: 2/9/2021
#  File type: Py file
#  Description: Given a list of coin denominations and a target amount, return the smallest amount of coins you would need to reach that amount exactly. Return -1 if not possible.
######################################################

import sys
sys.path.append("../..")
from parseTC import *
import math

"""
Idea:
    Create a 1d memo array, where memo[i] represents the minimal coins used to reach subamount i.
    For every subamount, loop through the coins and take the min of memo[subamount - coin] plus this 1 new coin we are using.
    The value stored in memo[amount] after filling the array is our answer.

    Complexity:
    n = amount, m = number coins
    Time: O(n*m)
    Space: O(n)

"""



#START
class Solution:
    def coinChange(self, coins : [int], amount : int):
        memo = [0] + [math.inf] * amount

        for subamount in range(1, amount+1):
            subcounts = [math.inf]
            for c in coins:
                if subamount - c >= 0:
                    subcounts.append(memo[subamount - c])

            minn = min(subcounts)
            memo[subamount] = minn + 1 if minn != math.inf else math.inf

        return memo[amount] if memo[amount] != math.inf else -1
#END


print('\n### TESTCASES ###')
tcs, exps = get_testcases()
for x in range(len(tcs)):
    inp = tcs[x]
    func_name = "coinChange"
    exec("output = Solution()." + func_name + "(" + inp + ")")
    outcome = 'pass' if output == exps[x] else 'FAIL'
    print(inp, '-->', output, ':::', exps[x], '[' + str(outcome) + ']')
print("")
