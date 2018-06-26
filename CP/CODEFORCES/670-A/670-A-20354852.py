n=int(input())
r=n%7
d=n//7
print(2*d+max(0,r-5),2*d+min(r,2))