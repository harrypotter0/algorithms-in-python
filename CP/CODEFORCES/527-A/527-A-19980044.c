#include<stdio.h>
int main()
{
long long a,b,c=0,t;
scanf("%I64d%I64d",&a,&b);
while(b!=0)
{
c=c+(a/b);
t=b;
b=a%b;
a=t;
}
printf("%I64d",c);
}