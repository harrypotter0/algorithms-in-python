for _ in range(int(raw_input())):
	n,k,b=map(int,raw_input().split())
	a=map(int,raw_input().split())
	a.sort()
	x=(a[0]*k)+b
	cnt=0
	for i in range(1,n):
		if a[i]>=x:
			cnt+=1
			x=(a[i]*k)+b
	print cnt+1
