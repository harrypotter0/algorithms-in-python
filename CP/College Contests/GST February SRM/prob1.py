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
    arr = readInts()
    f=0
    for i in range(1,len(arr)):
        if(arr[i]%10!=7):
            print arr[i],
            f=1
        elif(f==0 and i==len(arr)-1):
            print 




'''
Input:
2
4 7 17 27 37
7 21 67 98 34 17 23 16

Output:

21 98 34 23 16

'''
