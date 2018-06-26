def readInts():
    return list(map(int, input().split()))
def readInt():
    return int(input())
def readIntsindex0():
    return list(map(lambda x: int(x) - 1, input().split()))


n, k = readInts()
a = readInts()

best = -1
sel = -1
for i in range(k):
    cur = n - n % a[i]
    if best < cur:
        best = cur
        sel = i

print('%d %d' % (sel + 1, n // a[sel]))
