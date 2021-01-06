######################################################
#  Author: Jacob Nardone
#  Date created: 1/1/2021
#  File type: Py file
#  Description: Least Recently Used cache.
#           Python has an "OrderedDict" class
#           This is a conveniant object that stores both a dictionary and an ordered list (maybe a linked list for
#               constant operations). It defines "move_to_end" and "popitem". Doing this manually is pretty trivial,
#               just create a dict and a doubly linked list.
######################################################

import sys
sys.path.append("../")
from parseTC import *

from collections import OrderedDict

class LRUCache:

    def __init__(self, capacity: int):
        self.hmap = OrderedDict()
        self.cap = capacity

    def get(self, key: int) -> int:
        try:
            self.hmap.move_to_end(key) # used this pair
            return self.hmap[key]
        except KeyError:
            return -1

    def put(self, key: int, value: int) -> None:
        if key not in self.hmap and len(self.hmap) == self.cap:
            self.hmap.popitem(last=False) # evict least recently used pair
        self.hmap[key] = value # adds pair or edits existing one
        self.hmap.move_to_end(key) # adding a pair is like "using" it


    def __str__(self):
        return "{" + "".join([f"{pair[0]}={pair[1]}, " for pair in self.hmap.items()]).strip(", ") + "}"


if __name__ == "__main__":
    cache = LRUCache(2)
    cache.put(1,1)
    cache.put(2,2)
    cache.get(1)
    cache.put(3,3)
    cache.get(2)
    cache.put(4,4)
    cache.get(1)
    cache.get(3)
    cache.get(4)
    print(cache)



