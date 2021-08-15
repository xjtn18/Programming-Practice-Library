import sys
sys.path.append("../")
from parseTC import *

#START
class Solution:
	def threeSum(self, num: [int]) -> [[int]]:
		seen = []
		final_set = []
		for x in range(len(num)):
			for y in range(x+1, len(num)):
				for z in range(y+1, len(num)):
					s = {num[x],num[y],num[z]}
					if num[x] + num[y] + num[z] == 0 and s not in seen:
						final_set.append([num[x],num[y],num[z]])
						seen.append(s)
		return final_set
#END

print('\n### TESTCASES ###')
tcs, exps = get_testcases()
for x in range(len(tcs)):
	inp = tcs[x]
	output = Solution().threeSum(inp)
	outcome = 'pass' if output == exps[x] else 'FAIL'
	print(inp, '-->', output, ':::', exps[x], '[' + str(outcome) + ']')
print("")


