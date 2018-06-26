#include<stdio.h>
#include<conio.h>
int main ()
{
    int s=0,m,n;
    scanf("%d%d",&n,&m);
    if(n>m)
    {
    s=n-m;
    printf("%d ",m);
    }
    else
    {
    s=m-n;
    printf("%d ",n);
    }
    printf("%d ",s/2);
    return 0;
}