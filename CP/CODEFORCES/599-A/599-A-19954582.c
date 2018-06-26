#include<stdio.h>
int main()
{
int a,b,c,d;
scanf("%d%d%d",&a,&b,&c);
d=a+b+c;
if(d>2*(a+b))
d=2*(a+b);
if(d>2*(a+c))
d=2*(a+c);
if(d>2*(b+c))
d=2*(b+c);
printf("%d",d);
}