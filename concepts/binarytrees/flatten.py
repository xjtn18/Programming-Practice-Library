import sys
sys.path.append("../..")
from debug import *

def flatten(node : TreeNode) -> TreeNode:
	######################
	# Flattens a binary tree in a singly linked list down its right children
	######################
	if not node:
		return

	if node.right:
		flatten(node.right)

	if node.left:
		flatten(node.left)
		curr = leftroot = node.left
		while curr.right:
			curr = curr.right
		curr.right = node.right
		node.left = None
		node.right = leftroot


t = createBinaryTree([1,2,5,3,4,None,6])
flatten(t)

print("")
curr = t
while curr:
	print(curr.val)
	curr = curr.right
