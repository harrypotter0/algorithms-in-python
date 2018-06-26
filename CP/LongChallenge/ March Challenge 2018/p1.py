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
    a = readInts()
    b1 = readInts()
    b2 = list(reversed(b1))
    # print(b1,b2)
    f1=0
    for i in range(n):
        if(a[i]>b1[i]):
            f1=1
            break
    f2=0
    for i in range(n):
        if(a[i]>b2[i]):
            f2=1
            break
    if(f1==0 and f2==0):
        print("both")
    elif(f1==0):
        print("front")
    elif(f2==0):
        print("back")
    else :
        print("none")



'''

Input
4
3
1 2 3
2 3 4
3
1 2 1
1 2 1
3
3 2 1
1 2 3
4
1 3 2 4
1 2 3 5

Output
front
both
back
none

'''
