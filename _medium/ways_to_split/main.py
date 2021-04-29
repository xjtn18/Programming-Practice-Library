import sys
sys.path.append("../..")
from parseTC import *
from collections import defaultdict


def waystosplit_naive(s : str) -> int:
	counter = 0
	for i in range(1, len(s)):
		if len(set([x for x in s[:i]])) == len(set([x for x in s[i:]])):
			counter += 1
	
	return counter


def waystosplit(s : str) -> int:
	lmap = defaultdict(int)
	rmap = defaultdict(int)
	counter = 0

	for c in s:
		rmap[c] += 1
	
	i = 1 # split index
	while len(rmap) >= len(lmap) and i < len(s):
		lmap[s[i-1]] += 1
		rmap[s[i-1]] -= 1
		if rmap[s[i-1]] == 0:
			del rmap[s[i-1]]
		counter += int(len(lmap) == len(rmap))
		i += 1
	
	return counter




print(waystosplit("aacaba"))
print(waystosplit("abcd"))
print(waystosplit("acbadbaada"))
print(waystosplit("aaaaa"))
print(waystosplit(""))
print(waystosplit("k"))
