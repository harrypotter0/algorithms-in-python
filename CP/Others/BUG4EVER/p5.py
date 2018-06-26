from fractions import gcd
import math
from itertools import permutations
from itertools import combinations
import calendar
from itertools import product
def readInts():
    return list(map(int, raw_input().strip().split()))
def readInt():
    return int(raw_input())
def isSubsetSum(st, n, sm) :
    # arr, n, k
    subset=[[True] * (sm+1)] * (n+1)
    for i in range(0, n+1) :
        subset[i][0] = True
    for i in range(1, sm + 1) :
        subset[0][i] = False
    for i in range(1, n+1) :
        for j in range(1, sm+1) :
            if(j < st[i-1]) :
                subset[i][j] = subset[i-1][j]
            if (j >= st[i-1]) :
                subset[i][j] = subset[i-1][j] or subset[i - 1][j-st[i-1]]
    return subset[n][sm];

mod = 10 ** 9 + 7
# for i,j in product(xrange(R),xrange(C)):

for __ in range(readInt()):
    n,k = readInts()
    arr =readInts()
    if (isSubsetSum(arr, n, k) == True) :
        print "YES!"
    else:
        print "NO!"


'''
Input:
2
3 10
8 3 2
2 20
11 11

Output:
YES!
NO!
'''
