import math
def readInts():
    return list(map(int, raw_input().strip().split()))
def readInt():
    return int(raw_input())
def readIntsindex0():
    return list(map(lambda x: int(x) - 1, input().split()))
def readStr():
    return raw_input()

for __ in range(readInt()):
    n,h = readInts()
    a = readInts()
    a = sorted(a)
    diff = h-n
    if(n==h):
        print(a[n-1])
        continue
    for i in range(diff):
        if(a[n+i-1]/2<=1):
            break
        j = a[n+i-1]/2
        a[n+i-1] -= j
        a.append(j)
        a = sorted(a)
    print(int(a[n+i]))


'''

Input:
1
4 5
4 3 2 100

1
4 6
4 3 2 100

1
7 15
1 1 1 1 1 1 1

1
5 12
232 43 213 2431 431

1
4 5
4 3 2 7

3
3 3
1 2 3
3 4
1 2 3
4 5
4 3 2 7

2
6 9
12 35 45 34 32 213
4 5
4 3 2 7

'''
