def readInts():
    return list(map(int, raw_input().split()))
def readInt():
    return int(input())
def readIntsindex0():
    return list(map(lambda x: int(x) - 1, input().split()))

a = []

def SieveOfEratosthenes(n):
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
            # print p,
            a.append(p)


t=input()
SieveOfEratosthenes(1000001)
for __ in range(t):
    l,r = map(int, raw_input().split())
    count =0
    for i in a:
        if(i>=l and i<=r):
            count+=1
    ans = (float(count)/(r-l+1))
    print("{0:.6f}".format(ans))
    # print(count)
