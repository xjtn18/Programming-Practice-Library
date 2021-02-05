######################################################
#  Author: Jacob Nardone
#  Date created: 1/29/2021
#  File type: Py file
#  Description: Return the longest palindrome substring from an input string
######################################################

import sys
sys.path.append("../..")
from parseTC import *



"""
Idea:
"""



#START
class Solution:
    def longestPalindrome(self, s : str) -> str:
        longest = ""

        def expandOut(left : int, right : int) -> None:
            nonlocal longest, s
            for j in range(len(s)):
                if left-j >= 0 and right+j < len(s) and s[left-j] == s[right+j]:
                    if (right+j+1) - (left-j) > len(longest):
                        longest = s[left-j : right+j+1]
                else:
                    break
        

        for i in range(len(s)):
            expandOut(i,i) # odd length palindromes
            if i + 1 < len(s): expandOut(i,i+1) # even length palindromes

        return longest

#END


print('\n### TESTCASES ###')
tcs, exps = get_testcases()
for x in range(len(tcs)):
    inp = tcs[x]
    func_name = "longestPalindrome"
    exec("output = Solution()." + func_name + "(" + inp + ")")
    outcome = 'pass' if output == exps[x] else 'FAIL'
    print(inp, '-->', output, ':::', exps[x], '[' + str(outcome) + ']')
print("")
