import math
import sys
n=int(input())
mod = 10000000007
ans =1
for i in range(n):
   n,m = map(int,raw_input().split())
   ans1 = pow(2,m)%mod
   ans2 = pow(n+1,m-1)%mod
   ans3 = (n+1-m)%mod
   ans = (ans1*ans2*ans3)%mod
   print(ans)
