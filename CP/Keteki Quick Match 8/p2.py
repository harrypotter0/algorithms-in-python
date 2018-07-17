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
    x,y=readInts()
    a=[]
    for i in range(x):
        a.append(readInts())
    first=second=0
    for i in range(x):
        for j in range(y):
            if((i+j)%2 == a[i][j]%2):
                first+=1
            else:
                second+=1
    print(min(first//2,second//2))
    # print(first,second)

'''
Example input:
2
1 2
3 2
3 3
1 0 1
1 0 0
1 0 1

Example output:
0
1
'''
