import math
t = int(raw_input())
for ti in xrange(t):
    n, a, b, c = map(int, raw_input().split())
    arr = []
    upper = int(math.pow(n, 0.5))
    for i in xrange(1, upper+1):
        if n % i == 0:
            arr.append(i)
            if n/i != i:
                arr.append(n/i)
    print arr
    arr.sort()
    x1 = 0
    x2 = 0
    x3 = 0
    count = 0
    L = len(arr)
    print arr
    present = [[0 for i in xrange(L)] for j in xrange(L)]
    while(x1<L and arr[x1]<=a):
        temp2 = n/arr[x1]
        x2 = 0
        while(x2<L and arr[x2]<=b and arr[x2]<=temp2):
            if temp2 % arr[x2] != 0:
                x2 += 1
                continue
            temp3 = temp2 / arr[x2]
            if temp3 > c:
                x2 += 1
                continue
            if present[x1][x2] == 1:
                x2 += 1
                continue
            present[x1][x2] = 1
            count += 1
            # print arr[x1], arr[x2], temp3
            # print "va: ", x1, x2
            x2 += 1
        x1 += 1
    print count

'''

1
100 8 23 11
1 1 2 3

'''
