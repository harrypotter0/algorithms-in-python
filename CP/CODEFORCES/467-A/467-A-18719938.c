#include<stdio.h>
int main ()
{
    int count=0,i,n,a,b;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&a,&b);
        if((abs(a-b))>=2)
        count++;
    }
    printf("%d",count);
    return 0;
}