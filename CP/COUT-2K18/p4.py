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
    a = readStr()
    i=0
    count =0
    print(a.count("010"))



'''
Input:

2
5
11010
3
101

Output:

1
0
'''
