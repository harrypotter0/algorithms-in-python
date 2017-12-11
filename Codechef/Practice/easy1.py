# I love u always have wanna marry u :-)
for z in range(int(input())):
    n,m=list(map(int,input().split()))
    arr=list(map(int,input().split()))
    arr.sort()
    j=1
    c,a=[],[]
    for i in range(1,n+1):
        if j&1 and not i in arr :
            c.append(i)
            j+=1
        elif not j&1 and not i in arr :
            a.append(i)
            j+=1
    for i in c:
        print(i,end=" ")
    print()
    for i in a:
        print(i,end=" ")
    print()
