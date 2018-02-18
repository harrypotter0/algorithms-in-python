def readInts():
    return map(int, input().split())
def readInt():
    return int(input())
def readIntsindex0():
    return list(map(lambda x: int(x) - 1, input().split()))

n = readInt()
a = readIntsindex0()
ans = False

for i in range(n):
    if a[a[a[i]]] == i:
        ans = True
        break

print('YES' if ans else 'NO')

'''
5
2 4 5 1 3

5
4 2 1 3 5

5
4 1 2 3 5


5
5 5 5 5 1


'''
