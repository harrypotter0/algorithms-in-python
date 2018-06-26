# Akash Kandpal
# My Domain => http://harrypotter.tech/
from fractions import gcd
import math
from itertools import permutations

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
def permute(word):
    perms = [''.join(p) for p in permutations(word)]
    # print perms
    return set(perms)

a = readInt()
while(a):
    a-=1
    b=input()
    c=readInts()
    w=[0]*b
    for i in range(b):
        s=0
        j=i+1
        while(s<=c[i] and j<b):
            if(s<=c[i]):
                w[j]+=1
                s+=c[j]
                j+=1
            else:
                break
        s=0
        j=i-1
        while(s<=c[i] and j>-1):
            if(s<=c[i]):
                w[j]+=1
                s+=c[j]
                j-=1
            else:
                break
    for i in range(b):
        print w[i],
    print


'''
Input:

2
4
4 3 2 1
5
1 2 2 3 1

Output:

1 2 3 2
2 3 2 3 1

'''
