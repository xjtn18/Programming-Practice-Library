import sys
sys.path.append("../..")
from debug import *

def preorder(root : TreeNode) -> [int]:
	ordering = []
	stk = [root]
	
	while stk:
		node = stk.pop()
		ordering.append(node.val)
		if node.right:
			stk.append(node.right)
		if node.left:
			stk.append(node.left)

	return ordering

t = createBinaryTree([1,2,5,3,4,None,6])
print(preorder(t)) # expecting [1,2,3,4,5,6]

