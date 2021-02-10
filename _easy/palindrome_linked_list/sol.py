######################################################
#  Author: Jacob Nardone
#  Date created: 2/5/2021
#  File type: Py file
#  Description: Given a linked list of numbers, determine if they form a palindrome.
######################################################

import sys
sys.path.append("../..")
from parseTC import *

from debug import *


"""
Goal: Find O(n) time and constant space solution

Idea:
    Pass through the 
"""





#START
class Solution:
    def isPalindrome(self, head : ListNode) -> bool:
        size = 0
        curr = head
        while curr: # get the size of the list
            size += 1
            curr = curr.next
        
        curr = head
        for pos in range(size // 2):
            tmp = curr
            for i in range(size - (pos * 2) - 1):
                tmp = tmp.next

            if curr.val != tmp.val:
                return False
            
            curr = curr.next

        return True
#END


sol = Solution()
head = ListNode(1, ListNode(2, ListNode(1, ListNode(2))))
print(head)
print(sol.isPalindrome(head))

print("")

head = ListNode(1, ListNode(2, ListNode(2, ListNode(1))))
print(head)
print(sol.isPalindrome(head))

print("")

head = ListNode(1)
print(head)
print(sol.isPalindrome(head))

print("")

head = None
print(head)
print(sol.isPalindrome(head))

print("")

head = ListNode(1, ListNode(2, ListNode(1)))
print(head)
print(sol.isPalindrome(head))



