# LeetCode Solutions

## About
- A repository to store solutions to LeetCode problems and the like. Also contains libraries, notes, and source files that explore common programming concepts and algorithms.
- Doubles as a workspace to create new problem environments easily and solve problems in the comfort of your own editor.


## How to use:
- To create a new problem, open a terminal and run:
	* Unix 	>> "source new.sh {problem_name} {language} {difficulty}"
	* MSW 	>> "new.sh {problem_name} {language} {difficulty}"
- Languages to choose from include "python", "java", and "cpp".
- Difficulties to choose from include "easy", "medium", and "hard".
- This script will create a problem directory in in the specified difficulty folder, copy over the neccessary template files, and then set that directory to the current working one.

- Any python testcases should be written in the testcases.txt file in the format 'input ::: expected output'.
- Running the sol.py in python problem directories will test your code against the testcases and show you which cases you passed/failed.
- [Only for Python problems] When you're ready submit to LeetCode, you can run the copySubmissionCode.py (with one argument to be the name of the problem directory you want submit) to automatically copy the necessary solution code to your main clipboard. ( example: 'python copySubmissionCode.py problem1/' )

