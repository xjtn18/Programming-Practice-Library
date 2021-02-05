import sys
sys.path.append("../")
from debug import *




def reverseLL(root):
    node = root
    prev = None
    while node.next:
        z = node.next.next
        node.next.next = node
        if node == root:
            node.next = None
        else:
            node.next = 
        prev = 

    




root = ListNode(1, ListNode(2))
print(root)
