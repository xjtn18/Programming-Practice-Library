######################################################
#  Author: Jacob Nardone
#  Date created: 1/22/2021
#  File type: Py file
#  Description: Turn a binary tree data structure into a string (that can be transmitted through networks) and write the code that also turns a string back into a binary tree.
######################################################

import sys
sys.path.append("../")
from parseTC import *
from debug import *

from collections import deque



class Solution:

    def __init__(self):
        self.delim = '.'
        self.nullsymb = '#'

    def serialize(self, root : TreeNode) -> str: # creates string in preorder of tree
        return self.nullsymb if not root else self.delim.join([str(root.val), self.serialize(root.left), self.serialize(root.right)])


    def deserialize(self, data : str) -> TreeNode: # creates tree in preorder of string
        def loop() -> TreeNode:
            val = next(vals)
            print(val)
            if val == self.nullsymb:
                return None
            node = TreeNode(int(val))
            node.left = loop()
            node.right = loop()

            return node


        vals = iter(data.split(self.delim))
        return loop()





sol = Solution();

root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.right.left = TreeNode(4)
root.right.right = TreeNode(5)
print(root)

msg = sol.serialize(root);
print(msg)

recovery = sol.deserialize(msg)
print(recovery)



