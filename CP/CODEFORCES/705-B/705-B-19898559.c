#include<stdio.h>
int main()
{
int n,sum=0;
scanf("%d",&n);
while(n--)
{
int t;
scanf("%d",&t);
sum=sum+(t-1);
if(sum%2==0)
printf("2\n");
else
printf("1\n");
}
}