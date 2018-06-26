for kohli in range(int(raw_input())):
	x,n=map(int,raw_input().split(' '))
	su=(n*(n+1))/2-x
	if n<=3:
		print 'impossible'
	elif su%2==1:
		print 'impossible'
	else:
		su=su/2
		a=['0']*n
		a[x-1]='2'
		z=n-1
		while z>=0:
			if a[z]!='2' and (z+1)<=su:
				su=su-z-1
				a[z]='1'
			z=z-1

        # Case 1 17
		if su!=0 and x==1:
			a[x-1]='2'
			for i in range(len(a)):
				if a[i]=='1':
					a[i]='0'
					a[i-1]='1'
					a[x]='1'
					a[x-1]='2'
					break
        # Case : 2 8
		if su!=0 and x==2:
			a[x-1]='2'
			a[0]='0'
			for i in range(len(a)):
				if a[i]=='1':
					a[i]='0'
					a[i-1]='1'
					a[x]='1'
					a[x-1]='2'
					break
		print "".join(a)
