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
import itertools
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
    return raw_input().strip()
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
    perms = list(set(perms))
    return perms
def findsubsets(S,m):
    return list(set(itertools.combinations(S, m)))
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
def gcd(a,b):
    while b > 0:
        a, b = b, a % b
    return a
def lcm(a, b):
    return a * b / gcd(a, b)
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
def coinchange(S, m, n):
    # (arr,length,sum)
    table = [0 for k in range(n+1)]
    table[0] = 1
    for i in range(0,m):
        for j in range(S[i],n+1):
            table[j] += table[j-S[i]]
    return table[n]

mod = 10 ** 9 + 7
# for i,j in product(xrange(R),xrange(C)):
# print "Case #{}: {}".format(i+1,ans)

for __ in range(readInt()):
    n = readInt()
    x = n/2
    if n&1:
        print x-n
    else:
        print x

'''
 Sample Input:

2
5
4

Sample Output:

-3
2



'''
