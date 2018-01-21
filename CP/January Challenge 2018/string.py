def lcs(X , Y):
    # find the length of the strings
    m = len(X)
    n = len(Y)

    # declaring the array for storing the dp values
    L = [[None]*(n+1) for i in range(m+1)]

    """Following steps build L[m+1][n+1] in bottom up fashion
    Note: L[i][j] contains length of LCS of X[0..i-1]
    and Y[0..j-1]"""
    for i in range(m+1):
        for j in range(n+1):
            if i == 0 or j == 0 :
                L[i][j] = 0
            elif X[i-1] == Y[j-1]:
                L[i][j] = L[i-1][j-1]+1
            else:
                L[i][j] = max(L[i-1][j] , L[i][j-1])

    # L[m][n] contains the length of LCS of X[0..n-1] & Y[0..m-1]
    return L[m][n]

for _ in range(int(input())):
	n,m = input().split()
	n,m = int(n),int(m)
	a = input()
	b = input()
	i=1
	pre=a[0]
	c=""
	c+=pre
	while i<n:
		if a[i]!=pre:
			 pre = a[i]
			 c += pre
		i+=1
	a=c
	i=1
	pre=b[0]
	c=""
	c=pre
	while i<m:
		if b[i]!=pre:
			 pre = b[i]
			 c += pre
		i+=1
	b=c
	n=len(a)
	m=len(b)
	lc = lcs(a,b)
	f1 = n-lc
	f1+= (m-lc)+lc
	print(f1)
