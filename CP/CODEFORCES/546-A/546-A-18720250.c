#include<stdio.h>
#include<math.h>
int main ()
{
    int k,n,w,i;
    scanf("%d%d%d",&k,&n,&w);
    for(i=1;i<=w;i++)
    {
        n=n-i*k;
    }
    if(n>0)
    {
        printf("%d",0);
    }
    else
    {
    printf("%d",abs(n));
    }
    return 0;
}