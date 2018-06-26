t,s,x=map(int,input().split())
print('YES' if x==t or x>=s+t and (x-t-s)%s<=1 else 'NO')