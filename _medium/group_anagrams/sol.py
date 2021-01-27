######################################################
#  Author: Jacob Nardone
#  Date created: 1/12/21
#  File type: Py file
#  Description: Uses prime factorization of the ascii values to determine unique keys for anagrams.
#           Complexity: O(n * m) n = numbers of strings, m = length of string i
######################################################

import sys
sys.path.append("../")
from parseTC import *

from collections import defaultdict
from operator import mul
from functools import reduce

"""
Idea:
    Use a hash map where the key refers to any words that use the exact same characters (as well as the same number of times in each word) and the value is the list of those words.
    The hard part: figuring out how to get a unique value for each and every anagram.
"""




#START
class Solution:
    def groupAnagrams(self, strs:[str]) -> [[str]]:
        # hardcode first 26 primes
        primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101]
        groupings = defaultdict(list)
        for s in strs:
            try:
                groupings[reduce(mul, [primes[ord(c)-97] for c in s])].append(s)
            except TypeError: # the string is EMPTY
                groupings[0].append(s)
        return list(groupings.values())
#END



# trivial cases
print(Solution().groupAnagrams(["a"]))
print(Solution().groupAnagrams([""]))
print(Solution().groupAnagrams([]))


print(Solution().groupAnagrams(["eat","tea","tan","ate","nat","bat"]))
print(Solution().groupAnagrams(["dddddd","xxxxx","tan","ate","nat","bat"]))
print(Solution().groupAnagrams(["cb", "c"]))
print(Solution().groupAnagrams(["gb", "cd"]))
