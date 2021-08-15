import sys
sys.path.append("../")
from parseTC import *

#START
class Solution:
	def isPalindrome(self, x:int) -> bool:
		return str(x) == str(x)[::-1]
#END

print('\n### TESTCASES ###')
tcs, exps = get_testcases()
for x in range(len(tcs)):
	inp = tcs[x]
	output = Solution().isPalindrome(inp)
	outcome = 'pass' if output == exps[x] else 'FAIL'
	print(inp, '-->', output, ':::', exps[x], '[' + str(outcome) + ']')
print("")


