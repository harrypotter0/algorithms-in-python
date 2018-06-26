# Akash Kandpal
# My Domain => http://harrypotter.tech/

from fractions import gcd
import math
from itertools import permutations
from itertools import combinations

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
def numTobin(A):
    s = str(bin(A))[2:]
    s = '0'*(31-len(s)) + s
    return s
def precise(num):
    return "{0:.10f}".format(num)
def rsorted(a):
    return sorted(a,reverse=True)
def permute(word):
    perms = [''.join(p) for p in permutations(word)]
    # print perms
    return set(perms)
def combinate(word):
    perms = [''.join(p) for p in combinations(word)]
    # print perms
    return set(perms)


for __ in range(readInt()):
    a = readStr()
    b = readStr()
    a = a.lower()
    n,m = len(a),len(b)
    b = b.lower()
    per =set()
    per = permute(a)
    list1 = []
    c = 0
    per =list(per)
    for i in per:
        if(i in b):
            c+=1
            list1.append(i)
    print c
    list1.sort()
    for i in list1:
        print i

'''
Input:
1
Sam
msatmas
Output:
2
mas
msa

1
fuck
kucfdsnsdcukfsnjaaukcfkskfucjcmfhfcckucf
'''
