# Akash Kandpal
# My Domain => http://harrypotter.tech/
# from fractions import gcd
import math
# from itertools import permutations
# import statistics
import calendar
def readInts():
    return list(map(int, raw_input().strip().split(',')))
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
def distinctstr(s):
    t =''.join(set(s))
    return t

MOD = 10 ** 9 + 7

# for __ in range(readInt()):
arr = readInts()
arr = sorted(arr)
a,b,c=[],[],[]
for i in range(len(arr)):
    if(arr[i]<=2):
        a.append(arr[i])
    if(arr[i]<=5):
        b.append(arr[i])
    c.append(arr[i])
# print a,b,c
# print c
a = rsorted(a)
b = rsorted(b)
c = rsorted(c)
s =""
a = numlistTostr(a)
b = numlistTostr(b)
c = numlistTostr(c)
if(len(a)==0 or len(b)==0 or len(c)==0):
    print "Impossible"
else:
    s += a[0]+c[0]+":"+b[0]+c[1]+":"+b[1]+c[2]
    print s
'''

Input:
0,0,1,1,3,5,6,7,7
Output:
17:57:36

Input:
3,3,3,3,3,3,3,3,3
Output:
Impossible

'''
