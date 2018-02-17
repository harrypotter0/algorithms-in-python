import math
import sys
n=int(input())
mod = pow(10,9)+7
for i in range(n):
   p , m = map(int , raw_input().split())
   ans1 = pow(2*(p+1) , m , mod)%mod
   ans2 = pow((p+1) , mod-2 , mod)%mod
   ans3 = (p+1-m)%mod
   ans = (ans1*ans2*ans3)%mod
   # print(ans1,ans2,ans3)
   print(ans)
