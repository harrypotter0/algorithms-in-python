n=input()
a=map(int,raw_input().split())
x=1
y=10**6
ans=min(a[n-1]-x,y-a[0])
for i in range(n-1):
    ans=min(ans,max(a[i]-x,y-a[i+1]) )
print ans        
