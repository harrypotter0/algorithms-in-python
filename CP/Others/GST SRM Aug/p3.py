def readInts():
    return list(map(int, raw_input().strip().split()))
def readInt():
    return int(raw_input())

for __ in range(readInt()):
    arr,brr = [],[]
    n = readInt()
    arr = readInts()
    m = readInt()
    brr =readInts()
    a = set(arr)-set(brr)
    print n-len(list(a))

'''
Input:
1
5
10 20 30 40 50
5
22 30 32 45 50
Output:
2
'''
