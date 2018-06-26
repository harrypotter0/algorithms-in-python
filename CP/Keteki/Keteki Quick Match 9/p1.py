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
    arr =[]
    for alphabet in str:
        if alphabet in vowel:
            count = count + 1
            arr.append(alphabet)
    n = len(arr)
    return arr[n-1]
def leapyear(year):
    return calendar.isleap(year)
def distinctstr(s):
    t =''.join(set(s))
    return t

MOD = 10 ** 9 + 7

for __ in range(readInt()):
    n = readInt()
    s = readStrs()
    n = len(s)
    ar = []
    for i in range(n):
        t = vowel_count(s[i])
        ar.append(t)
    arrr = distinctstr(ar)
    length = len(ar)-len(arrr)
    print length*2


'''
Input:
2
1
you
4
you are dell

Output:
0
2

'''
