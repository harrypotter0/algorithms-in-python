#include<stdio.h>
#include<conio.h>
int main ()
{
    int a,b,c,d,e;
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    if((a+b+c+d+e)%5==0 && (a+b+c+d+e)!=0)
    {
        printf("%d",(a+b+c+d+e)/5);
    }
    else
    printf("-1");
    return 0 ;
}