#include<stdio.h>
int main()
{
int i,a,b,c,d,e;
scanf("%d",&i);
for(a=i+1;a<10000;a++)
{
b=a%10;
c=(a/10)%10;
d=(a/100)%10;
e=(a/1000)%10;
if((b!=c)&&(b!=d)&&(b!=e)&&(c!=d)&&(c!=e)&&(d!=e))
{
printf("%d",a);
break;
}
}
return 0;
}