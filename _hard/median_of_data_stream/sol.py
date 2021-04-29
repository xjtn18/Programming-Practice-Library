######################################################
#  Author: Jacob Nardone
#  Date created: 1/23/2021
#  File type: Py file
#  Description: Keep a sorted container of integers from a data stream and compute the running median at any given moment.
######################################################

import sys
sys.path.append("../")
from parseTC import *
from debug import *

import heapq


"""
Idea:
    Calculating the median is the trivial part, but keeping the data stream sorted efficiently is the tricky part. We can use a binary search tree to minimize insertion time.
"""


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



class Solution:

    def __init__(self):
        self.lo = MyHeap(True) # true because its a max heap
        self.hi = MyHeap()


    def addNum(self, num: int) -> None: # O(3 * log n)
        self.lo.push(num)
        if len(self.lo) > len(self.hi)+1 or (len(self.hi) > 0 and self.lo.top() > self.hi.top()):
            self.hi.push(self.lo.pop())

        if len(self.hi) > len(self.lo):
            self.lo.push(self.hi.pop())


    
    def findMedian(self) -> float:
        return self.lo.top() if len(self.lo) > len(self.hi) else (self.lo.top() + self.hi.top()) * 0.5





sol = Solution()

sol.addNum(3)
sol.addNum(3)
sol.addNum(1)
sol.addNum(1)
sol.addNum(2)
sol.addNum(4)

print(sol.findMedian())


