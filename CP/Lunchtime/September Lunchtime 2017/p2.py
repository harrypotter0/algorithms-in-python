# Akash Kandpal
# My Domain => http://harrypotter.tech/
# Looking for a career in data science and machine learning

# from fractions import gcd
import math
# from itertools import permutations
# import statistics
import itertools
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

possible = []
arr = itertools.permutations(range(6))
arr = list(arr)
for perm in arr:
    flag = True
    for i in range(6):
        if perm[i] is i or perm[perm[i]] is not i:
            flag = False
            break

    if flag : possible.append(perm)

# print possible

T = readInt()
for tc in range(T):
    N = int(raw_input())
    A = [i - 1 for  i in map(int , raw_input().split())]
    # print A
    found = []
    for perm in possible:
        can = True
        for i in range(N - 1):
            # print A[i],A[i+1],perm[A[i]]
            can &= not (A[i] is A[i + 1] or A[i + 1] is perm[A[i]])

        if can:
            found = perm
            break

    if len(found) > 0:
        print ' '.join(map(str , [i + 1 for i in found]))
    else:
        print -1

'''
Input:
4
9
1 3 4 6 1 3 4 6 1
10
1 2 1 3 1 4 1 5 1 6
6
1 2 3 4 5 6
4
1 3 3 1

Output:
2 1 6 5 4 3
-1
4 5 6 1 2 3
-1
'''
