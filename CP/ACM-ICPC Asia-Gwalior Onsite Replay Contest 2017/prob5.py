for iii in range(int(input())):
    a,b,c,d,e,f,l,r=(map(int,raw_input().strip().split(' ')))
    temp=max(l,r)
    tp=min(l,r)
    l=temp
    r=tp
    if(b>a):
         if(e>d):
              if(max(b,e)<=l and max(a,d)<=r):
                   C=[0,0]
                   A=[0,b]
                   B=[a,0]
                   F=[r,l]
                   E=[r-d,l]
                   D=[r,l-e]
                   arr=[A,B,C,D,E,F]
                   for i in range(6):
                        p=arr[i]
                        print p[0],p[1]
              else:
                   print(-1)
         else:
              if(max(b,d)<=l and max(a,e)<=r):
                   C=[0,0]
                   A=[0,b]
                   B=[a,0]
                   D=[r-e,l]
                   E=[r,l-d]
                   F=[r,l]
                   arr=[A,B,C,D,E,F]
                   for i in range(6):
                        p=arr[i]
                        print p[0],p[1]

              else:
                   print(-1)
    else:
         if(e>d):
              if(max(a,e)<=l and max(b,d)<=r):
                   C=[0,0]
                   A=[b,0]
                   B=[0,a]
                   F=[r,l]
                   E=[r-d,l]
                   D=[r,l-e]
                   arr=[A,B,C,D,E,F]
                   for i in range(6):
                        p=arr[i]
                        print p[0],p[1]
              else:
                   print(-1)
         else:
              if(max(a,d)<=l and max(b,e)<=r):
                   C=[0,0]
                   A=[b,0]
                   B=[0,a]
                   D=[r-e,l]
                   E=[r,l-d]
                   F=[r,l]
                   arr=[A,B,C,D,E,F]
                   for i in range(6):
                        p=arr[i]
                        print p[0],p[1]
              else:
                   print(-1)
