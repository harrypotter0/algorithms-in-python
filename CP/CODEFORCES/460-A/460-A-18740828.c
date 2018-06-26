#include<stdio.h>
int main ()
{
    int a,c=0,b,n=0;
    scanf("%d%d",&a,&b);
    n=a;
    c=a;
    while(c>=b)
    {
        n+=c/b;
        c=c%b+c/b;
    }
    printf("%d",n);
    return 0;
}