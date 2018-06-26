def inp(): return input()

def inpv(): return [int(x) for x in raw_input().split()]

MOD = 10 ** 9 + 7

def chefptnt():
    for _ in range(input()):
        n, m, x, k = map(int,raw_input().split())
        s = raw_input().strip()
        ev = 0
        for c in s: ev += c == 'E'
        odd = len(s) - ev
        mx = 0
        for i in range(1,m+1):
            if i & 1:
                v = min(odd, x)
                odd -= v
            else:
                v = min(ev, x)
                ev -= v
            mx += v
        print 'yes' if mx >= n else 'no'

chefptnt()


'''
3
4 4 2 4
EEOO
4 3 1 4
EEOO
6 4 2 6
EEEOOO
'''
