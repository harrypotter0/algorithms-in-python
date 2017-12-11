# I love u, always have, wanna marry u :-)
n,k = [int(x) for x in input().split()]
s = set()
count = 0
for line in range(k):
	inp = input()
	if inp=="CLOSEALL":
		s = set()
		count = 0
	else:
		c_no = int(inp.split()[1])
		if c_no in s:
			s.remove(c_no)
			count -= 1
		else:
			s.add(c_no)
			count += 1
	print(count)
    
