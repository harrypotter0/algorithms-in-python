for kandu in xrange(int(raw_input())):
    sum = 0
    n = int(input())
    for i in range(n):
        a = map(int, raw_input().split())
        a = sorted(a)
        sum+=abs(a[n-1]-a[0])
    print(sum)
