#include<stdio.h>
int main ()
{
    int n;
    scanf("%d",&n);
    if((n%2==0)&&(n!=2))
    {
        printf("YES");
    }
    else printf("NO");
    return 0 ;
}