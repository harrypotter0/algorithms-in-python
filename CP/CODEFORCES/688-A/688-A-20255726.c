#include<stdio.h>
int main()
{
int n,d,i,j,t=0,m,r=0;
scanf("%d%d",&n,&d);
char ch[n+1];
for(i=1;i<=d;i++)
{
scanf("%s",ch);
m=0;
for(j=0;j<n;j++)
{
if(ch[j]=='0')
{
m++;
break;
}
}
if(m==1)
{
t++;
if(t>r)
r=t;
}
else
t=0;
}
printf("%d",r);
}