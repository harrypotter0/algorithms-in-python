#include<stdio.h>
int a[1000001];
int main()
{
long long int n,i,s=0,j=2; 
scanf("%I64d",&n);
int b[n];
for(i=0;i<n;i++)
scanf("%d",&b[i]);
for(i=0;i<n;i++)
a[b[i]]++;
for(i=0;i<1000001;i++)
{
while(a[i]>0)
{
s=s+j*i;
j++;
a[i]--;
if(j==n+2) 
s=s-i;
}
}
printf("%I64d\n",s);
}