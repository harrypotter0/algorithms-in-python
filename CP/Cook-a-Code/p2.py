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
    a,b = readInts()
    arr = readInts()
    brr = readInts()
    win = 0 if(a>b) else: 1
    print(winner)
    c= [0 ,0]
    for i in range(len(arr)):
        if(arr[i]&1):
            c[0]+=1
    for i in range(len(brr)):
        if(brr[i]&1):
            c[1]+=1
    print(c[0],c[1])
    if(c[win]>=c[(win+1)%2]):
        print("alan")
    else:
        print("chef")



'''
Input:
1
3 2
1 2 3 8 9 10 11 4 5 6 7
21 31 43 52 11 36 22 11 23 17 8
Output:
chef
'''
