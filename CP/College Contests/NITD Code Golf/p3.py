import math
def readInts():
    return list(map(int, raw_input().strip().split()))
def readInt():
    return int(raw_input())
# def printDivisors(n) :
#     i = 1
#     arr =[]
#     while i <= n :
#         if (n % i==0) :
#             arr.append(i)
#
#         i = i + 1
#     return len(arr)

def printDivisors(n) :
    i = 1
    arr =[]
    while i <= math.sqrt(n):
        if (n % i == 0) :
            if (n / i == i) :
                arr.append(i)
            else :
                arr.append(i)
                arr.append(n/i)
        i = i + 1
    return len(arr)

for __ in range(readInt()):
    n = readInt()
    for i in range(100000):
        num = n+i+1
        if(printDivisors(num)==2):
            print num
            break
