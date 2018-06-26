#include<stdio.h>
#include<math.h>
int main()
{
int n,m,t,s=0,i;
scanf("%d%d",&n,&m);
for(i=0;i<n;i++)
{
scanf("%d",&t);
s=s+t;
}
s=abs(s);
printf("%d",(s/m)+(s%m>0));
}