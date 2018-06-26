#include<stdio.h>
int main()
{
int a[8],i;
for(i=0;i<8;i++)
scanf("%d",&a[i]);
int b=a[1]*a[2]/a[6];
int c=a[3]*a[4];
int d=a[5]/a[7];
printf("%d",(b<c?b<d?b:d:c<d?c:d)/a[0]);
return 0;
}