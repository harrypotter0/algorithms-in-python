def readInts():
    return list(map(int, raw_input().split()))
def readInt():
    return int(input())
def readIntsindex0():
    return list(map(lambda x: int(x) - 1, input().split()))

t=input()
for __ in range(t):
    a,b,c = readInts()
    x,y,z = readInts()
    root = pow(c+z,2)
    line = pow(a-x,2) + pow(b-y,2)

    if(root == line):
        print("tangential")
    elif(root>line):
        print("overlapping")
    else:
        print("not overlapping")


'''

Input:
3
10 10 3
10 6 1
8 8 3
8 4 2
7 5 2
4 9 2
Output:
tangential
overlapping
not overlapping

'''
