import sys
sys.path.append("../..")
from debug import *

def postorder(root : TreeNode) -> [int]:
	ordering = []
	stk = [root]
	explored = set([None]) # add None to explored to skip having to check for leaves
	
	while stk:
		node = stk[-1] # top of the stack
		if node.left in explored and node.right in explored:
			ordering.append(node.val)
			explored.add(node)
			stk.pop()
			continue
		if node.right:
			stk.append(node.right)
		if node.left:
			stk.append(node.left)

	return ordering


t = createBinaryTree([5,3,4,1,2])
print(postorder(t)) # expecting [1,2,3,4,5]

t = createBinaryTree([2,7,5,2,6,None,9,None,None,5,11,None,None,4,None])
print(postorder(t)) # expecting [2,5,11,6,7,4,9,5,2]



def postorder2(root : TreeNode) -> [int]:
	##############
	# this implementation uses no explored set.
	##############
	stk1 = [root]
	stk2 = []
	
	while stk1:
		node = stk1.pop()
		stk2.append(node)
		if node.left:
			stk1.append(node.left)
		if node.right:
			stk1.append(node.right)

	return list(reversed(stk2))


t = createBinaryTree([5,3,4,1,2])
print(postorder2(t)) # expecting [1,2,3,4,5]

