for __ in range(int(input())):
    n = int(raw_input())
    # map(int, raw_input().split())
    a = [0,0,0]
    b = [100,100,100]
    for i in range(n):
        [c,l,x] = map(int, raw_input().split())
        if x>a[l-1]:
            a[l-1]=x
            b[l-1]=c
        elif x==a[l-1]:
            if b[l-1]>c:
                b[l-1]=c
    for i in xrange(3):
        print str(a[i])+' '+str(b[i])
