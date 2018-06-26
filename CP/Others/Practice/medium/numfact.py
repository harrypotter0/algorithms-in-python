primes = [2,3,5,7]
for i in range(11,1000):
    isPrime = True
    for j in primes:
        if i%j == 0:
            isPrime = False
            break
    if isPrime:
        primes.append(i)
numberOfPrimes = len(primes)


for _ in range(input()):
    n = input()
    a = map(int, raw_input().split())
    d = {}
    for i in a:
        j = 0
        while j<numberOfPrimes and primes[j]<= i:
            while i%primes[j] == 0:
                i/=primes[j]
                if primes[j] in d:
                    d[primes[j]] += 1
                else:
                    d[primes[j]] = 2
            j+=1
            #print(d,i)
        if i!=1:
            if i in d:
                d[i] += 1
            else:
                d[i] = 2    

    answer = 1
    for key in d:
        answer*=d[key]
    print answer
