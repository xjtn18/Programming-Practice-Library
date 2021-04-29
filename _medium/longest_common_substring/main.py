


def LCsubstring(a : str, b : str):
	memo = [[0] * (len(b) + 1) for x in range(len(a) + 1)]
	maxx = 0
	x = y = 0

	for i in range(1, len(a) + 1):
		for j in range(1, len(b) + 1):
			memo[i][j] = memo[i-1][j-1] + 1 if a[i-1] == b[j-1] else 0
			if memo[i][j] > 0:
				maxx = max(memo[i][j], maxx)
				x = i
				y = j
	
	s = ""
	while (x > 0 and y > 0 and memo[x][y] > 0):
		s = a[x-1] + s
		x -= 1
		y -= 1
	return s




print(LCsubstring("ageeksforgeeks", "geeks"))
print(LCsubstring("avocadoplea", "cadopplease"))
print(LCsubstring("h", "hh"))
