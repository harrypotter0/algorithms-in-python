import math
def readInts():
    return list(map(int, raw_input().split()))
def readInt():
    return int(input())
def readIntsindex0():
    return list(map(lambda x: int(x) - 1, input().split()))
def readStr():
    return raw_input()

t = int(raw_input())

while t>0:
    t-=1
    n = int(raw_input())
    a = n*n+2*n+1
    b = n*(n+1)  # summation  n
    c = b*(2*n+1) # summation n2
    d = b*b  # summation n3
    e = (2*n+2)
    num = (a*b)/2+d/4-(e*c)/6
    den = (a*n)+c/6-(e*b)/2
    # print(num,den)
    print num/den
