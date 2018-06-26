#include<stdio.h>
int main()
{
int n,i,j,c;
scanf("%d",&n);
int a[n];
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<n;i++)
{
c=1;
for(j=0;j<n;j++)
{
if(a[j]>a[i])
c++;
}
printf("%d ",c);
}
}