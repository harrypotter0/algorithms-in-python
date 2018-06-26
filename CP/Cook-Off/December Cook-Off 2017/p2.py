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

mod = 10 ** 9 + 7

for __ in range(readInt()):
    n = readInt()
    arr = readInts()
    if sum(arr)%4 != 0:
        print -1
        continue
    else:
        a1,a2,a3=[],[],[]
        for i in range(n):
            if(arr[i]%4==1):
                a1.append(arr[i])
            elif(arr[i]%4==2):
                a2.append(arr[i])
            elif(arr[i]%4==3):
                a3.append(arr[i])
        a,b,c = len(a1),len(a2),len(a3)
        # a/=4
        # b/=2
        # c/=4
        # print a,b,c
        sumi =0
        temp = min(a,c)
        sumi+=temp
        a-=temp
        c-=temp
        sumi+=b/2
        b=b&1
        temp =max(a,c)
        if b%2==0:
            sumi=sumi+(temp/4)*3
        else:
            sumi=sumi+2+(temp/4)*3
        print sumi
'''
1
7
1 2 3 1 2 3 8

3
'''
