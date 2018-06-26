#include <stdio.h>
int main()
{
    int a, b , c = 0 , h = 0 ;
    scanf("%d %d",&a, &b);
    while(1)
    {
        h += a ;
        c += a ;
        a = c / b ;
        if(c < b) break;
        c %= b ;
    }
    printf("%d\n", h);
    return 0;
}