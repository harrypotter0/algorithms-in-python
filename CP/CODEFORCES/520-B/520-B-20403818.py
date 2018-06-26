n,m=map(int,input().split());a=0
while n!=m:
    a+=1;m+=1 if m<n or m&1 else-m//2
print(a)