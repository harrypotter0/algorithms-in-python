# Utility function to read a list of numbers from stdin
def readInts():
    return map(int, raw_input().strip().split())

primeMap = {}
countPrimesMap = {}

# Function for checking whether a number is a prime
def isPrime(n):
    if n in primeMap:
        return primeMap[n]

    if n < 2:
        primeMap[n] = False
        return False

    if n == 2 or n == 3:
        primeMap[n] = True
        return True

    if n % 2 == 0 or n % 3 == 0:
        primeMap[n] = False
        return False

    i, w = 5, 2

    while i ** 2 <= n:
        if n % i == 0:
            primeMap[n] = False
            return False

        i += w
        w = 6 - w

    primeMap[n] = True
    return True

# Function for checking primes between 1 and n (inclusive)
def countPrimes(n):
    if n in countPrimesMap:
        return countPrimesMap[n]

    if n < 2:
        countPrimesMap[n] = 0
        return 0

    count = 1

    i = 3
    while i <= n:
        if isPrime(i):
            count += 1

        i += 2

    countPrimesMap[n] = count
    return count

def solveTestCase():
    [l, r] = readInts()

    count = 0
    for i in range(l, r + 1):
        if isPrime(countPrimes(i)):
            count += 1

    print count

for i in range(readInts()[0]):
    solveTestCase()
