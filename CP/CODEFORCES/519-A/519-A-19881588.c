#include<stdio.h>
int main()
{
int a=0,b=0,i,j,d[18]={0,3,0,0,0,0,0,0,0,0,0,0,0,3,0,1,9,5};
char s[9];
for(i=1;i<=8;i++)
{
scanf("%s",&s);
for(j=0;j<8;j++)
{
if(s[j]=='.'||s[j]=='k'||s[j]=='K')
continue;
else
{
if(s[j]>='B'&&s[j]<='R')
a=a+d[(int)(s[j])-65];
else
b=b+d[(int)(s[j])-65-32];
}
}
}
if(a>b)
printf("White");
else if(b>a)
printf("Black");
else
printf("Draw");
}