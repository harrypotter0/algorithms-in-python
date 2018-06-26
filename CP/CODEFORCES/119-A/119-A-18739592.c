#include<stdio.h>
#include<limits.h>
int gcd(int a,int b)
{
    if(b%a==0)
        return a;
    else
        return gcd(b%a,a);
}
int main()
{
    int a,b,n;
    scanf("%d%d%d",&a,&b,&n);
    start:
    n-=gcd(a,n);
    if(n<0)
    {
        printf("1");
        goto end;
    }
    n-=gcd(b,n);
    if(n<0)
    {
        printf("0");
        goto end;
    }
    goto start;
    end:
    return(0);
}