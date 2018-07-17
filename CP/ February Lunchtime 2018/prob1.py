for t in xrange(input()):
    n,u,d=map(int,raw_input().split())
    l=map(int,raw_input().split())
    cnt=1
    flag=1
    for i in xrange(1,n):
        if l[i]-l[i-1]>u:
            break
        if l[i]<=l[i-1]+u and l[i]>=l[i-1]-d:
            cnt+=1
        else:
            if flag:
                flag=False
                cnt+=1
            else:
                break
    print cnt
