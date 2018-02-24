import math
def readInts():
    return list(map(int, raw_input().split()))
def readInt():
    return int(input())
def readIntsindex0():
    return list(map(lambda x: int(x) - 1, input().split()))


import math

def solve():
    # T=int(input())
    # for y in range(T):
    k=int(input())
    if k==1:
        print(5)
    else:
        base=int(math.log(k+1,2))
        diff=(k+1)-(2**base)
        val=bin(diff)[2:] # to remove 0b
        l=len(val)
        # print(val,base,l)
        ans = ""
        if l!=base:
            val='0'*(base-l)+val
            # print("an improvement",val)
        for i in val:
            if i=='0':
                ans += "5"
            else:
                ans += "8"
        print(ans)
t = int(input())
for i in range(t):
    solve()
'''

Input:
3
1
5
11

Output:
5
85
8555

'''
