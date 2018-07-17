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
def slicenum(number,x):
    return int(str(number)[:x])

for __ in range(readInt()):
    n = readInt()
    a,b,c = [],[],[]
    for i in range(n):
        num = readInt()
        a.append(num)
        b.append(num%10)
        c.append(slicenum(num,1))
    # print(a)
    # print(b)
    # print(c)
    co =0
    for i in range(len(a)):
        if(b[i] in c):
            co+=1
    # print(co)
    if(co==len(a)-1):
        print("The door will be opened")
    else:
        print("The door cannot be opened")
'''



Input:
3
3
67
96
59
3
43
64
32
2
12
34

Output:
The door will be opened
The door will be opened
The door cannot be opened
'''
