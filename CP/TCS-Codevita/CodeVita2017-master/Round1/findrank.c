#include <stdio.h>
#include <string.h>

long fact(long n)
{
	return (n <= 1) ? 1 : n * fact(n - 1);
}

// A utility function to count smaller characters on right
// of str[low]
int findSmallerInRight(char* str, int low, int high)
{
	int countRight = 0, i;

	for (i = low + 1; i <= high; i++)
		if (str[i] < str[low])
			countRight++;

	return countRight;
}

// A function to find rank of a string in all permutations
// of characters
long findRank (char* str)
{
	int len = strlen(str);
	long mul = fact(len);
	long rank = 1;
	int countRight;
	int i;

	for (i = 0; i < len; i++)
	{
		mul /= len - i;

		// count number of chars smaller than str[i]
		// fron str[i + 1] to str[len - 1]
		countRight = findSmallerInRight(str, i, len - 1);

		rank += countRight * mul ;
	}

	return rank;
}

int main()
{
    int n, i, j, k;
    char a[11];
    long long r = 1;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        a[10] = '\0';

        for (j = 0; j < 10; j++)
        {
            scanf("%1d", &k);
            a[j] = k + '0';
        }

        r *= findRank(a);
    }

    r %= 23456;

    printf("%ll\n", r);

	return 0;
}
