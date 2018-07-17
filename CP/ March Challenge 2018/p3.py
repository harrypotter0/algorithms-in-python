import math
def readInts():
    return list(map(int, raw_input().strip().split()))
def readInt():
    return int(raw_input())
def readIntsindex0():
    return list(map(lambda x: int(x) - 1, input().split()))
def readStr():
    return raw_input()

for __ in range(readInt()):
    n = readInt()
    arr = readInts()
    summ =0
    arr = sorted(arr)
    # if(arr[0]==arr[n-1]):
    #     n-=1
    #     print(n*(n+1)/2)
    #     continue
    for i in range(n-1):
        if(arr[i]==arr[i+1]):
            summ+=1
    # for i in range(n-1,0,-1):
    #     arr = reversed(sorted(arr))
    #     if(arr[i]==arr[i-1]):
    #         # print(arr[i],arr[i-1])
    #         s1 = 1
    #         for j in arr:
    #             s1=1
    #             s = arr[i-1]+j
    #             if(s not in arr and ):
    #                 summ+=s1
    #                 arr[i-1]=s
    #                 break
    #             else:
    #                 s1+=1
    #         print(s,arr)

    print(summ)




'''

Input:

2
3
1 2 3
3
2 1 2

1
4
2 2 2 2

Output:

0
1

'''
