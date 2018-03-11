# cook your code here
a = []
n = 10**6+10**5
prime = [True for i in range(n+1)]
p = 2
while (p * p <= n):
    # If prime[p] is not changed, then it is a prime
    if (prime[p] == True):

        # Update all multiples of p
        for i in range(p * 2, n+1, p):
            prime[i] = False
    p += 1
# Print all prime numbers
for p in range(2, n):
    if prime[p]:
        a.append(p+1)
# print(a)

for kohli in range(int(raw_input())):
    n = int(raw_input())
    # print(a)
    print(a[n]*-1)
