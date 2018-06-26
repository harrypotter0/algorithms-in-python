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
    x = readInt()
    n = (math.sqrt(1+8*x)-1)/2
    # print n
    check = checkint(n)
    if(check):
        print int(n)
        continue
    else:
        a = int(math.floor(n))
        b = int(math.ceil(n))
        # print a,b
        a1 = a*(a+1)/2
        b1 = b*(b+1)/2
        diff1 = abs(a1-x)
        diff2 = abs(b1-x)
        if(diff1<=diff2):
            ans = a+int(math.ceil(abs(a1-x)))
            # print int(math.ceil(abs(a1-x)/2.0))
        else:
            ans = b+int(math.ceil(abs(b1-x)))
            # print int(math.ceil(abs(b1-x)/2.0))
        print ans







'''
Input:

1
9

Output:

1
2
2
5
'''
