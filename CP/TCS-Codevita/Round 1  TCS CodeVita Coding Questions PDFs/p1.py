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

MOD = 10 ** 9 + 7
def dec2hex(num):
    if num == 0:
        return 0
    ans = ""
    while num > 0:
        ans = str(num%6) + ans
        num /= 6
    return int(ans)

def hex2dec(num):
    if num == 0:
        return 0
    num = str(num)
    ans = int(num[0])
    for i in num[1:]:
        ans *= 6
        ans += int(i)
    return ans

# for __ in range(readInt()):
n = readInt()
arr =readInts()
print arr
a = []
for i in range(n):
    a.append(sum_digits(dec2hex(arr[i])))
print a
c =0
for i in range(n):
    for j in range(i,n):
        if a[i]>a[j]:
            print a[i],a[j]
            c+=1
print c
'''

5
55, 53, 88, 27, 33

2

8
120,21,47,64,72,35,18,98
11

'''
