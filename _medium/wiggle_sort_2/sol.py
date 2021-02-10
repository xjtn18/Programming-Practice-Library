######################################################
#  Author: Jacob Nardone
#  Date created: 2/5/2021
#  File type: Py file
#  Description: Sort a given list of integers with the constraint the every even index is less than every odd index,
#               and every odd index is greater than every even index.
######################################################

import sys
sys.path.append("../..")
from parseTC import *


#START
class Solution:
    def wiggleSort(self, nums : [int]) -> None:
        for i in range(0,len(nums)-1,2):
            if i % 2 == 0: # even
                j = i
                if j < len(nums):
                    while j < len(nums)-1 and nums[i] >= nums[j]:
                        j += 1
                    nums[i], nums[j] = nums[j], nums[i]

            else: # odd
                j = i
                if j < len(nums):
                    while j < len(nums)-1 and nums[i] <= nums[j]:
                        j += 1
                    nums[i], nums[j] = nums[j], nums[i]


            
        
#END



sol = Solution()

nums = [1,3,2,2,3,1]
sol.wiggleSort(nums)
print(nums)
print("")

nums = [1]
sol.wiggleSort(nums)
print(nums)
print("")

nums = [2,1]
sol.wiggleSort(nums)
print(nums)
print("")

nums = [1,2]
sol.wiggleSort(nums)
print(nums)
print("")

nums = [4,3,2,1]
sol.wiggleSort(nums)
print(nums)
print("")

nums = [3,2,4]
sol.wiggleSort(nums)
print(nums)
print("")

nums = [1,1,1,6,4,5]
sol.wiggleSort(nums)
print(nums)
print("")

nums = [1,1,1,6,4,5]
sol.wiggleSort(nums)
print(nums)
print("")


