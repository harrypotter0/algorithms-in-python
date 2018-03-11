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
    n = readInt()
    a = readInts()
    r = readInts()
    sum = 0
    for i in range(n):
        sum += a[i]*pow(r[i],3)
    print(sum)

'''
Input:
1
3
2 2 2
3 1 2

Output:
72
'''
