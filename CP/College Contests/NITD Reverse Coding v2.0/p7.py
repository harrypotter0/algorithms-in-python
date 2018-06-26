# Akash Kandpal
# My Domain => http://harrypotter.tech/
# from fractions import gcd
import math
# from itertools import permutations
# import statistics
from random import randint
import calendar

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

MOD = 10 ** 9 + 7

# for __ in range(readInt()):
s = readStr()
day = int(s[:2])
month = int(s[2:4])
year = int(s[-4:])
arr =[0,31,69,100,120,151,181,212,243,273,304,334,365]
brr =[0,31,70,101,121,152,182,213,244,274,305,335,366]
sumi =0
year %=400
if(year>100):
    sumi+=(year/100)*5
year %=100

print calendar.isleap(year)
if(calendar.isleap(year)):
    sumi+=(brr[month-1]+day)
else:
    sumi+=(arr[month-1]+day)
print sumi
print sumi%7

'''
input
21091999
output
2

input
24061996
output
1
'''
