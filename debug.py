# Debug.py
# Contains visual helper functions and standard LeetCode data structures for python


from collections import deque
import heapq

class MyHeap:
    def __init__(self, _isMaxHeap = False):
        self.heap = []
        self.isMaxHeap = _isMaxHeap

    def top(self) -> int:
        if len(self.heap) == 0:
            return None

        return self._checkFlip() * self.heap[0]

    def pop(self) -> int:
        return self._checkFlip() * heapq.heappop(self.heap)

    def push(self, num : int) -> int:
        return heapq.heappush(self.heap, self._checkFlip() * num)

    def _checkFlip(self) -> int:
        return -(2 * int(self.isMaxHeap) - 1)

    def __len__(self):
        return len(self.heap)



class TreeNode:

    def __init__(self, init_val = 0, init_left = None, init_right = None):
        self.left = None if not init_left else TreeNode(init_left)
        self.right = None if not init_right else TreeNode(init_right)
        self.val = init_val

    def __str__(self) -> str:  # preorder print
        s = ""
        d = deque()
        d.append(self)

        while len(d) > 0:
            node = d.popleft()
            if not node:
                s += 'null '
                continue
            else:
                s += f"{node.val} "
            d.append(node.left)
            d.append(node.right)

        return s

    def __repr__(self) -> str:
        return str(self.val)


class ListNode:
    def __init__(self, init_val = 0, init_next = None):
        self.val = init_val
        self.next = init_next

    def __str__(self) -> str:  # preorder print
        s = ""
        node = self
        s += "[ "
        while node:
            s += str(node.val) + " "
            node = node.next
        s+= "]"
        return s



def fill(v : [int], i : int) -> TreeNode:
    if v[i] == None:
        node = None
    else:
        node = TreeNode(v[i])
        if 2*i+1 < len(v):
            node.left = fill(v, 2*i+1)

        if 2*i+2 < len(v):
            node.right = fill(v, 2*i+2)

    return node



def createBinaryTree(v : [int]) -> TreeNode:
	if len(v) == 0: return None
	return fill(v, 0)


def createLinkedList(v : [int]) -> TreeNode:
	if len(v) == 0: return None
	root = ListNode(v[0])
	curr = root
	for x in v[1:]:
		curr.next = ListNode(x)
		curr = curr.next
	return root




