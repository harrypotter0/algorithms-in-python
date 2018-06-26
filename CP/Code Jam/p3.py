from fractions import gcd
import math
from itertools import permutations
from itertools import combinations
import calendar
from itertools import product
def readInts():
    return list(map(int, raw_input().strip().split()))
def readInt():
    return int(raw_input())
def readStrs():
    return raw_input().split()
def readStr():
    return raw_input()
def readarr(n):
    return [map(int,list(readStr())) for i in xrange(n)]
def readnumbertolist():
    a=[int(i) for i in list(raw_input())]
    return a
def strlistTostr(list1):
    return ''.join(list1)
def strTolist(str):
    return str.split()
def strlistTointlist(str):
    return map(int, str)


# Idhar se shuru hai 
mod = 10 ** 9 + 7
for pandora in range(readInt()):
    d,st = readStrs()
    c = st.count("C")
    s = st.count("S")
    v = 1
    d = int(d)
    n = len(st)
    if s==0:
        print "Case #{}: {}".format(pandora+1,0)
        continue
    if c==0 and s>d:
        print "Case #{}: {}".format(pandora+1,"IMPOSSIBLE")
        continue
    sumi = 0
    for i in range(n):
        if st[i]=="C":
            v*=2
        else:
            sumi+=v
    if sumi<=d:
        print "Case #{}: {}".format(pandora+1,0)
        continue
    v = 1
    f = True
    ans = 0
    while True:
        counts = st.count("CS")
        tot = counts
        if counts ==0:
            f = False
            break
        ind = 0
        if counts>0:
            ind = st.rfind("CS")
        arr = list(st)
        cca = st.count("C",ind+1)
        ccb = c-cca
        arr[ind],arr[ind+1] = arr[ind+1],arr[ind]
        sumi -= (pow(2,ccb)-pow(2,ccb-1))
        counts-=1
        st = strlistTostr(arr)
        ans +=1
        if sumi<=d:
            print "Case #{}: {}".format(pandora+1,ans)
            f = True
            break
    if not f:
        print "Case #{}: {}".format(pandora+1,"IMPOSSIBLE")
        continue

