######################################################
#  Author: Jacob Nardone
#  Date created: 2/4/21
#  File type: Py file
#  Description: Count the number of primes in range [0,n).
######################################################

import sys
sys.path.append("../..")
from parseTC import *
from math import *


primes = set([2])

def isPrime(n : int) -> bool: # This isnt needed, just here for reference
    if n in primes: return True
    if n == 1 or n % 2 == 0: return False
    for i in range(3, n//2, 2):
        if n % i == 0: return False
    primes.add(n)
    return True


#START
class Solution:
    def countPrimes(self, n : int) -> int:
        if n <= 2: return 0

        sieve = [0,0,1] + [1] * (n-3)

        for i in range(2, ceil(pow(n, 0.5))):
            if sieve[i] == 1:
                j = i
                while j*i < n:
                    sieve[j*i] = 0
                    j += 1

        return sum(sieve)
#END


print('\n### TESTCASES ###')
tcs, exps = get_testcases()
for x in range(len(tcs)):
    inp = tcs[x]
    func_name = "countPrimes"
    exec("output = Solution()." + func_name + "(" + inp + ")")
    outcome = 'pass' if output == exps[x] else 'FAIL'
    print(inp, '-->', output, ':::', exps[x], '[' + str(outcome) + ']')
print("")
