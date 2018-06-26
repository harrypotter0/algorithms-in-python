n=int(input())
a=list(map(int,input().split()))
b=[0]*n
mx=a[n-1]
for i in range(n-2,-1,-1):
	b[i]=max(0,mx-a[i]+1)
	if a[i]>mx:mx=a[i]
print(*b)