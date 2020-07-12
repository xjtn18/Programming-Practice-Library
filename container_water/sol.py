import sys
sys.path.append("../")
from parseTC import *

class Solution:
	def maxArea(self, height: [int]) -> int:
		max_area = 0
		for a,x in enumerate(height):
			for b,y in enumerate(height):
				max_area = max(min(x,y) * abs(a-b), max_area)
		return max_area


print('\n### TESTCASES ###')
tcs, exps = get_testcases()
for x in range(len(tcs)):
	inp = tcs[x]
	output = Solution().maxArea(inp)
	outcome = 'pass' if output == exps[x] else 'FAIL'
	print(inp, '-->', output, ':::', exps[x], '[' + str(outcome) + ']')
print("")
	
			


