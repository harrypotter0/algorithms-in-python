# /*
#  *
#  ********************************************************************************************
#  * AUTHOR : Akash Kandpal                                                                    *
#  * Language: Python2                                                                          *
#  * Motto : The master has failed more times than the beginner has even tried.               *                                                                *
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

MOD = 10 ** 9 + 7
# for i,j in product(xrange(R),xrange(C)):
# "abcdefghijklmnopqrstuvwxyz"

for __ in range(readInt()):
    s = readStr()
    a = [((ord(i)-97)%5,s.count(i)) for i in "abcdefghijklmnopqrstuvwxyz"]
    # print a
    sumi = 0
    for i in range(26):
        if a[i][1]==0:
            continue
        sumi+=a[i][0]*a[i][1]
    print sumi
# for t in range(int(raw_input())):
#     ans=0
#     s=raw_input()
#     for j in range(len(s)):
#         ans+=((ord(s[j])-97)%5)
#     print ans

'''
Input:
2
aa
bdssaaz

Output:

0
1
'''
