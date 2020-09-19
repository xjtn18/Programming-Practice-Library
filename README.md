# LeetCode Solutions

# About
- This is a repository where I write and store my original solutions to LeetCode problems that I find interesting.
- I'm keeping this repository for many reasons:
1) To practice common algorithms one might need to know on the spot (either for technical interviews or personal/work purposes).
2) To be able to work in the environment of my choice as opposed to LeetCode's editor.
3) To keep a backup of my LeetCode solutions outside of my account.


# How to use this for yourself:
- To start a new problem, run new-problem.sh, which accepts 2 arguments: -l (the problem language), and -n (the name of the problem). For example: 'source new-problem.sh -l python -n prob1'
- Any python testcases should be written in the testcases.txt file in the format 'input ::: expected output'.
- Running the sol.py in python problem directories will test your code against the testcases and show you which cases you passed/failed.
- [Only for Python:] When you're ready submit to LeetCode, you can run the copySubmissionCode.py (with one argument to be the name of the problem directory you want submit) to automatically copy the necessary solution code to your main clipboard. ( example: 'python copySubmissionCode.py problem1/' )

