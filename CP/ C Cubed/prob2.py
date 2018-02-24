import math
from itertools import combinations

def readInts():
    return list(map(int, input().split()))
def readInt():
    return int(input())
def readIntsindex0():
    return list(map(lambda x: int(x) - 1, input().split()))
def readStr():
    return raw_input()
def euclid(x1,y1,x2,y2):
    return math.sqrt(pow(x1-x2,2)+pow(y1-y2,2))
def manhat(x1,y1,x2,y2):
    return abs(x1-x2)+abs(y1-y2)

n = readInt()
a = []
for i in range(n):
    a.append(readInts())
# print(a)
ans =0
count =0
a = combinations(a, 2)
for i in list(a):
    # print(i)
    count+=1
    # print(euclid(i[0][0],i[0][1],i[1][0],i[1][1]),manhat(i[0][0],i[0][1],i[1][0],i[1][1]))
    if(euclid(i[0][0],i[0][1],i[1][0],i[1][1])==manhat(i[0][0],i[0][1],i[1][0],i[1][1])):
        # print(i[0][0],i[0][1],i[1][0],i[1][1])
        ans += 1
print(ans)


'''

Input:
3
1 1
7 5
1 5

Output:
3

Input:
6
0 0
0 1
0 2
-1 1
0 1
1 1

Output:
12


'''
