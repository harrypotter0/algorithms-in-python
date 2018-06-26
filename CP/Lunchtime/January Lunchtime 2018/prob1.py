for kohli in range(input()):
    n = int(input())
    a = list(map(int, raw_input().split()))
    c1=0
    c2=0
    sum=0
    for x in range(10):
        i=0
        j=0
        for i in range(len(a)):
            for j in range(len(a)):
                if(j>len(a)):
                    break
                if(len(a)==1):
                    break
                if(len(a)==2):
                    sum = a[0]+a[1]
                    if(not(sum)&1):
                        # print(sum)
                        # print(a)
                        a.pop(0)
                        a.pop(0)
                        a.append(sum)
                        # print(a)
                else:
                    if(i!=j and i<len(a) and j<len(a)):
                        sum = a[i]+a[j]
                    # print(sum)
                    if(not(sum)&1 and i!=j and i<len(a) and j<len(a)):
                        # print(sum)
                        # print(i,j)
                        # print(a)
                        if(i<j):
                            a.pop(i)
                            # print(a)
                            a.pop((j-1) if (j-1)>=0 else j+len(a)-2)
                            # print(a)
                        else:
                            a.pop(j)
                            # print(a)
                            a.pop((i-1) if (i-1)>=0 else i+len(a)-2)
                            # print(a)
                        a.append(sum)
                        # print(a)
            if(len(a)==1):
                break
            if(i>len(a)):
                break
        if(len(a)==1):
            break
    print(len(a))
    a[:] = []

'''
1
5
2 1 3 1 3
'''
