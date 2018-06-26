# Akash Kandpal
# My Domain => http://harrypotter.tech/
# from fractions import gcd
import math
from itertools import permutations
from itertools import combinations

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
    return list(combinations(S, m))
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
import string
def ascii(n):
    return string.ascii_lowercase[:n]
import operator as op
def ncr(n, r):
    r = min(r, n-r)
    numer = reduce(op.mul, xrange(n, n-r, -1), 1)
    denom = reduce(op.mul, xrange(1, r+1), 1)
    return numer/denom


def reverse(s):
    return s[::-1]

def isPalindrome(s):
    # Calling reverse function
    rev = reverse(s)

    # Checking if both string are equal or not
    if (s == rev):
        return True
    return False
MOD = 10 ** 9 + 7
from itertools import product
from string import ascii_lowercase
n,k = readInts()
keywords = [''.join(i) for i in product(ascii_lowercase[:k], repeat = n)]
print keywords
nt = len(keywords)

# keyw ="akash"
# print keyw[:-1]
# print keyw[-1:]
# print keyw[:-1]
# print keyw[:4]

c = 0
for i in range(nt):
    for j in range(nt):
        print keywords[i]+keywords[i][:-j],keywords[j][-j:]+keywords[i]
        if(keywords[i]+keywords[i][:-j]==keywords[i][-j:]+keywords[i]):
            print keywords[i],keywords[j]
            c+=1
print c

'''
A+C=C+B.
2 2
3 4

'''
