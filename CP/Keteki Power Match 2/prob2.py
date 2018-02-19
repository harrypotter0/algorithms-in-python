def readInts():
    return map(int, raw_input().split())
def readInt():
    return int(input())

for __ in range(readInt()):
    r,b,m = readInts()
    ans = 0
    for i in range(m+1):
        j = m-i
        # print(i,j,r,b)
        if i>r or j>b:
            continue
        ans+=1
    print ans

'''

Input:
2
1 1 2
3 2 2
Output:
1
3

'''
