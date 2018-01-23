'''input
1
6
1 2 3 4 5 6

'''
from bisect import bisect_left as bl
from itertools import combinations as c
from collections import defaultdict as df
from math import factorial as F
from math import ceil


for _ in range(input()):
	n=input()
	l=[int(x) for x in raw_input().split()]

	fix=[0]*n
	if n==1 :
		print 0
	elif n==2 and len(set(l))==1:
		print -1
	elif n==2:
		print 0



	elif n&1:
		dp=[]
		for i in range(n):
			dp.append([0,0])


		def satis(ind):
			if ind&1==0:
				return l[ind]>l[ind-1] and l[n-ind-1]>l[n-ind]
			else:
				return l[ind]<l[ind-1] and l[n-ind-1]<l[n-ind]

		for ind in range(n/2+1,n):
			if satis(ind):
				dp[ind][0]=dp[ind-1][0]
			else:
				dp[ind][0]=9999999

			l[ind],l[n-ind-1]=l[n-ind-1],l[ind]

			if satis(ind):
				dp[ind][1]=dp[ind-1][0]+1
			else:
				dp[ind][1]=9999999

			l[ind-1],l[n-ind]=l[n-ind],l[ind-1]

			if satis(ind):
				dp[ind][1]=min(dp[ind][1],dp[ind-1][1]+1)
			else:
				dp[ind][1]=min(dp[ind][1],9999999)

			l[ind],l[n-ind-1]=l[n-ind-1],l[ind]

			if satis(ind):
				dp[ind][0]=min(dp[ind-1][1],dp[ind][0])
			else:
				dp[ind][0]=min(dp[ind][0],9999999)

			l[ind-1],l[n-ind]=l[n-ind],l[ind-1]
		a1=min(dp[-1])
		dp=[]
		for i in range(n):
			dp.append([0,0])


		def satis(ind):
			if ind&1:
				return l[ind]>l[ind-1] and l[n-ind-1]>l[n-ind]
			else:
				return l[ind]<l[ind-1] and l[n-ind-1]<l[n-ind]

		for ind in range(n/2+1,n):
			if satis(ind):
				dp[ind][0]=dp[ind-1][0]
			else:
				dp[ind][0]=9999999

			l[ind],l[n-ind-1]=l[n-ind-1],l[ind]

			if satis(ind):
				dp[ind][1]=dp[ind-1][0]+1
			else:
				dp[ind][1]=9999999

			l[ind-1],l[n-ind]=l[n-ind],l[ind-1]

			if satis(ind):
				dp[ind][1]=min(dp[ind][1],dp[ind-1][1]+1)
			else:
				dp[ind][1]=min(dp[ind][1],9999999)

			l[ind],l[n-ind-1]=l[n-ind-1],l[ind]

			if satis(ind):
				dp[ind][0]=min(dp[ind-1][1],dp[ind][0])
			else:
				dp[ind][0]=min(dp[ind][0],9999999)

			l[ind-1],l[n-ind]=l[n-ind],l[ind-1]
		a2=min(dp[-1])
		ans=min(a1,a2)
		if ans>999999:
			print -1
		else:
			print ans




	else:


		def satis(ind):
			if ind&1==0:
				return l[ind]>l[ind-1] and l[n-ind-1]<l[n-ind]
			else:
				return l[ind]<l[ind-1] and l[n-ind-1]>l[n-ind]
		dp=[]



		for i in range(n):

			dp.append([0,1])

		for ind in range(n/2+1,n):
			if satis(ind):
				dp[ind][0]=dp[ind-1][0]
			else:
				dp[ind][0]=9999999

			l[ind],l[n-ind-1]=l[n-ind-1],l[ind]

			if satis(ind):
				dp[ind][1]=dp[ind-1][0]+1
			else:
				dp[ind][1]=9999999

			l[ind-1],l[n-ind]=l[n-ind],l[ind-1]

			if satis(ind):
				dp[ind][1]=min(dp[ind][1],dp[ind-1][1]+1)
			else:
				dp[ind][1]=min(dp[ind][1],9999999)

			l[ind],l[n-ind-1]=l[n-ind-1],l[ind]

			if satis(ind):
				dp[ind][0]=min(dp[ind-1][1],dp[ind][0])
			else:
				dp[ind][0]=min(dp[ind][0],9999999)

			l[ind-1],l[n-ind]=l[n-ind],l[ind-1]
		a1=min(dp[-1])


		#print dp

		def satis(ind):
			if ind&1:
				return l[ind]>l[ind-1] and l[n-ind-1]<l[n-ind]
			else:
				return l[ind]<l[ind-1] and l[n-ind-1]>l[n-ind]

		dp=[]
		for i in range(n):
			dp.append([0,1])

		for ind in range(n/2+1,n):
			if satis(ind):
				dp[ind][0]=dp[ind-1][0]
			else:
				dp[ind][0]=9999999

			l[ind],l[n-ind-1]=l[n-ind-1],l[ind]

			if satis(ind):
				dp[ind][1]=dp[ind-1][0]+1
			else:
				dp[ind][1]=9999999

			l[ind-1],l[n-ind]=l[n-ind],l[ind-1]

			if satis(ind):
				dp[ind][1]=min(dp[ind][1],dp[ind-1][1]+1)
			else:
				dp[ind][1]=min(dp[ind][1],9999999)

			l[ind],l[n-ind-1]=l[n-ind-1],l[ind]

			if satis(ind):
				dp[ind][0]=min(dp[ind-1][1],dp[ind][0])
			else:
				dp[ind][0]=min(dp[ind][0],9999999)

			l[ind-1],l[n-ind]=l[n-ind],l[ind-1]
		a2=min(dp[-1])
		#print dp
		ans=min(a1,a2)
		#print satis(3)
		if ans>999999:
			print -1
		else:
			print ans
