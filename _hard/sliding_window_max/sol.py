######################################################
#  Author: Jacob Nardone
#  Date created: 1/24/2021
#  File type: Py file
#  Description: Given a list of ints and window size k that scans the array and views k elements at each iteration, return a list of all of the max's from each window through the iteration.
######################################################


"""
Idea:
    Use a double ended queue that keeps bigger numbers towards the front. Any new number that window exposes that is greater than any tailing numbers in the deque removes all of those tailing numbers. We know that those numbers can be removed because a larger number has been found AFTER them, and so they could never be the max for any given window in the future.

"""



import sys
sys.path.append("../")
from parseTC import *
from debug import *

from collections import deque


#START
class Solution:

    def maxSlidingWindow(self, nums : [int], k : int) -> [int]:

        def trimAndAppend(i : int) -> None:
            while dq and nums[i] > nums[dq[-1]]:
                dq.pop()
            dq.append(i)

        dq = deque()

        for i in range(k): # fill dq with first window
            trimAndAppend(i)

        maxes = [nums[dq[0]]]
    
        for i in range(k, len(nums)): # for each new element seen in the rest of the windows: nums[k] is the first new element seen
            if i - dq[0] == k:
                dq.popleft() # remove current max

            trimAndAppend(i)

            maxes.append(nums[dq[0]])

        return maxes

#END


print('\n### TESTCASES ###')
tcs, exps = get_testcases()
for x in range(len(tcs)):
    inp = tcs[x]
    func_name = "maxSlidingWindow"
    exec("output = Solution()." + func_name + "(" + inp + ")")
    outcome = 'pass' if output == exps[x] else 'FAIL'
    print(inp, '-->', output, ':::', exps[x], '[' + str(outcome) + ']')
print("")
