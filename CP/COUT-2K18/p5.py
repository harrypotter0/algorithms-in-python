from itertools import groupby
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

for _ in range(readInt()):
    n, m = readInts()
    grid = [raw_input().strip() for __ in range(n)]
    # print(grid)
    ans = -1
    for r in grid:
        a = [len(list(g)) for k, g in groupby(r)]
        ans = max(ans, max(a))
    print(ans)
    for c in zip(*grid):
        a = [len(list(g)) for k, g in groupby(c)]
        ans = max(ans, max(a))
    # print(ans)



'''
2
3 3
aaa
abc
dca
2 3
fgh
frq


3
2
'''
