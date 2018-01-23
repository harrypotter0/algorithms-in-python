from collections import deque
n, k = map(int, raw_input().split())
a = [i for i in xrange(64) if n >> i & 1]
if k < len(a):
    print 'No'
    quit()
s = a[-1]
c = 0
while len(a) + c < k:
    if a and s == a[-1]:
        c += 1
        a.pop()
    c = c * 2
    s -= 1
t = len(a) + c - k
a.reverse()
b = 0
if t:
    while t:
        c -= 2
        t -= 1
        b += 1
    if not a:
        c -= 1
        a.append(s)
    while c > 1:
        c -= 2
        b += 1
        a.extend([a.pop() - 1] * 2)
a = [s + 1] * b + [s] * c + a
print 'Yes'
for x in a:
    print x,
