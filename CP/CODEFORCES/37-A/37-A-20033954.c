#include <stdio.h>
#include<math.h>
main()
{int c=0,k,i,t=1,n,a[1001]={0};
scanf("%d",&n);
while(n--)
{scanf("%d",&k);
a[k]++;
if(a[k]==1)c++;
if(a[k]>t)
t=a[k];}        
printf("%d %d\n",t,c);
return 0;}