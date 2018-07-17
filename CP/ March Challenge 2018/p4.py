import math
def readInts():
    return list(map(int, raw_input().strip().split()))
def readInt():
    return int(raw_input())
def readIntsindex0():
    return list(map(lambda x: int(x) - 1, input().split()))
def readStr():
    return raw_input()


for m in range(readInt()):
    strings = raw_input().split(" ")
    N= int(strings[0])
    H= int(strings[1])
    strings1=raw_input().split(" ")
    A= map(int, strings1)
    maxi = A[0]
    sumi = 0
    for i in range(len(A)):
        sumi += A[i]
        if(maxi < A[i]):
            maxi = A[i]
    flag=True
    #suitable values of K
    avg = sumi/H
    low = avg
    high = maxi
    #######################################3
    hr = 0
    while(low<=high):
        mid = (low+high)/2
        hr = 0
        for j in range(len(A)):
            if( A[j]%mid != 0):
                hr += A[j]/mid + 1
            else:
                hr += A[j]/mid
        if(hr <= H):
            ans = mid
            high = mid - 1
        else:
            low = mid  + 1
    print ans


'''

Input:
1
4 5
4 3 2 100

1
4 6
4 3 2 100

1
7 15
1 1 1 1 1 1 1

1
5 12
232 43 213 2431 431

1
4 5
4 3 2 7

3
3 3
1 2 3
3 4
1 2 3
4 5
4 3 2 7

2
6 9
12 35 45 34 32 213
4 5
4 3 2 7

'''
