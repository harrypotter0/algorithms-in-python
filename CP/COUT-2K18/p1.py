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


for __ in range(readInt()):
    a = readStr()
    n = len(a)
    vowels,cons =0,0
    for i in range(n):
        if(a[i] in 'aeiou'):
            vowels+=1
        elif(a[i] in 'bcdfghjklmnpqrstvwxyz'):
            cons+=1
    print vowels,cons

# a = 'a'
# vowels =''
# cons = ''
# for i in range(26):
#     if(chr(ord(a)+i) in 'aeiou'):
#         vowels += chr(ord(a)+i)
#     else:
#         cons += chr(ord(a)+i)
# print(vowels)
# print(cons)

'''
Input

3
abcde ewa
aioue
Aefdd

Output

2 3
5 0

'''
