for nitish in range(int(raw_input())):
  n=int(raw_input())
  if(n==1):
    print(1)
    continue
  mod=10**9+7

  # x=((n*(n+1)*(2*n+1))//6)%mod
  # y=((n*n+1-2*n)%mod)*(n//2)
  # y=y%mod
  # xx=n//2-1
  # c=(((xx*(xx+1))%mod*(2-2*n))%mod+(xx*(xx+1)*(xx*2+1)*4)//6)%mod
  print(((((n*(n+1))//2)%mod)*n)%mod)


  # print((x+y+c)%(mod))
