######################################################
#  Author: Jacob Nardone
#  Date created:
#  File type: Py file
#  Description:
######################################################

import sys
sys.path.append("../..")
from parseTC import *
from debug import *

from collections import deque



#START
class Solution:
    def postorder(self, root : TreeNode) -> [int]:
        if not root: return []
        ret = []
        visited = set()
        stk = deque()
        stk.append(root)

        while stk:
            curr = stk[-1]
            if curr.right and curr.right not in visited:
                stk.append(curr.right)
            if curr.left and curr.left not in visited:
                stk.append(curr.left)
            if (not curr.left or curr.left in visited) and (not curr.right or curr.right in visited): # if the children are completed
                ret.append(curr.val)
                stk.pop()
                visited.add(curr)

        return ret

#END



root = TreeNode(1)
root.left = TreeNode(2)
root.left.left = TreeNode(4)
root.left.right = TreeNode(5)
root.right = TreeNode(3)
root.right.left = TreeNode(6)
root.right.right = TreeNode(7)
sol = Solution()
print(sol.postorder(root))


