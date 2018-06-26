t=int(input())
while t:
    s1=input()
    a=[]
    s=set(s1)
    if len(s)>=3:
        for i in s:
            a.append(s1.count(i))
        a=sorted(a)
        l=len(a)
        f=0
        for i in range(2,l):
            if a[i]==a[i-1]+a[i-2]:
                f=1
                break
        if f==1:
            print("Dynamic")
        else:
            print("Not")
    else:
        print("Dynamic")
    t=t-1
