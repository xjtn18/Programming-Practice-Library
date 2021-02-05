import time


def fibBruteForce(n : int) -> int: # trivial recursive version ; least optimal
    if n == 1: return 0
    if n == 2: return 1
    return fibBruteForce(n-1) + fibBruteForce(n-2)



memo = {}
def fibSet(n : int) -> int: # uses set to keep track of previously computed fibs.
    """Makes n constant time recursive calls ;
        Bad because it reaches max recursion depth at the 1000th fibonacci.
    """
    if n in memo: return memo[n]
    if n == 1: return 0
    if n == 2: return 1
    nfib = fibSet(n-1) + fibSet(n-2)
    memo[n] = nfib
    return nfib



def fibDP(n : int) -> int: # Most optimal ; non-recursive
    memo = [0,1]
    for i in range(2, n + 1):
        memo.append(memo[i-1] + memo[i-2])
    return memo[n-1] # n refers to nth fib, so n-1 is actually the nth fib in our array.



# brute force
t0 = time.time()
print(fibBruteForce(35))
t1 = time.time()
print(t1-t0, "\n")

# using set
t0 = time.time()
print(fibSet(999))
t1 = time.time()
print(t1-t0, "\n")

# full DP
t0 = time.time()
print(fibDP(1000))
t1 = time.time()
print(t1-t0, "\n")




