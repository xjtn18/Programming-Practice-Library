######################################################
#  Author: Jacob Nardone
#  Date created: 2/5/2021
#  File type: Py file
#  Description: Check if a given string is a valid palindrome (ingnoring symbols, spaces, and case)
######################################################

import sys
sys.path.append("../..")
from parseTC import *




"""
Idea:
    Have two pointers, one pointing at the front of the string, and one at the end.
    Every time the left or the right is pointing to a non-alhanumeric char, ignore that and increment respective pointer.
    Once both pointers point to an alphanum, compare the .lower() of the chars.
        If they are not equal, return False (not a palindrome)
        Else: incerment the pointers towards.

    Time: O(n), 'n' being the length of the string.
    Space: O(1)
"""




#START
class Solution:
    def isPalindrome(self, s: str) -> bool:
        left = 0
        right = len(s)-1
        while (left < right):
            if not s[left].isalnum():
                left += 1
            elif not s[right].isalnum():
                right -= 1
            elif s[left].lower() != s[right].lower():
                return False
            else:
                left += 1
                right -= 1
        return True

#END


print('\n### TESTCASES ###')
tcs, exps = get_testcases()
for x in range(len(tcs)):
    inp = tcs[x]
    func_name = "isPalindrome"
    exec("output = Solution()." + func_name + "(" + inp + ")")
    outcome = 'pass' if output == exps[x] else 'FAIL'
    print(inp, '-->', output, ':::', exps[x], '[' + str(outcome) + ']')
print("")
