#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long int ulint;

bool isPrime(ulint);
bool isConsecSumPrime(ulint, ulint*);

ulint* buildPrimesList(ulint n)
{
    ulint i;
    ulint* vals = (ulint*) malloc(sizeof(ulint) * n);

    vals[0] = vals[1] = 2;

    for (i = 3; i < n; i += 2)
        if (isPrime(i))
            vals[vals[0]++] = i;

    return vals;
}

int main()
{
    ulint* primes;
    ulint n;
    int i, c = 0;

    scanf("%ld", &n);
    primes = buildPrimesList(n);

    for (i = 2; i < primes[0]; i++)
        if (isConsecSumPrime(primes[i], primes))
            c++;

    printf("%ld", c);
    free(primes);

    return 0;
}

bool isPrime(ulint n)
{
    ulint i, w;

    if (n == 2) return true;
    if (n == 3) return true;
    if (n % 2 == 0) return false;
    if (n % 3 == 0) return false;

    i = 5, w = 2;

    while (i * i <= n)
    {
        if (n % i == 0)
            return false;

        i += w;
        w = 6 - w;
    }

    return true;
}

bool isConsecSumPrime(ulint prime, ulint* primes)
{
    int n;
    ulint sum = 0;

    for (n = 1; n < primes[0]; n++)
    {
        sum += primes[n];

        if (sum == prime)
            return true;

        if (sum > prime)
            return false;
    }

    return false;
}
