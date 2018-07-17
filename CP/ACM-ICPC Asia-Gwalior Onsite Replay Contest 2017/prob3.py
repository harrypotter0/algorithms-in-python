# cook your code here
t=int(raw_input())
for a0 in xrange(t):
    a,k=map(float,raw_input().split())
    b=map(float,raw_input().split())
    # print a,k,b
    m=min(b)
    if m<0:
        for i in xrange(3):
            b[i]+=abs(m)
    [x1,x2,x3]=sorted(b)
    if (k >= (x3-x1)/2):  # k is the move we can take
        print float(a*a)
    else:
        if x3-x1-2*k>a: print float(0)
        else: print abs(x3-x1-2*k-a)*a
