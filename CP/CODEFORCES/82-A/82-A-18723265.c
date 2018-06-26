#include <stdio.h>
int main()
{
    unsigned int n;
    scanf("%u",&n);
    n--;
    while(n>4)
    {
       n-=5;
       n/=2;
    }
    switch(n)
    {
        case 1:puts("Leonard");break;
        case 2:puts("Penny");break;
        case 3:puts("Rajesh");break;
        case 4:puts("Howard");break;
        case 0:puts("Sheldon");break;
    }
    return 0;
}