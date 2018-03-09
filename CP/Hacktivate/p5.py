import math
def readInts():
    return list(map(int, raw_input().strip().split()))
def readInt():
    return int(raw_input())
def readIntsindex0():
    return list(map(lambda x: int(x) - 1, input().split()))
def readStrs():
    return raw_input().split()
def readStr():
    return raw_input()

a = [[1 for i in xrange(n+1)] for n in xrange(102)]

for i in xrange(1, 101):
   	for j in xrange(1, i+1):
   		a[i+1][j] = a[i][j-1] + a[i][j]

p = math.pow(10,9)+9
# print(p)
for _ in xrange(int(raw_input())):
   	n, g = map(int, raw_input().split())
   	s = 0
   	ans = [n for _ in xrange(g+1)]
   	for i in xrange(1, g+1):
   		ans[i] = (pow(n+1, i+1)) - 1
   		for j in range(2, i+2):
   			ans[i] -= ((a[i+1][j]*ans[i+1-j]))
   		ans[i] = (ans[i]/(i+1))
   	print (int((ans[g]-1-pow(n,g)) % p))



'''
Sample Input 0

1
4 2
Sample Output 0

13
Explanation 0
(4-1)2 + (4-2)2 = 32 + 22 = 13.

Sample Input 1

1
4 3
Sample Output 1

35
Explanation 1

(4-1)3 + (4-2)3 = 33 + 23 = 35
'''
