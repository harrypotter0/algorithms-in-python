t=input()
for i in range(t):
    n=input()
    arr=map(int,raw_input().split())
    s=sum(arr)
    if s%4!=0:
        print -1
    else:
        a,b,c=[0,0,0]
        for i in arr:
            if i%4==1:
                a+=1
            elif i%4==2:
                b+=1
            elif i%4==3:
                c+=1
        #print a,b,c
        #a,b,c=[2,5,8]
        ans=0
        ans+=min(a,c)
        ans+=b/2
        oth=max(a,c)-min(a,c)
        #print a,b,c
        if b%2==0:
            ans+=3*(oth/4)
        else:
            ans+=2+3*((oth-2)/4)
        print ans
