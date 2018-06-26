#include <stdio.h>
#include <stdlib.h>

#define CHECK_POWER_POINT(a, m, n) \
    if (a[m][n] % 11 == 0)         \
    {                              \
        printf("\n(%d,%d)", m, n); \
    }

#define WRITE_CELL(a, m, n)              \
    if ((a[m][n] = counter++) % 11 == 0) \
    {                                    \
        powerPoints++;                   \
    }

int main()
{
    int n, i, k = 0, l = 0, counter = 1, powerPoints = 1;
    int a[100][100];

    scanf("%d", &n);

    int m1 = n;
    int n1 = n;

    while (k < m1 && l < n1)
    {
        for (i = l; i < n1; i++)
            WRITE_CELL(a, k, i);
        k++;

        for (i = k; i < n1; i++)
            WRITE_CELL(a, i, n1 - 1);
        n1--;

        if (k < m1)
        {
            for (i = n1 - 1; i >= l; i--)
                WRITE_CELL(a, m1 - 1, i);
            m1--;
        }

        if (l < n1)
        {
            for (i = m1 - 1; i >= k; i--)
                WRITE_CELL(a, i, l);
            l++;
        }
    }

    for (m1 = 0; m1 < n; m1++)
    {
        for (n1 = 0; n1 < n; n1++)
        {
            printf("%d", a[m1][n1]);
            if (n1 != n - 1)
                printf("\t");
        }

        printf("\n");
    }

    printf("Total Power points : %d\n", powerPoints);
    printf("(0,0)");

    m1 = n1 = n;
    k = 0, l = 0;

    while (k < m1 && l < n1)
    {
        for (i = l; i < n1; i++)
            CHECK_POWER_POINT(a, k, i);
        k++;

        for (i = k; i < n1; i++)
            CHECK_POWER_POINT(a, i, n1 - 1);
        n1--;

        if (k < m1)
        {
            for (i = n1 - 1; i >= l; i--)
                CHECK_POWER_POINT(a, m1 - 1, i);
            m1--;
        }

        if (l < n1)
        {
            for (i = m1 - 1; i >= k; i--)
                CHECK_POWER_POINT(a, i, l);
            l++;
        }
    }

    return 0;
}
