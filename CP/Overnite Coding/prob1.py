import math
def readInts():
    return list(map(int, raw_input().split()))
def readInt():
    return int(input())
def readIntsindex0():
    return list(map(lambda x: int(x) - 1, input().split()))
def readStr():
    return raw_input()

for __ in range(readInt()):
    n,m = readInts()
    m = m*(m+1)/2
    # print(n,m)
    if(n>=m):
        print("YES")
    else:
        print("NO")


'''
Input:
1
5 2

Output:
YES
'''
