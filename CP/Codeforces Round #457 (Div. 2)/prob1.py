n = int(input())
a = map(str,raw_input().split(' '))

a[0] = int(a[0])
a[1] = int(a[1])

a1 = a[0]//10
a2 = a[0]%10
b1 = a[1]//10
b2 = a[1]%10

if(a1 == 7 or a2 == 7 or b1 == 7 or b2 == 7 ):
    print "0"
else:
    count = 0
    while(not(a1 == 7 or a2 == 7 or b1 == 7 or b2 == 7)):
        a[1]-=n
        count+=1
        #print(count)
        if(a[1]<0):
            a[1]+=60
            a[0]-=1
            if(a[0]<0):
                a[0]+=24
        a1 = a[0]//10
        a2 = a[0]%10
        b1 = a[1]//10
        b2 = a[1]%10
        continue
    #print(count,str(a[0])+str(a[1]))
    print(count)
