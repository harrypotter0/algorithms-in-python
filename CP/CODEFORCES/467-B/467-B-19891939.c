#include<stdio.h>
int main()
{
int n,m,k,i,d,c=0,f;
scanf("%d%d%d",&n,&m,&k);
int a[m+1];
for(i=0;i<m+1;i++)
scanf("%d",&a[i]);
for(i=0;i<m;i++)
{
f=a[m]^a[i];
d=0;
while(f!=0)
{
d=d+f%2;
f=f/2;
}
if(d<=k)
c++;
}
printf("%d",c);
}