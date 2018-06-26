
from fractions import gcd
import math
def readInts():
    return list(map(int, raw_input().strip().split()))
def readInt():
    return int(raw_input())
def readIntsindex0():
    return list(map(lambda x: int(x) - 1, input().split()))
def readStrs():
    return raw_input().split()
def readStr():
    return raw_input()
def numlistTostr(list1):
    return ''.join(list1)
def strlistTostr(list1):
    return ''.join(str(e) for e in list1)
def strTolist(str):
    return str.split()
def strlistTointlist(str):
    return map(int, str)
def slicenum(number,x):
    return int(str(number)[:x])
def precise(num):
    return "{0:.10f}".format(num)
def rsorted(a):
    return sorted(a,reverse=True)
def binar(x):
    return '{0:031b}'.format(x)


bitln = 31
n,q = readInts()
ar = readInts()

# list created here
biar = map(binar,ar)
# print biar

bits = []

for i_ in range(bitln):
    bits.append([0,0])

# print bits

prfxar = []
prfxar.append([(0,0)]*bitln)
# print prfxar

for i in range(n):
    tmp = [(0,0)]*bitln # 1 d array
    # print tmp
    for j in range(bitln):
        if biar[i][j] == '1':
            bits[j][1]+=1
        else:
            bits[j][0]+=1
        tmp[j] = bits[j][0],bits[j][1]
    prfxar.append(tmp)
    # print prfxar

# for  i in range(n):
#     print(prfxar[i])

for _ in range(q):
    l,r = map(int,raw_input().split())
    ans = 0
    for j in range(bitln):
        if (prfxar[r][j][1] - prfxar[l-1][j][1]) < (prfxar[r][j][0] - prfxar[l-1][j][0]):
            ans += 1<<(bitln-j-1)
            # print((bitln-j-1))

    print ans

# print(bits)


'''

5 3
20 11 18 2 13
1 3
3 5
2 4

'''
