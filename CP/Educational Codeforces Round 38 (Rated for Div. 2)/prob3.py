ps = [False]*(10**5)
ps[0] = True
ps[1] = True
for i in range(len(ps)):
    if not ps[i]:
        for k in range(i*i, i, len(ps)):
            ps[k] = True
primes = [i for i, v in enumerate(ps) if not v]

t = int(raw_input())
for _ in range(t):
    x = int(raw_input())
    divs = set([1])
    xol = x
    if x == 0:
        print("1 1")
        continue
    for p in primes:
        if x <= 1: break
        while x%p == 0:
            d2 = set()
            for d in divs:
                d2.add(d*p)
            divs |= d2
            x //= p
    ok = False
    for d in divs:
        d1, d2 = d, xol//d
        if (d1+d2)%2 == 0:
            n, nm = (d1+d2)//2, (max(d1,d2) - min(d1, d2))//2
            if nm == 0: continue
            m1 = n//nm
            m2 = n//nm + 1
            if m1 > 0 and n//m1 == nm:
                print("{} {}".format(n, m1))
                ok = True
                break
            if m2 > 0 and n//m2 == nm:
                print("{} {}".format(n, m2))
                ok = True
                break
    if not ok:
        print(-1)
