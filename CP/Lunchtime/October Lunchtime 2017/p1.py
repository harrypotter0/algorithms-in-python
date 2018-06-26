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
def readIntsindex0():
    return list(map(lambda x: int(x) - 1, input().split()))
def readStrs():
    return raw_input().split()
def readStr():
    return raw_input()
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
        n /= 10
    return s
def len_digits(n):
    s = 0
    while n:
        s +=1
        n /= 10
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
MOD = 10 ** 9 + 7

for __ in range(readInt()):
    a,b = readInts()
    arr1 = []
    arr2 = []
    while a:
        arr1 = [a % 10] +arr1
        a /= 10
    # print arr1
    while b:
        arr2 = [b % 10] +arr2
        b /= 10
    # print arr2
    la,lb = len(arr1),len(arr2)
    if(la>lb):
        arr2= [0]*(la-lb)+arr2
    else:
        arr1= [0]*(lb-la)+arr1
    # print arr1,arr2
    c = []
    for i in range(max(la,lb)):
        c.append((arr1[i]+arr2[i])%10)
    # print c
    c = numlistTostr(c)
    if(int(c)==0):
        print "0"
    else:
        print c.lstrip("0")

'''

Input:
3
12 9
25 25
23 0
Output:
11
40

'''
