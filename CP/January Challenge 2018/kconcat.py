int_min = -float('inf')

def kadane(a , k):
    n = len(a)
    temp = 0
    maxm = int_min
    while k :
        k -= 1

        for i in range(n):
            temp += a[i]
            if temp > maxm :
                maxm = temp

            if temp < 0 :
                temp = 0

    return maxm

t = int(raw_input())
for a0 in range(t):
    n,k = map(int , raw_input().split())
    arr = map(int , raw_input().split())

    sumi = 0
    maxi = -float('inf')

    s1 = kadane(arr , 1)
    s2 = kadane(arr , 2)
    s3 = kadane(arr , 3)
    s4 = kadane(arr , 4)

    if s1 == s2 :
        print s1
    else :
        if k == 1 :
            print s1
        elif k == 2:
            print s2
        elif k == 3 :
            print s3
        else :
            print s3 + (k-3)*(s4-s3)
