#include<stdio.h>
int main()
{
int a,b;
char m[6];
scanf("%d%s%s",&a,m,m);
if(m[0]=='w')
b=52+(a==5||a==6);
else
b=12-(a>29)-4*(a>30);
printf("%d",b);
}