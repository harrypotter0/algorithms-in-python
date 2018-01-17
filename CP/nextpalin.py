t=int(raw_input())
for x in range(t):
	s=raw_input()
	l=len(s)
	if(s.count('9')==l):
		print(str(long(s)+2))
	else:
		if(l%2==0):
			rev=''.join(reversed(s[:l/2]))
			if(rev>s[l/2:]):
				print s[:l/2]+rev
			else:
				revs=str(long(s[:l/2])+1)
				print revs+''.join(reversed(revs))
		else:#odd
			rev=''.join(reversed(s[:l/2]))
			if(rev>s[(l/2)+1:]):
				print s[:l/2+1]+rev
			else:
				d=int(s[l/2])+1
				if(d==10):
					revs=str(long(s[:l/2])+1)
					print revs+'0'+''.join(reversed(revs))
				else:
					print s[:l/2]+str(d)+rev
