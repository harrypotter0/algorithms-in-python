#include<stdio.h>
int main()
{
int n=0,i,s=0,j;
scanf("%d",&n);
int a[n];
for(i=0;i<n;i++){
scanf("%d",&a[i]);
s+=a[i];
}
s=s/(n/2);
for(i=0;i<n;i++)
for(j=0;j<n;j++)
if(i!=j)
if(a[i]+a[j]==s)
{
printf("%d %d\n",i+1,j+1);
a[i]=0;
a[j]=0;
}
return 0;
}