#include<stdio.h>
int main ()
{
    int a,b,c,d,e,count=0,i;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    scanf("%d",&d);
    scanf("%d",&e);
    for(i=1;i<=e;i++)
    {
        if((i%a==0)||(i%b==0)||(i%c==0)||(i%d==0))
        count++;
    }
    printf("%d",count);
    return 0;
}