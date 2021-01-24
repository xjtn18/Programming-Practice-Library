# Debug.py
# Contains visual helper functions and standard LeetCode data structures for python


from collections import deque

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



