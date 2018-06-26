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
def numlistTonumber(numList):
    return int(''.join(map(str,numList)))
"ABCDE"
"FGHIJ"

# for __ in range(readInt()):
t = readInt()
arr = readStrs()
n = readInt()

sumi = 0
for i in range(t):
    a = []
    for j in range(6):
        if(arr[i][j] in "FGHIJ" and j<5):
            # print arr[i][j]
            if(arr[i][j+1] in "ABCDE" and (ord(arr[i][j])-65)+(ord(arr[i][j+1])-65)==9):
                quora = (ord(arr[i][j+1])-65)
                a.append(quora)
                # print a
            else:
                a.append(ord(arr[i][j])-65)
                # print a
        elif(arr[i][j] in "FGHIJ"):
            print arr[i][j]
            a.append(ord(arr[i][j])-65)
        else:
            print arr[i][j]
            a.append(ord(arr[i][j])-65)
            # print a
    print a
    ro = numlistTonumber(a)
    sumi +=ro

print sumi,n
if sumi>=n:
    print "GREEDY"
    print sumi-n
else:
    print "INNOCENT"


'''
Input
3
JAABHF JAACJA JAACDA
500
Output
GREEDY
105
000175.  000200 and 000230.

Input
8
JAACJA JAABCH JAABHD JAACAF JAJAJJ JAABEJ JAACJJ JAACDI
1500
Output
INNOCENT

000200, 000127, 000173, 000205, 0000099, 000149, 000299, 000238
'''
