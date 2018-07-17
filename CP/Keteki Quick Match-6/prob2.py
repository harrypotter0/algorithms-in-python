for kohli in range(int(input())):
	n,k = map(int,raw_input().split())
	a = list(map(int,raw_input().split()))
	t = 1e10
	for i in range(len(a)-k+1):
		t = min(t, max(a[i:i+k]))
	print(t)
