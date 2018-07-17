import math
def readInts():
    return list(map(int, raw_input().split()))
def readInt():
    return int(input())
def readIntsindex0():
    return list(map(lambda x: int(x) - 1, input().split()))
def readStr():
    return raw_input()

for __ in range(readInt()):
    n = readInt()
    count =0
    for i in range(n):
        a = readStr()
        b = readStr()
        count1=0
        count2=0
        for j in range(len(a)):
            if(a[j]=='a' or a[j]=='e' or a[j]=='i' or a[j]=='o' or a[j]=='u'):
                count1+=1
        for j in range(len(b)):
            if(b[j]=='a' or b[j]=='e' or b[j]=='i' or b[j]=='o' or b[j]=='u'):
                count2+=1
        # print(count1,count2)
        if(count1==count2):
            count+=1
    if(count>=n/2):
        print("jane")
    else:
        print("secretbff")





'''
Input:
2
3
haha
okay
lmao
nai
bata
naibataungi
3
siesgsta
haha
lmao
naire
bata
batadiya

Output:
jane
secretbff
'''
