#include<stdio.h>
int main()
{
int n,a,b,s;
scanf("%d%d%d",&n,&a,&b);
s=(a+b)%n;
if(s<=0) 
s=s+n;
printf("%d",s);
}