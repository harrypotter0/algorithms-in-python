# I love u, always have, wanna marry u :-)

def ncr(n,r):
	r = min(r,n-r);
	num = 1;
	den = 1;
	for i in range(0,r):
		num = num * (n-i)
		den = den * (r-i)
	return num/den
t = input()
while(t!=0):
    s = raw_input().split()
    n = int(s[0])
    k = int(s[1])
    ans = 0;
    ans = ncr(k + (n-k) - 1 , k-1)
    print ans
    t-=1
    
'''
if __name__ == '__main__':
    main()
'''
