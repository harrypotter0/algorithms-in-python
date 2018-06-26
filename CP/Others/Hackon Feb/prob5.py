import math
def readInts():
    return list(map(int, raw_input().split()))
def readInt():
    return int(input())
def readIntsindex0():
    return list(map(lambda x: int(x) - 1, input().split()))

test = readInt()
for _ in range(test):
    X1, Y1, R1 = readInts()
    X2, Y2, R2 = readInts()
    d = math.sqrt(((X2 - X1) ** 2) + ((Y2 - Y1) ** 2))
    if d < abs(R1 - R2):
        if R1 > R2:
            print 'C1CC2'
        else:
            print 'C2CC1'
    elif d == (R1 - R2):
        print 'C2~C1'
    else:
        print 'NOT SATISFIED'
