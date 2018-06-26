k=int(input())
l=int(input())
m=0
while k**m<l:
    m=m+1
if k**m>l:
    print('NO')
else:
    print('YES')
    print(m-1)