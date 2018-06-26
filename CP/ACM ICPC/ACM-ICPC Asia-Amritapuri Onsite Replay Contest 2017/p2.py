from sys import stdin
t = int(stdin.readline())
def gcd(a,b):
    while a%b:
        x = a%b
        a=b
        b=x
    return b
for _ in xrange(t):
    a,b,c = map(int,stdin.readline().split())
    d,e,f = map(int,stdin.readline().split())
    x1,x2 = map(int,stdin.readline().split())
    den = 6
    num = 2 * (a-d) * (x1**3 - x2**3) + 3 * (b-e) * (x1**2 - x2**2) + 6 * (c-f) * (x1 - x2)
    if num < 0:
        num = -num
    g = gcd(num,den)
    print "%d/%d"%(num/g,den/g)
