#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x1, y1, x2, y2;
    int x3, y3, x4, y4;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    if(x1 == x2)
    {
        x3 = x4 = x1+abs(y1-y2);
        y3 = y1;
        y4 = y2;
        printf("%d %d %d %d\n", x3, y3, x4, y4);
    }
    else if(y1 == y2)
    {
        y3 = y4 = y1+abs(x1-x2);
        x3 = x1;
        x4 = x2;
        printf("%d %d %d %d\n", x3, y3, x4, y4);
    }
    else if(abs(x1-x2) == abs(y1-y2))
    {
        x3 = x1;
        y3 = y2;
        x4 = x2;
        y4 = y1;
        printf("%d %d %d %d\n", x3, y3, x4, y4);
    }
    else
    {
        puts("-1");
    }
    return 0;
}