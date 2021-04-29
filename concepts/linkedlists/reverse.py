import sys
sys.path.append("../..")
from debug import *


def reverse(root : ListNode) -> ListNode:
	######################
	# Reverse a linked list in place
	######################
	curr = root
	prev = None

	while curr:
		next = curr.next
		curr.next = prev
		prev = curr
		curr = next

	return prev # will contain the new head


ll = createLinkedList([1,2,3])
print(ll)
print(reverse(ll))


