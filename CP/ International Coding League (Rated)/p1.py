 # International Coding League (Rated)

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
def numlistTostr(list1):
    return ''.join(list1)
def strlistTostr(list1):
    return ''.join(str(e) for e in list1)
def strTolist(str):
    return str.split()
def strlistTointlist(str):
    return map(int, str)
def slicenum(number,x):
    return int(str(number)[:x])
def numTobin(A):
    s = str(bin(A))[2:]
    s = '0'*(31-len(s)) + s
    return s
def precise(num):
    return "{0:.10f}".format(num)
def rsorted(a):
    return sorted(a,reverse=True)

for __ in range(readInt()):
    n,m = readInts()
    arr,a = [],[]
    for i in range(n):
        arr.append(readInts())
    for i in range(n):
        for j in range(m):
            a.append(arr[i][j])
    # print(arr)
    # print(a)
    a= rsorted(a)
    # print(a)
    sum1,sum2 =0,0
    for i in range(len(a)):
        if(i&1):
            sum2+=a[i]
        else:
            sum1+=a[i]
    if(sum2==sum1):
        print("Draw")
        # print(sum1,sum2)
    elif(sum2>sum1):
        print("Geno")
        # print(sum1,sum2)
    else:
        print("Cyborg")
        # print(sum1,sum2)




'''
3
1 1
3
2 3
4 4 4
4 4 4
2 3
4 3 4
4 4 4

Sample Output

Cyborg
Draw
Cyborg

Geno
'''
