######################################################
#  Author: Jacob Nardone
#  Date created: 1/29/2021
#  File type: Py file
#  Description: Get preorder traversal of a binary tree and append to a list.
######################################################

import sys
sys.path.append("../..")
from parseTC import *
from debug import *


import queue

#START
class Solution:
    def preorderTraversal(self, root: TreeNode) -> [int]:
        if not root: return []
        ret = []
        q = queue.LifoQueue()
        node = root

        while node or not q.empty():
            while node:
                q.put(node)
                node = node.left
            node = q.get()
            ret.append(node.val)
            node = node.right

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
print(sol.preorderTraversal(root))

