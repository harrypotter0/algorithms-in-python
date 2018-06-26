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
# Python3 program to print
# given matrix in spiral form
MOD = 10 ** 9 + 7
def spiral(n,arr):
    dx,dy = 1,0            # Starting increments
    x,y = 0,0              # Starting location
    myarray = [[None]* n for j in range(n)]
    t=0
    for i in xrange(n**2):
        myarray[x][y] = arr[t]
        nx,ny = x+dx, y+dy
        if 0<=nx<n and 0<=ny<n and myarray[nx][ny] == None:
            x,y = nx,ny
        else:
            dx,dy = -dy,dx
            x,y = x+dx, y+dy
        t+=1
    return myarray

def printspiral(myarray):
    n = range(len(myarray))
    for y in n:
        for x in n:
            print myarray[x][y],
        print

# for __ in range(readInt()):
n = readInt()
a,b =[],[]
for i in range(n):
    arr = readInts()
    b.extend(arr)
b =sorted(b)
# print b

if(n==1):
    print b[0]
else:
    printspiral(spiral(n,b))

'''
3
2  5  12
22 45 55
1  6  8
1
4
2
3 2
5 7
'''
