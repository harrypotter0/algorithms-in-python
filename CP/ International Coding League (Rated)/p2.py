 # International Coding League (Rated)
from fractions import gcd
import math
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
def numTobin(A):
    s = str(bin(A))[2:]
    s = '0'*(31-len(s)) + s
    return s
def precise(num):
    return "{0:.10f}".format(num)
def rsorted(a):
    return sorted(a,reverse=True)

for __ in range(readInt()):
    n,k = readInts()
    string = readStr()
    con = 0
    col =n
    summ = 0
    for i in string:
        if(ord(i)-96>2*k):
            con+=1
            col-=1
            summ+=ord(i)-96
    # print(summ)
    lolo = k*(col-con)+summ
    p = gcd(abs(lolo),k)
    lolo/=p
    k/=p
    print lolo,k

'''
Sample Input

2
10 6
abcdefghij
10 1
qwertyuiop

Sample Output

10 1
159 1


'''
