# Akash Kandpal
# My Domain => http://harrypotter.tech/
# from fractions import gcd
import math
# from itertools import permutations
# import statistics
import calendar
def readInts():
    return list(map(int, raw_input().strip().split()))
def readInt():
    return int(raw_input())
def readStrs():
    return raw_input().split()
def readStr():
    return raw_input()
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
def roam(a,f,i,j,v):
  f[i][j]=True

  if i+1<len(a) and v==a[i+1][j] and not f[i+1][j]:
    roam(a,f,i+1,j,v)

  if j+1<len(a[0]) and v==a[i][j+1] and not f[i][j+1]:
    roam(a,f,i,j+1,v)

  if i>0 and v==a[i-1][j] and not f[i-1][j]:
    roam(a,f,i-1,j,v)

  if j>0 and v==a[i][j-1] and not f[i][j-1]:
    roam(a,f,i,j-1,v)

MOD = 10 ** 9 + 7

# for __ in range(readInt()):
#     n,k = readInts()



for tc in xrange(int(raw_input().strip())):
  r,c= map(int,raw_input().split())
  a=[]
  f=[[False for i in xrange(c)]for j in xrange(r)]
  for i in xrange(r):
    a.append(map(int,raw_input().split()))
  ans = 0
  for i in xrange(r):
    for j in xrange(c):
      if f[i][j]:
        continue
      ans += 1
      roam(a,f,i,j,a[i][j])
    # print f
  print ans

'''
Input:
1
4 6
1 1 1 1 1 1
1 1 1 1 0 0
1 1 1 1 0 0
0 0 0 1 1 1
2 2
0 0
2 1

Output:
3
3
'''
