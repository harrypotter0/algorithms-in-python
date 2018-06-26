for kohli in range(input()):
    n = int(input())
    x=[]
    y=[]
    xx=[]
    yy=[]
    ans=[]
    for i in range(n):
        a,b = map(int,raw_input().split(' '))
        x.append(a)
        y.append(b)
    # print(x,y)
    for i in range(n):
        yy.append([y[i],i])
    print(yy)
    yy.sort(key = lambda x:x[0])
    print(yy)
    yy = yy[::-1]
    print(yy)
    for i in yy:
        if(len(ans)==3):
            break
        if(x[i[1]] in xx):
            continue
        else:
            xx.append(x[i[1]])
            ans.append(i[0])
    if(len(ans)==3):
        print(sum(ans))
    else:
        print('0')
