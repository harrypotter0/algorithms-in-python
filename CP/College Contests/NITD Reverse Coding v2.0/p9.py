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
def sort1(yy,index):
    return yy.sort(key = lambda x:x[index])
def reversepair(yy):
    return yy[::-1]
def checkint(x):
    return (x).is_integer()

MOD = 10 ** 9 + 7

for __ in range(readInt()):
    n,k = readInts()
    arr =[1, 1, 2, 3, 6, 7, 10, 11, 14, 19, 20, 25, 28,29, 32]
    


'''

input:
56 89
output:
207 212 213 218 221 222 231 244 247 248 251 264 269 278 279 282 287 294 299 304 307 312 319 322 329 338 339 348 349 354 357 362 369 372

1 1 2 3 6 7 10 11 14 19 20 25 28 29 32
'''
