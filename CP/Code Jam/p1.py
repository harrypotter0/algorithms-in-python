# /*
#  *
#  ********************************************************************************************
#  * AUTHOR : AKASH KANDPAL                                                                   *
#  * Language : Python2                                                                       *
#  * Motto : The master has failed more times than the beginner has even tried.               *
#  * IDE used: Atom                                                                           *
#  * My Domain : http://harrypotter.tech/                                                     *
#  ********************************************************************************************
#  *
#  */
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
def numlistTostr(list1):
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
def findpermute(word):
    perms = [''.join(p) for p in permutations(word)]
    return set(perms)
def findsubsets(S,m):
    return set(itertools.combinations(S, m))
def sort1(yy,index):
    return yy.sort(key = lambda x:x[index])
def reversepair(yy):
    return yy[::-1]
def checkint(x):
    return (x).is_integer()
def sum_digits(n):
    s = 0
    while n:
        s += n % 10
        n //= 10
    return s
def vowel_count(str):
    count = 0
    vowel = set("aeiouAEIOU")
    for alphabet in str:
        if alphabet in vowel:
            count = count + 1
    return count
def leapyear(year):
    return calendar.isleap(year)
def primes_sieve(limit):
    limitn = limit+1
    not_prime = set()
    primes = []

    for i in range(2, limitn):
        if i in not_prime:
            continue

        for f in range(i*2, limitn, i):
            not_prime.add(f)

        primes.append(i)

    return primes
def distinctstr(s):
    t =''.join(set(s))
    return t
def countdict(s):
    d ={}
    for i in range(len(s)):
        if s[i] not in d.keys():
            d[s[i]]=1
        else:
            d[s[i]]+=1
    return d
import operator as op
def nck(n, k):
    k = min(n-k,k)
    result = 1
    for i in range(1, k+1):
        result = result* (n-i+1) / i
    return result
def matrixcheck(x,y):
    faadu = []
    directions = zip((0,0,1,-1),(1,-1,0,0))
    for dx,dy in directions:
        if R>x+dx>=0<=y+dy<C and A[x+dx][y+dy]==0:
            faadu.append((x+dx,y+dy))
    return faadu
def stringcount(s):
    return [s.count(i) for i in "abcdefghijklmnopqrstuvwxyz"]
def bubbleSort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1] :
                arr[j], arr[j+1] = arr[j+1], arr[j]
def isSubsetSum(st, n, sm) :
    # arr, n, k
    subset=[[True] * (sm+1)] * (n+1)
    for i in range(0, n+1) :
        subset[i][0] = True
    for i in range(1, sm + 1) :
        subset[0][i] = False
    for i in range(1, n+1) :
        for j in range(1, sm+1) :
            if(j < st[i-1]) :
                subset[i][j] = subset[i-1][j]
            if (j >= st[i-1]) :
                subset[i][j] = subset[i-1][j] or subset[i - 1][j-st[i-1]]
    return subset[n][sm];
def decimal_to_octal(dec):
    decimal = int(dec)
    return oct(decimal)
def decimal_to_binary(dec):
    decimal = int(dec)
    return bin(decimal)
def decimal_to_hexadecimal(dec):
    decimal = int(dec)
    return hex(decimal)
def dictlist(keys,values):
    {d.setdefault(key,[]).append(value) for key, value in zip(keys,values)}
    return d
def mullistbyconst(my_list,r):
    my_new_list = []
    for i in my_list:
        my_new_list.append(i * r)
    return my_new_list

mod = 10 ** 9 + 7
# for i,j in product(xrange(R),xrange(C)):
# print "Case #{}: {}".format(i+1,ans)
for pandora in range(readInt()):
    d,st = readStrs()
    c = st.count("C")
    s = st.count("S")
    v = 1
    d = int(d)
    # print d,"d "
    # arr = strTolist(st)
    n = len(st)
    # print "Case #{}:".format(pandora+1)
    if s==0:
        print "Case #{}: {}".format(pandora+1,0)
        # print "lodu1"
        continue
    if c==0 and s>d:
        print "Case #{}: {}".format(pandora+1,"IMPOSSIBLE")
        # print "lodu2"
        continue
    sumi = 0
    for i in range(n):
        if st[i]=="C":
            v*=2
        else:
            sumi+=v
    # print sumi,"sum"
    if sumi<=d:
        print "Case #{}: {}".format(pandora+1,0)
        # print "lodu3"
        continue
    v = 1
    f = True
    # loda=1
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
        # print ind
        # print arr
        cca = st.count("C",ind+1)
        ccb = c-cca
        # print st
        # print ccb,"ccb",cca,"cca",sumi,"sum"
        arr[ind],arr[ind+1] = arr[ind+1],arr[ind]
        sumi -= (pow(2,ccb)-pow(2,ccb-1))
        # print sumi,"sumi",(pow(2,ccb)-pow(2,ccb-1)),"reduction"
        counts-=1
        # print sumi,"sum"
        st = strlistTostr(arr)
        # print st
        ans +=1
        if sumi<=d:
            print "Case #{}: {}".format(pandora+1,ans)
            # print "lodu4"
            f = True
            break
    if not f:
        print "Case #{}: {}".format(pandora+1,"IMPOSSIBLE")
        # print "lodu5"
        continue

'''
7
1 CS
2 CS
1 SS
6 SCCSSC
2 CC
3 CSCSS
12 CS

Case #1: 1
Case #2: 0
Case #3: IMPOSSIBLE
Case #4: 2
Case #5: 0
Case #6: 5

'''
