import math
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


for __ in range(readInt()):
    m,n = readInts()
    a = readInts()
    c = 0
    for i in range(n-1):
        c= c+1
        c=c-min(c,a[i+1]-a[i]-1)
    c=c+1
    c=c-min(c,m-a[-1])
    if c==0:
        print 1
    else:
        print c


'''
Input:
2
5 5
1 2 3 4 5
5 2
1 3
Output:
5
1
'''
