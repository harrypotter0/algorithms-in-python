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
# arr = []
for __ in range(readInt()):
    n,m = readInts()
    arr =[]
    for i in range(n):
        arr.append(readInts())
    # print arr
    if(arr[0][0]==-1):
        arr[0][0]=1

    for i in range(n-1):
        if(arr[i+1][0]==-1):
            arr[i+1][0]=arr[i][0]

    for i in range(m-1):
        if(arr[0][i+1]==-1):
            arr[0][i+1]=arr[0][i]

    for i in range(1,n):
        for j in range(1,m):
            if(arr[i][j]==-1):
                arr[i][j]=max(arr[i-1][j],arr[i][j-1])

    flag = 0
    for i in range(n-1):
        for j in range(m-1):
            if(arr[i][j+1]<arr[i][j]):
                flag=1
                break
            if(arr[i+1][j]<arr[i][j]):
                flag=1
                break

    for i in range(n-1):
        if(arr[i+1][m-1]<arr[i][m-1]):
            flag=1
            break

    if(flag!=1):
        for i in range(n):
            for j in range(m):
                print(arr[i][j]),
            print
    else:
        print "-1"

'''
Input:

2
4 4
1 2 2 3
1 -1 7 -1
6 -1 -1 -1
-1 -1 -1 -1
2 3
1 4 -1
1 -1 3

1
3 4
-1 -1 -1 -1
-1 2 3 -1
-1 -1 -1 2
Output:

1 2 2 3
1 7 7 100
6 10 20 101
7 11 21 20000
-1
'''
