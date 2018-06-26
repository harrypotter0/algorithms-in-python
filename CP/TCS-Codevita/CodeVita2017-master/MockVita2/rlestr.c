#include <stdio.h>

int main()
{
    int i, j = 0;
    char ch = '\0';

    while (ch != '\n')
    {
        scanf("%c", &ch);

        if (ch == ' ')
        {
            printf("\n");
            j++;
            continue;
        }

        for (i = 0; i < ((int) ch) - 64; i++)
            printf(j % 2 == 0 ? "0" : "!");

        j++;
    }

    return 0;
}
