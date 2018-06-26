# /*
#  *
#  ********************************************************************************************
#  * AUTHOR : AKASH KANDPAL                                                                   *
#  * Language : Python2                                                                       *
#  * Motto : The master has failed more times than the beginner has even tried.               *
#  * IDE used: Atom                                                                           *
#  * My Domain : http://harrypotter.tech/                                                     *
#  ********************************************************************************************
#  *
#  */
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
def readStrs():
    return raw_input().split()
def readStr():
    return raw_input()
def readarr(n):
    return [map(int,list(readStr())) for i in xrange(n)]
def readnumbertolist():
    a=[int(i) for i in list(raw_input())]
    return a
def strlistTostr(list1):
    return ''.join(list1)
def numlistTostr(list1):
    return ''.join(str(e) for e in list1)
def strTolist(str):
    return str.split()
def strlistTointlist(str):
    return map(int, str)
def slicenum(number,x):
    return int(str(number)[:x])
def precise(num):
    return "{0:.10f}".format(num)
def rsorted(a):
    return sorted(a,reverse=True)
def binar(x):
    return '{0:031b}'.format(x)

mod = 10 ** 9 + 7
# for i,j in product(xrange(R),xrange(C)):

def printcode(i,ans):
    print "Case #{}: {}".format(i+1,ans)

for t in range(readInt()):
    n = readInt()
    h = [0]+readInts()+[0]

    L = [0]*(n+2)
    for i in range(1, n+1):
        L[i] = min(L[i-1]+1, h[i])
    R = [0]*(n+2)
    for i in range(n, 0, -1):
        R[i] = min(R[i+1]+1, h[i])
    # print L
    # print R

    max_height = 0
    for i in range(1, n+1):
        height = min(L[i], R[i])
        max_height = max(max_height, height)

    ans = sum(h) - max_height**2
    print ans

'''
Input
3
3
1 2 1
4
1 1 2 1
5
1 2 6 2 1

Output
0
1
3
'''
