for tc in xrange(1,1+input()):
		n,k = map(int,raw_input().strip().split())
		s = raw_input().strip()
		bs = []
		na = 0
		for i in s:
				if i=='a':
						na+=1
				elif i=='b':
						bs.append(na)
		nb = len(bs)
		ans_pre = sum(bs)
		ans = ans_pre*k
		ans+=na*nb*k*(k-1)/2
		print ans
 
