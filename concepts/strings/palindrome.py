


def ispalin(s : str) -> bool:
	if s == "":
		return True
	left,right = 0, len(s)-1
	while left < right:
		if s[left] != s[right]:
			return False
		left += 1
		right -= 1
	return True

print(ispalin("acab"))
print(ispalin("acabaca"))
print(ispalin(""))
print(ispalin("gg"))
print(ispalin("bab"))
print(ispalin("babb"))



def longestsubpalin(s : str) -> str:
	longest = ""

	def expandout(x : int, y : int):
		nonlocal s, longest
		while x >= 0 and y < len(s):
			if s[x] != s[y]:
				break
			x -= 1
			y += 1
		if (y - x - 1) > len(longest): # update longest
			longest = s[x+1 : y]

	for i in range(len(s)):
		expandout(i,i) # odd length palindromes
		if i+1 < len(s): expandout(i,i+1) # odd length palindromes

	return longest


print(longestsubpalin("acab"))
print(longestsubpalin("acabaca"))
print(longestsubpalin(""))
print(longestsubpalin("gg"))
print(longestsubpalin("bab"))
print(longestsubpalin("babb"))
print(longestsubpalin("zwioaaaiwkldnjbbbb "))
