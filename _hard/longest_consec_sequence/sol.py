######################################################
#  Author: Jacob Nardone
#  Date created: 1/23/2021
#  File type: Py file
#  Description: Given a unsorted list of ints, find the length of the longest consecutive chain of numbers in the list.
######################################################

import sys
sys.path.append("../")
from parseTC import *


"""
Trivial inefficient solution:
    Sort the numbers, loop through them, tally up consecutive numbers and keep track of the max. Return max.
        Time complexity: O(2n log n), because we are sorting (using standard quicksort), and iterating through all elements.
        Space complexity: O(1)

Better solution:
    Store the numbers in a set for constant lookup time. Loop through every number in the list. If the numbers predecessor is in the set, it cant be the start of the longest streak, so ignore it and move to the next number. If the next number is a possible beggining of a streak, loop through the consecutive numbers until they no longer exist and update maxConsec count. The inner loop can only run a maximum of N times spanned across the entire initial for loop, thereby effectively making the whole algorithm O(N + N) = O(N).
    Space Complexity: O(N), but no worry about modifying the original list :)
"""


class Solution:
    def longestConsecutive(self, nums: [int]) -> int:
        maxconsec = 0
        nset = set(nums)

        for n in nums:
            if n - 1 not in nset:
                curr_num = n
                consec = 1

                while curr_num + 1 in nset:
                    curr_num += 1
                    consec += 1

                maxconsec = max(consec, maxconsec)

        return maxconsec



sol = Solution()
print(sol.longestConsecutive([0,3,7,2,5,8,4,6,0,1]))
print(sol.longestConsecutive([]))
print(sol.longestConsecutive([2]))
print(sol.longestConsecutive([1,2,3,6,7,8,9,10]))
print(sol.longestConsecutive([1,2,0,1]))

