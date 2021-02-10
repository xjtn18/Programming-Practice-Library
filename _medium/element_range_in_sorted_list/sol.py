######################################################
#  Author: Jacob Nardone
#  Date created: 2/9/2021
#  File type: Py file
#  Description: Given a sorted list and a target value, return a list of 2 indices where the first value represents the index of the low of the target, and the second value represents the index of the high of the target.
######################################################

import sys
sys.path.append("../..")
from parseTC import *



"""
Idea:
    Since the list is sorted, we can use binary search to find the low of the target, and then we can run binary search again to find the high of the target. This is O(2 log n) which is O(log n).
    Time: O(log n)
    Space: O(1)

"""



#START
class Solution:

    def binSearchIndex(self, nums: [int], target : int, first : bool) -> int:
        i = -1
        low, high = 0, len(nums)-1

        while low <= high:
            i = (low & high) + ((low ^ high) >> 1) # middle index (overflow safe)

            if nums[i] > target:
                high = i - 1

            elif nums[i] < target:
                low = i + 1

            elif first: # at this point, we know the nums[i] is equal to the target
                if i-1 < 0 or nums[i-1] != target: return i
                else: high = i - 1

            else: # look for last occurence
                if i+1 >= len(nums) or nums[i+1] != target: return i
                else: low = i + 1

        # if low is greater than high, that 'i' is not our answer (target wasnt found)
        return i if low <= high else -1



    def searchRange(self, nums : [int], target : int) -> [int]:
        return [self.binSearchIndex(nums, target, True), self.binSearchIndex(nums, target, False)]


#END


sol = Solution()
print(sol.searchRange([], 0))
print(sol.searchRange([1], 0))
print(sol.searchRange([1,2], 2))
print(sol.searchRange([1], 1))
print(sol.searchRange([1,2,3,3,5], 3))
print(sol.searchRange([3,3,3,3,3], 3))



