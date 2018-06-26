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

for __ in range(readInt()):
    n,k = readInts()
    a = readInts()
    d = readInts()
    b = readInts()
    arr = []
    for i in range(n):
        arr+=[a[i]]*d[i]
    arr.sort()
    print arr
    for i in range(k):
        if i%2==0:
            arr=arr[-b[i]:]
        else:
            arr=arr[:b[i]]
    print(sum(arr))


'''
Input:

1
4 2
1 2 4 3
2 2 3 2
6 3

Output:

7
'''
