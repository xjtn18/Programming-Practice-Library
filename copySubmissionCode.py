import pyperclip
import sys
import re
import os

"""
Takes in one commandline argument which is the directory of the problem and copies the code to the OS clipboard so it can be easily pasted into LeetCode
"""

START_DELIM = '#START'
END_DELIM = '#END'

cwd = os.getcwd() + '/'
problemDir = sys.argv[1]
problemPath = cwd + problemDir + 'sol.py'

with open(problemPath, 'r') as f:
	text = f.read()
	#print(text)
	r = re.compile(START_DELIM + '(\r\n|\r|\n)(.*)' + END_DELIM, flags = re.DOTALL) # dotall flag so that newlines are included in the "."
	submissionCode = r.search(text)
	if submissionCode:
		pyperclip.copy(submissionCode.group(2))
	else:
		print("ERROR: Submission delimiters not detected")

