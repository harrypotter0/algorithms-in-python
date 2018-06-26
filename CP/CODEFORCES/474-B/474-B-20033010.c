#include<stdio.h>
int main()
{
int j,i,n,sum=0,m,x,a[1000000];
scanf("%d",&n);
j=0;
for(i=0;i<n;i++)
{
scanf("%d",&x);
sum+=x;
for( ;j<sum;j++)
a[j]=i+1;
}
scanf("%d",&m);
for(i=0;i<m;i++)
{
scanf("%d",&x);
printf("%d\n",a[x-1]);
}
return 0;
}