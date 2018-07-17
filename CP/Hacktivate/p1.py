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
     n,k= readInts()
     arr = readInts()
     arr = sorted(arr)
     diff = k-arr[0]
     if(diff>0):
         print(k-arr[0])
     else:
         print("0")






'''
Sample Input 0

3
5 3
1 2 3 4 5
6 9
1 1 1 1 1 1
3 -1
1 2 4
Sample Output 0

2
8
'''
