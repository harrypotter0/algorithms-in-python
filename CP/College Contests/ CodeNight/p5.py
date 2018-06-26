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

MOD = 10 ** 9 + 7

# for __ in range(readInt()):
n = readInt()
A = readInts()
B = readInts()
# print A,B
L=[]
M=0
for i in range(n):
    if(A[i]>=B[i]):
        L.append('No Turn')
        M+=A[i]
    else:
        L.append('Turn')
        M+=B[i]

A.reverse()
B.reverse()
for i in range(2**n):
    suma=0
    for j in range(n):
        if(i & (1<<j)):
            suma+=B[j]
        else:
            suma+=A[j]
    print suma
print M,L

'''
4
11 2 3 4
4 5 6 7

20
23
23
26
23
26
26
29
13
16
16
19
16
19
19
22
29 ['No Turn', 'Turn', 'Turn', 'Turn']


'''
