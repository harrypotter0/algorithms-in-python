'''
listB.sort(reverse=True) # listB gets modified
listC = sorted(listB, reverse=True) # listB remains untouched
'''


for _ in range(int(input())):
    n = int(input())
    b = []
    for __ in range(n):
        a = map(int,raw_input().split())
        b.append(sorted(a))
    su = b[n-1][-1]
    k1=su

    for x in range(n-2,-1,-1):
        flag = 0
        for y in range(n-1,-1,-1):
            if(b[x][y]<k1):
                k1=b[x][y]
                su+=k1
                flag = 1
                break
        if(flag == 0):
            break
    if(flag == 0):
        print("-1")
    else :
        print(su)
