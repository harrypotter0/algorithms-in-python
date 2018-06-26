#include<stdio.h>
int main()
{
int n,t,i,max=-1000000000,a,b,f;
scanf("%d%d",&n,&t);
for(i=1;i<=n;i++)
{
scanf("%d%d",&a,&b);
if(b<=t)
f=a;
else
f=a-(b-t);
if(f>max)
max=f;
}
printf("%d",max);
}