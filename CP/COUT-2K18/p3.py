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

def primeFactors(n):
    a = set()
    while n % 2 == 0:
        a.add(2)
        n = n / 2

    for i in range(3,int(math.sqrt(n))+1,2):
        # while i divides n , print i ad divide n
        while n % i== 0:
            # print i,
            a.add(i)
            n = n / i

    if n > 2:
        a.add(n)
    return a

for __ in range(readInt()):
    n = readInt()
    ans = []
    # ans.clear()
    # del ans[:]
    ans = primeFactors(n)
    # print(ans)
    # print("Sorted version :",sorted(ans))

    ans = list(ans)
    ans = sorted(ans)
    for i in range(len(ans)):
        print(ans[i]),
    print


'''
Input:
5
2
3
4
5
48
Output:
2
3
2
5
2 3
'''
