def readInts():
    return list(map(int, raw_input().strip().split()))
def readInt():
    return int(raw_input())

for __ in range(readInt()):
    n,k = readInts()
    arr =readInts()
    sumi =sum(arr)
    # print sumi
    if(sumi%n==0 ):
        print sumi/n
        continue
    maxi = 0
    t = 0
    for i in range(k+1):
        for j in range(i):
            sumi = sum(arr[j:i])
            # print sumi,maxi
            if(sumi%n==0 and sumi>maxi):
                maxi = sumi
            if(t>100000):
                break
            # sumi = sum(arr[])
    print maxi/n

'''
input
1
3 7
2 7 3 4 4 5 2
output:
6
'''
