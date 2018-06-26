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
    n = readInt()
    summ = 0
    for i in range(n):
        arr = readInts()
        p = arr[0]
        q = arr[0]*(1.+arr[2]/100.)*(1.-arr[2]/100.)
        # print(p,q)
        profit = p-q
        summ+=profit*arr[1]
    print(summ)

'''
     pricei, quantityi and discounti.


Input:

2
2
100 5 10
100 1 50
3
10 10 0
79 79 79
100 1 100

Output:

30.000000000
3995.0081000

'''
