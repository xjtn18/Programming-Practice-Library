import re

def get_testcases():
	""" Reads in the testcases and their expected answers in the from the testcases file in teh same directory and returns to lists for both inputs and expected outputs."""

	splitOn = ":::"

	testcases = []
	expecteds = []

	with open('testcases.txt' , 'r') as f:
		cases = f.readlines()

	for case in cases:
		inp, exp = re.split(splitOn, case)
		inp = inp.strip()
		exp = exp.strip()
		exec('testcases.append('+inp+')')
		exec('expecteds.append('+exp+')')

	return testcases, expecteds

