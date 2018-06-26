# Akash Kandpal
# My Domain => http://harrypotter.tech/
# from fractions import gcd
import math
# from itertools import permutations
# import statistics

def readInts():
    return list(map(int, raw_input().strip().split()))
def readInt():
    return int(raw_input())
def readIntsindex0():
    return list(map(lambda x: int(x) - 1, input().split()))
def readStrs():
    return raw_input().split()
def readStr():
    return raw_input()
def numlistTostr(list1):
    return ''.join(list1)
def strlistTostr(list1):
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
def findpermute(word):
    perms = [''.join(p) for p in permutations(word)]
    return set(perms)
def findsubsets(S,m):
    return set(itertools.combinations(S, m))
def combinesort(X,Y,sort):
    return [x for _, x in sorted(zip(X,Y), key=lambda pair: pair[sort])]
def reversepair(yy):
    return yy[::-1]
def checkint(x):
    return (x).is_integer()
def dictionary(a,b):
    return dict(zip(arr, brr))
MOD = 10 ** 9 + 7

from __future__ import division
from math import ceil
from bisect import bisect_right as b_r
from bisect import bisect_left as b_l
for _ in range(0 , input()):
    n, k = map(int , raw_input().split())
    r = raw_input()
    lis = []
    for j in range(1,n+1):
        a  = j
        rr = r[:a]
        cc = 0
        ll = []
        for i in range(a,0,-1):
            if rr[:i] == rr[a-i:]:
                ll.append(i)
                cc+=1
        lis.append(ll)
    for i in range(0, k):
        a,b = map(int, raw_input().split())
        ll = lis[a-1]
        if b> len(ll):
            print -1
        else:
            print ll[-b]



'''


'''
