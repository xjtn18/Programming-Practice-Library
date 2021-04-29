######################################################
#  Author: Jacob Nardone
#  Date created: 2/11/2021
#  File type: Py file
#  Description: Given a tree, determine if it is a valid BST.
######################################################

import sys
sys.path.append("../..")
from parseTC import *
from debug import *

import math



"""
Idea:
    Do an inorder traversal of the tree using a stack and check that the next node's values is greater than the last.

    Complexity:
        Time:   O(N)
        Space:  O(1)
"""




#START
class Solution:
    def isValidBST(self, root : TreeNode) -> bool:
        stk = []
        curr = root
        prev = -math.inf

        while curr or len(stk):
            while curr:
                stk.append(curr)
                curr = curr.left

            curr = stk.pop()

            if curr.val <= prev:
                return False

            prev = curr.val
            curr = curr.right

        return True

#END





sol = Solution()

t = createBinaryTree([2,1,3])
print(sol.isValidBST(t))

t = createBinaryTree([2,3,1])
print(sol.isValidBST(t))



