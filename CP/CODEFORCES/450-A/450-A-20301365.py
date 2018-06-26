n,m=map(int,input().split())
l=list((i-1)//m for i in map(int,input().split()))
l.reverse()
print(n-l.index(max(l)))