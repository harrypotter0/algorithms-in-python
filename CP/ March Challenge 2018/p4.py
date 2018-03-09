import math
def readInts():
    return list(map(int, raw_input().strip().split()))
def readInt():
    return int(raw_input())
def readIntsindex0():
    return list(map(lambda x: int(x) - 1, input().split()))
def readStr():
    return raw_input()

def binarySearch (arr, l, r, x):

    # Check base case
    if r >= l:

        mid = l + (r - l)/2

        # If element is present at the middle itself
        if arr[mid] == x:
            return mid

        # If element is smaller than mid, then it
        # can only be present in left subarray
        elif arr[mid] > x:
            return binarySearch(arr, l, mid-1, x)

        # Else the element can only be present
        # in right subarray
        else:
            return binarySearch(arr, mid+1, r, x)

    else:
        # Element is not present in the array
        return -1

for __ in range(readInt()):
    n,h = readInts()
    arr = readInts()
    summ = 0
    for i in arr:
        summ+=i
    arr = sorted(arr)
    summ = float(summ)
    minn = int(math.ceil(summ/h))
    maxn = arr[n-1]
    if(n==h):
        print(arr[n-1])
        continue
    # print(minn)
    for i in range(minn,maxn+1):
        s=0
        for j in reversed(arr):
            if(j > i):
                s+=(int(math.ceil(j/i))-1)
            else:
                break
        if(n+s<=h):
            print(i)
            break
    #     # print("loda")


'''

Input:
1
4 5
4 3 2 100

Output:
3
2
4

'''
