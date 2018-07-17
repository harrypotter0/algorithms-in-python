n = int(input())
c = 0
for i in range(1,n/2+1):
    if((n-i)%i==0):
        c+=1
        # print(n-i,i,"love")
print(c)
