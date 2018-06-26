a,b,c=(int(x) for x in input().split())
print('YES' if c==0 and a==b or c!=0 and (b-a)%c==0 and (b-a)//c>=0 else 'NO')