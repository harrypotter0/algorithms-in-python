import math
def readInts():
    return list(map(int, raw_input().strip().split()))
def readInt():
    return int(raw_input())
def readIntsindex0():
    return list(map(lambda x: int(x) - 1, input().split()))
def readStr():
    return raw_input().split()


for __ in range(readInt()):
    a,b = readStr()
    # a = list(a)
    # print(a)
    # for i in range(len(a)) :
    #     print(a[i])

    a = map(int,str(a))
    mini = min(int(b),len(a))

    # print(mini)
    # print(a)
    i=0
    while i < min(mini,len(a)):
        if(a[i]==9 ):
            mini+=1
        a[i]=9
        # print(mini)
        i+=1
    # print(a)


    str1 = ''.join(str(e) for e in a)
    print(str1)

'''


3
961468737763377902 4
577894577902683672 1
474923610533896544 9


3
923 23
234 12
32 12

3
000000099999999999 10
577894577902683672 1
474923610533896544 9


'''
