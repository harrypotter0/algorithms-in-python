def readInts():
    return map(int, raw_input().split())
def readInt():
    return int(input())

for __ in range(readInt()):
    arr = readInts()
    c = 0
    for i in arr:
        if i==1:
            c+=1
    if(c==0):
        print("Beginner")
    elif(c==1):
        print("Junior Developer")
    elif(c==2):
        print("Middle Developer")
    elif(c==3):
        print("Senior Developer")
    elif(c==4):
        print("Hacker")
    else:
        print("Jeff Dean")


'''

7
0 0 0 0 0
0 1 0 1 0
0 0 1 0 0
1 1 1 1 1
0 1 1 1 0
0 1 1 1 1
1 1 1 1 0

'''
