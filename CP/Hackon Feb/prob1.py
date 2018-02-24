def readInts():
    return list(map(int, input().split()))
def readInt():
    return int(input())
def readIntsindex0():
    return list(map(lambda x: int(x) - 1, input().split()))

t=input()
for __ in range(t):
    n = readInt()
    a = n//7
    print(7*(a*(a+1)//2))
