# I love u, always have, wanna marry u :-)
def re(l):
    n=len(l)
    l2=[]
    for i in range(0,len(l)):
        l2.insert(i-l[i],i)
    return l2

for t in range(input()):
    n=input()
    l2=map(int,raw_input().split())
    l3=re(l2)
    d={}
    for i in range(len(l3)):
        d[l3[i]+1]=i+1
    for i in d:
        print d[i],
    print
