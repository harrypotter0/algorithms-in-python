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
    a = readStr()
    set1 = set()
    n = len(a)
    for i in range(n):
        if(a[i] in 'aeiou'):
            set1.add(a[i])
    sort = ''.join(sorted(set1))
    # print(set1)
    # print(sort)
    if(sort=='aeiou'):
        print(a)



'''
Input:
3
functionality
hamdard
eukaryotic

Output:
eukaryotic
'''
