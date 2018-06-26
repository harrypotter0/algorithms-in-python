#include <stdio.h>

int gcd(int x, int y)
{
    if (y > x)
        return gcd(y, x);

    return y == 0 ? x : gcd(y, x % y);
}

int main()
{
    int n, m, i, j, flag, count;

    scanf("%d/%d", &n, &m);

    i = gcd(n, m);
    n /= i;
    m /= i;

    i = 1, j = 1, flag = 1;
    count = 0;

    while (1)
    {
        if (gcd(i, j) == 1)
            count++;

        if (i == n && j == m)
            break;

        if (flag == 1)
        {
            if (j == 1)
            {
                i++;
                flag = -1;
            }
            else
            {
                i++;
                j--;
            }
        }
        else
        {
            if (i == 1)
            {
                j++;
                flag = 1;
            }
            else
            {
                i--;
                j++;
            }
        }
    }

    printf("%d\n", count);

    return 0;
}
