######################################################
#  Author: Jacob Nardone
#  Date created: 1/27/2021
#  File type: Py file
#  Description: Given a string representing a number, find the number of all-prime groupings you can make from that string (keeping the order of digits the same).
######################################################

import sys
sys.path.append("../..")
from parseTC import *


"""
IDEA:
    Use dynammic programming.
    Keep a 1D array that


"""

primes = set()


def isPrime(num : int) -> bool:
    if num in primes:
        return True
    if num == 0 or num == 1:
        return False
    if num == 2:
        return True
    if num % 2 == 0:
        return False

    for j in range(3, num // 2, 2):
        if num % j == 0:
            return False

    primes.add(num)
    return True;


class Solution:
    def countPrimeGroupings(self, s : str):
        print(s[:3])
        dp = [0] * (len(s)+1)
        for i in range(1, len(s) + 1):
            print(i)
            count = 0
            for j in range(i):
                if isPrime(int(s[j:i])):
                    count += dp[j]
            dp[i] = count
            dp[i] += isPrime(int(s[:i]))
        
        return dp[-1]



print('\n### TESTCASES ###')
tcs, exps = get_testcases()
for x in range(len(tcs)):
    inp = tcs[x]
    func_name = "countPrimeGroupings"
    exec("output = Solution()." + func_name + "(" + inp + ")")
    outcome = 'pass' if output == exps[x] else 'FAIL'
    print(inp, '-->', output, ':::', exps[x], '[' + str(outcome) + ']')
print("")
