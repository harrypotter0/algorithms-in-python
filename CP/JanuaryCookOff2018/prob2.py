from __future__ import division
from math import ceil
from bisect import bisect_right as b_r
from bisect import bisect_left as b_l
for __ in range(int(input())):
    a = map(int,raw_input().split())
    s = (a[1]+a[2])%10
    lis = [a[1],a[2]]
    c=2
    if(s%2==1):
        lis.append(s)
        c+=1
        s = (s*2)%10
    #print(s)
    rem = (a[0]-c)%4
    loop = (a[0]-c)//4
    #print(rem,loop)
    summ = sum(lis)
    summ += (loop*20)%3
    tt = [4,8,6,2,4,8,6,2]
    st = '4862'
    i = st.find(str(s))
    for j in range(0,rem):
        summ+=tt[i+j]
    summ%=3
    if(a[0]==2):
        if((a[1]+a[2])%3==0):
            print 'YES'
        else:
            print 'NO'
    elif(s==0):
        print 'NO'
    elif(summ%3==0):
        print 'YES'
    else:
        print 'NO'




'''
2
5 3 4
13 8 1

'''
