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

a = readStr()
n = len(a)
c=0
a = list(a)
for i in range(n/2):
    if(a[i]==a[n-i-1]):
        continue
    elif(a[i]<a[n-i-1]):
        c+=1
        a[n-i-1] = a[i]
    else:
        c+=1

        a[i] = a[n-i-1]
print(c)
print(''.join(a))

'''
abc

ewgfdshagsdgbgrfdszvcxgrasdv
'''
