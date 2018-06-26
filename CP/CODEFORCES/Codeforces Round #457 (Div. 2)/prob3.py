n, m = map(int, raw_input().split())
t = k = 100000007
print 2, (k if n != 2 else 2)
print 1, n, 2
k -= 2
for i in range(2, n):
	print 1, i, k / (n - 2) + (k % (n - 2) if i == 2 else 0)
u, v = 2, 2
for i in range(n - 1, m):
	v += 1
	if v > n:
		u += 1
		v = u + 1
	print u, v, t
