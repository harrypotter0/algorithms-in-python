for _ in range(input()):
    n,m=map(int,raw_input().split())
    a=map(int,raw_input().split())
    a.sort()
    x=-10**8
    for i in range(m-1):
        if a[i+1]-a[i]>x:
            x=a[i+1]-a[i]
    x=x/2
    x=max(x,a[0],n-1-a[m-1])
    print x
