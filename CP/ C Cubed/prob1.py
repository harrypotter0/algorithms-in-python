import math
import statistics
import itertools

def findsubsets(S,m):
    return set(itertools.combinations(S, m))
def readInts():
    return list(map(int, input().split()))
def readInt():
    return int(input())

n = readInt()
a = []

for __ in range(n):
    inp = readInt()
    if(inp>=0):
        a.append(inp)
n = len(a)
# print(a)

summ = 0

for i in range(1,len(a)+1):
    s = []
    if(i&1):
        s = findsubsets(a,i)
        s = list(s)
        for j in range(len(s)):
            med = statistics.median(s[j])
            summ+=med
print(summ)


'''
4
0
1
3
2

9
6
-9
7
2
-2
3
2
0
1

4
1
2
2
-2
'''
