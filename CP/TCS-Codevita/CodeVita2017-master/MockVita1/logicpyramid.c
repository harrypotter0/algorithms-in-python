#include <stdio.h>
#include <stdbool.h>

int next();

int main()
{
    int n, i, row;

    scanf("%d", &n);

    for (row = 0; row < n; row++)
    {
        for (i = 1; i < n - row; i++)
            printf(" ");

        for (i = 0; i <= row; i++)
        {
            printf("%05d", next());

            if (i != row)
                printf(" ");
        }

        if (row != n - 1)
            printf("\n");
    }

    return 0;
}

int next()
{
    static int lastSeries    = 6;
    static int lastSubSeries = 6;

    static bool started = false;

    if (!started)
    {
        started = true;
        return lastSeries;
    }

    lastSubSeries += 16;
    lastSeries += lastSubSeries;

    return lastSeries;
}
