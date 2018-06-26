#include<stdio.h>
int main()
{
int n,t,i,s;
scanf("%d",&n);
for(i=1;i<=n;i++) 
{
scanf("%d",&t);
while(t%2==0)
t=t/2;
while(t%3==0)
t=t/3;
if(i==1)
s=t;
else if(s!=t)
{
printf("No");
return 0;
}
}
printf("Yes");
return 0;
}