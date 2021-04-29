import sys
sys.path.append("../..")
from debug import *

def inorder(root : TreeNode) -> [int]:
	ordering = []
	stk = []
	curr = root

	while stk or curr: # while stack is not empty
		if curr:
			stk.append(curr)
			curr = curr.left

		else: # stack must be non-empty, otherwise loop condition would fail
			curr = stk.pop()
			ordering.append(curr.val)
			curr = curr.right

	return ordering


t = createBinaryTree([4,2,6,1,3,5,7])
print(inorder(t)) # expecting [1,2,3,4,5,6,7]

